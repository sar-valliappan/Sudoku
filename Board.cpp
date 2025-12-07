#include <array>
#include <iostream>

class Board {
    private:
        std::array<std::array<int, 9>, 9> board;
        std::array<int, 9> rowBitMap;
        std::array<int, 9> colBitMap;
        std::array<int, 9> boxBitMap;
        const int FULL_MASK = (1 << 9) - 1;

    public:
        Board() = default;

        Board(const std::array<std::array<int, 9>, 9>& initial)
            : board(initial) {}

        void printBoard() const {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        bool isFull() const {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == 0) {
                        return false;
                    }
                }
            }
            return true;
        }

        bool isSolutionValid() const {
            for (int i = 0; i < 9; i++) {
                if (rowBitMap[i] != FULL_MASK) return false;
                if (colBitMap[i] != FULL_MASK) return false;
                if (boxBitMap[i] != FULL_MASK) return false;
            }
            return true;
        }

        bool isSolved() const {
            return isSolutionValid() && isFull();
        }

        bool isValidMove(int row, int col, int value) const {
            int bit = 1 << (value - 1);

            if (rowBitMap[row] & bit) return false;

            if (colBitMap[col] & bit) return false;

            int boxIndex = (row / 3) * 3 + (col / 3);
            if (boxBitMap[boxIndex] & bit) return false;

            return true;
        }

        int getValue(int row, int col) const {
            return board[row][col];
        }

        bool setValue(int row, int col, int value) {
            if (!isValidMove(row, col, value)) return false;
            int bit = 1 << (value - 1);
            board[row][col] = value;
            rowBitMap[row] |= bit;
            colBitMap[col] |= bit;
            int boxIndex = (row / 3) * 3 + (col / 3);
            boxBitMap[boxIndex] |= bit;
            return true;
        }

        void print() const {
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
};