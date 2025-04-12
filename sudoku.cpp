#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
//colors
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BOLDWHITE   "\033[1;37m"

const int SIZE = 9;     //board size

enum class Difficulty {
    Easy, Medium, Hard
};

bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    //checking the row
    for (int x = 0; x < SIZE; ++x) {
        if (board[row][x] == num) return false;
    }
    //checking the column
    for (int x = 0; x < SIZE; ++x) {
        if (board[x][col] == num) return false;
    }

    //checking the 3x3 block
    int start_row = row - row % 3, start_col = col - col % 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + start_row][j + start_col] == num) {
                return false;
            }
        }
    }
    return true;
}

//a function that solves Sudoku
bool solve_sudoku(vector<vector<int>>& board) {
    int row, col;
    bool empty = false;

    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }
    if (!empty) return true;

    for (int num = 1; num <= SIZE; ++num) {
        if (isSafe(board, row, col, num)){
            board[row][col] = num;
            if (solve_sudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

//a function that generates Sudoku by removing some cells
void generate_sudoku(vector<vector<int>>& board, Difficulty level) {
    solve_sudoku(board);

    int emptyCells = 0;
    //select level
    switch (level)
    {
    case Difficulty::Easy:
        emptyCells = 20;
        break;
    case Difficulty::Medium:
        emptyCells = 30;
        break;
    case Difficulty::Hard:
        emptyCells = 40;
        break;
    default:
        break;
    }
    while (emptyCells > 0) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (board[row][col] != 0) {
            board[row][col] = 0;
            --emptyCells;
        }
    }
}

//the function for the output of the board
void print_board(const vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row){
        for (int col = 0; col < SIZE; ++col) {
            int val = board[row][col];

            if (val == 0) {
                cout << CYAN << "*" << " " << RESET;
            }
            else {
                cout << WHITE << val << " " << RESET;
            }
            //Dividers for 3x3 blocks
            if ((col + 1) % 3 == 0 && col != SIZE - 1) cout << YELLOW << "| " << RESET;
        }
        cout << endl;
        //Dividers for 3x3 blocks
        if ((row + 1) % 3 == 0 && row != SIZE - 1) {
            cout << YELLOW << "---------------------" << RESET << endl;
        }
    }
}

int main()
{
    srand(time(0));
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

    int choice;
    cout << "Choose difficulty level:\n1 - Easy\n2 - Medium\n3 - Hard\n> ";
    cin >> choice;

    Difficulty level = Difficulty::Medium;
    switch (choice)
    {
    case 1: level = Difficulty::Easy; break;
    case 2: level = Difficulty::Medium; break;
    case 3: level = Difficulty::Hard; break;
    default:
        cout << "Invalid choice. Defaulting to medium\n";
        break;
    }

    generate_sudoku(board, level);
    //solve_sudoku(board);
    print_board(board);
    return 0;
}


