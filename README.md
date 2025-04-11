# Sudoku Generator and Solver in C++

This project is a simple console-based Sudoku puzzle generator and solver written in C++. 

## How It Works

1. **Board Generation**:
   - A 9x9 grid is filled using backtracking to create a valid Sudoku solution.

2. **Puzzle Creation**:
   - A fixed number of cells (currently 40) are emptied to form the actual puzzle.
   - This number can later be adjusted to control difficulty.

3. **Solving**:
   - The puzzle can be solved by the same backtracking algorithm, checking all constraints.

## Example Output

5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6

0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9