#include "Board.h"

// Default constructor
Board::Board() {
    board.fill({0});
    initializeBitmaps();
}

// Constructor with initial board
Board::Board(const std::array<std::array<int, 9>, 9>& initial)
    : board(initial) {
    initializeBitmaps();
}

// Initialize bitmaps for rows, columns, and boxes
void Board::initializeBitmaps() {
    rowBitMap.fill(0);
    colBitMap.fill(0);
    boxBitMap.fill(0);

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            int value = board[r][c];
            if (value == 0) continue;
            int bit = 1 << (value - 1);
            rowBitMap[r] |= bit;
            colBitMap[c] |= bit;
            boxBitMap[(r/3)*3 + (c/3)] |= bit;
        }
    }
}

void Board::printBoard() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::isFull() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

bool Board::isSolutionValid() const {
    for (int i = 0; i < 9; i++) {
        if (rowBitMap[i] != FULL_MASK) return false;
        if (colBitMap[i] != FULL_MASK) return false;
        if (boxBitMap[i] != FULL_MASK) return false;
    }
    return true;
}

bool Board::isSolved() const {
    return isSolutionValid() && isFull();
}

bool Board::isValidMove(int row, int col, int value) const {
    int bit = 1 << (value - 1);
    if (rowBitMap[row] & bit) return false;
    if (colBitMap[col] & bit) return false;
    int boxIndex = (row / 3) * 3 + (col / 3);
    if (boxBitMap[boxIndex] & bit) return false;
    return true;
}

int Board::getValue(int row, int col) const {
    return board[row][col];
}

bool Board::setValue(int row, int col, int value) {
    if (!isValidMove(row, col, value)) return false;
    int bit = 1 << (value - 1);
    board[row][col] = value;
    rowBitMap[row] |= bit;
    colBitMap[col] |= bit;
    int boxIndex = (row / 3) * 3 + (col / 3);
    boxBitMap[boxIndex] |= bit;
    return true;
}

void Board::removeValue(int row, int col, int value) {
    int bit = 1 << (value - 1);
    board[row][col] = 0;
    rowBitMap[row] &= ~bit;
    colBitMap[col] &= ~bit;
    boxBitMap[(row / 3) * 3 + (col / 3)] &= ~bit;
}

bool Board::solveBoard(int row, int col) {
    if (row == 9) return true;
    if (col == 9) return solveBoard(row + 1, 0);
    
    if (board[row][col] != 0) return solveBoard(row, col + 1);
    for (int value = 1; value <= 9; value++) {
        if (isValidMove(row, col, value)) {
            setValue(row, col, value);
            if (solveBoard(row, col + 1)) return true;
            removeValue(row, col, value);
        }
    }
    return false;
}

void Board::print() const {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            std::cout << board[r][c] << " ";
            if (c == 2 || c == 5) std::cout << "| ";
        }
        std::cout << "\n";
        if (r == 2 || r == 5)
            std::cout << "------+-------+------\n";
    }
}
