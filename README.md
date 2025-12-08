# Sudoku Solver in C++

This is a **C++ Sudoku solver** that allows you to represent a Sudoku board, check for valid moves, and solve puzzles using a recursive backtracking algorithm. It also includes utilities to validate completed solutions and print the board in a readable format.

---

## Features

- **Board Representation:** Uses a 9x9 `std::array` to represent the Sudoku board.
- **Bitmask Optimization:** Tracks row, column, and 3x3 box constraints with bitmasks for fast validation.
- **Validation:** Checks if moves are valid and if the board is solved.
- **Solver:** Recursively solves any valid Sudoku puzzle using backtracking.
- **Testing:** Includes test cases to validate solver correctness and invalid moves.

---

## Files

- `Board.h` – Header file containing the `Board` class definition.
- `Board.cpp` – Implementation of all member functions for the `Board` class.
- `main.cpp` – Example test cases including:
  - Complete solved board check.
  - Incomplete puzzle check.
  - Invalid move detection.
  - Solver on valid and unsolvable puzzles.

---

## What I Learned (coming from Java)

- How to write classes in C++
- How OOP works in C++
- Bitmasking