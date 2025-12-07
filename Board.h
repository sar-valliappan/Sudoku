#ifndef BOARD_H
#define BOARD_H

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
    Board();
    Board(const std::array<std::array<int, 9>, 9>& initial);

    void initializeBitmaps();
    void printBoard() const;
    bool isFull() const;
    bool isSolutionValid() const;
    bool isSolved() const;
    bool isValidMove(int row, int col, int value) const;
    int getValue(int row, int col) const;
    bool setValue(int row, int col, int value);
    void removeValue(int row, int col, int value);
    bool solveBoard(int row, int col);
    void print() const;
};

#endif