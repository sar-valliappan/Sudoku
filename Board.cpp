#include <array>
#include <iostream>

class Board {
    private:
        std::array<std::array<int, 9>, 9> board;

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

        int getValue(int row, int col) const {
            return board[row][col];
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