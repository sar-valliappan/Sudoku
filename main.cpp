#include <iostream>
#include <array>
#include "Board.h"

void testCompleteValidSolution() {
    std::array<std::array<int, 9>, 9> solvedSudoku = {{
        {{5,3,4,6,7,8,9,1,2}},
        {{6,7,2,1,9,5,3,4,8}},
        {{1,9,8,3,4,2,5,6,7}},
        {{8,5,9,7,6,1,4,2,3}},
        {{4,2,6,8,5,3,7,9,1}},
        {{7,1,3,9,2,4,8,5,6}},
        {{9,6,1,5,3,7,2,8,4}},
        {{2,8,7,4,1,9,6,3,5}},
        {{3,4,5,2,8,6,1,7,9}}
    }};

    Board b(solvedSudoku);
    std::cout << "Test 1 - Complete Valid Solution: ";
    std::cout << (b.isSolved() ? "PASS\n" : "FAIL\n");
}

void testIncompletePuzzle() {
    std::array<std::array<int, 9>, 9> puzzle = {{
        {{5,3,0, 0,7,0, 0,0,0}},
        {{6,0,0, 1,9,5, 0,0,0}},
        {{0,9,8, 0,0,0, 0,6,0}},
        {{8,0,0, 0,6,0, 0,0,3}},
        {{4,0,0, 8,0,3, 0,0,1}},
        {{7,0,0, 0,2,0, 0,0,6}},
        {{0,6,0, 0,0,0, 2,8,0}},
        {{0,0,0, 4,1,9, 0,0,5}},
        {{0,0,0, 0,8,6, 0,7,9}}
    }};

    Board b(puzzle);
    std::cout << "Test 2 - Incomplete Puzzle should not be solved: ";
    std::cout << (!b.isSolved() ? "PASS\n" : "FAIL\n");
}

void testInvalidMove() {
    std::array<std::array<int, 9>, 9> puzzle = {{}};
    Board b(puzzle);

    b.setValue(0, 0, 5);
    std::cout << "Test 3 - Invalid move (duplicate in row): ";
    std::cout << (!b.isValidMove(0, 1, 5) ? "PASS\n" : "FAIL\n");
}

void testSolveValidPuzzle() {
    std::array<std::array<int, 9>, 9> puzzle = {{
        {{7,6,0, 4,0,0, 0,3,8}},
        {{0,0,4, 0,9,5, 0,0,0}},
        {{0,1,0, 8,0,0, 6,0,5}},
        {{4,0,8, 3,1,0, 0,0,9}},
        {{0,2,0, 0,6,0, 5,8,0}},
        {{0,0,1, 7,0,8, 3,0,4}},
        {{1,7,0, 0,4,6, 0,0,0}},
        {{0,8,9, 1,0,7, 0,5,0}},
        {{0,0,0, 0,0,0, 1,7,3}}
    }};

    Board b(puzzle);

    bool success = b.solveBoard(0, 0);

    b.printBoard();

    std::cout << "Test 4 - Solver on valid puzzle: ";
    std::cout << (success && b.isSolved() ? "PASS\n" : "FAIL\n");
}

void testUnsolvablePuzzle() {
    std::array<std::array<int, 9>, 9> badPuzzle = {{
        {{1,1,1, 1,1,1, 1,1,1}},
        {{0,0,0, 0,0,0, 0,0,0}},
        {{0,0,0, 0,0,0, 0,0,0}},
        {{0,0,0, 0,0,0, 0,0,0}},
        {{0,0,0, 0,0,0, 0,0,0}},
        {{0,0,0, 0,0,0, 0,0,0}},
        {{0,0,0, 0,0,0, 0,0,0}},
        {{0,0,0, 0,0,0, 0,0,0}},
        {{0,0,0, 0,0,0, 0,0,0}}
    }};

    Board b(badPuzzle);
    bool success = b.solveBoard(0,0);

    std::cout << "Test 5 - Solver on unsolvable puzzle: ";
    std::cout << (!success ? "PASS\n" : "FAIL\n");
}

int main() {
    testCompleteValidSolution();
    testIncompletePuzzle();
    testInvalidMove();
    testSolveValidPuzzle();
    testUnsolvablePuzzle();
    return 0;
}
