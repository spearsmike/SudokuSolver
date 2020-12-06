#include <iostream>
#include <vector>
#include <cmath>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using std::vector;
using std::cout;

inline size_t CELLBEGIN(size_t n, size_t index)
{
    return (size_t)sqrt(n)*(index/(size_t)sqrt(n));
}

inline size_t CELLEND(size_t n, size_t index)
{
    return (size_t)sqrt(n)*(index/(size_t)sqrt(n)+1);
}

inline bool valid(int guess, size_t row, size_t col, vector<vector<int>> &board)
{
    size_t n = board.size();
    for(int i=0; i<n; i++)
        if(board[i][col] == guess)
            return false;

    for(int j=0; j<n; j++)
        if(board[row][j] == guess)
            return false;

    for(int i=CELLBEGIN(n, row); i<CELLEND(n, row); i++)
        for(int j=CELLBEGIN(n, col); j<CELLEND(n, col); j++)
            if(board[i][j] == guess)
                return false;

    return true;
}

inline bool nextCell(size_t &row, size_t &col, vector<vector<int>> &board)
{
    size_t n = board.size();
    for(int j=col; j<n; j++)
        if(!board[row][j])
            {
                col = j;
                return true;
            }

    for(int i=row+1; i<n; i++)
        for(int j=0; j<n; j++)
            if(!board[i][j])
            {
                row = i;
                col = j;
                return true;
            }

    return false;                                //Done, solution found
}

bool Sudoku(size_t i, size_t j, vector<vector<int>> &board)
{static size_t iter = 0;iter++;
    size_t size = board.size();
    if(!nextCell(i, j, board))
        return true;

    for(int guess=1; guess<=size; guess++)
        if(valid(guess, i, j, board))
        {
            #ifdef VERBOSE

            for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++)
                    if(!board[i][j])
                        cout << "  ";
                    else
                        cout << board[i][j] << ' ';
                cout << '\n';
            }cout << iter << std::endl;
            sleep(0);cout << "\033c";
            #endif

            board[i][j] = guess;
            if(Sudoku(i, j, board) == false)
                board[i][j] = 0;                 //Backtrack
            else
                return true;
        }
    
    return false;                                //Bad guess or unsolvable
}

int main()
{
    vector<vector<int>> board9x9 {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 7, 0, 0, 0, 0, 0, 4, 1},
                                  {0, 0, 0, 0, 6, 0, 8, 0, 0},
                                  {7, 0, 8, 4, 0, 0, 0, 2, 0},
                                  {0, 2, 0, 0, 9, 0, 0, 0, 0},
                                  {5, 0, 3, 1, 0, 0, 0, 6, 0},
                                  {0, 0, 0, 0, 4, 0, 5, 0, 0},
                                  {0, 5, 0, 0, 0, 0, 0, 7, 9},
                                  {3, 0, 0, 6, 0, 5, 0, 0, 0}};

    vector<vector<int>> board16x16 {{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
                                    {0,  3,  6,  0,  0,  7,  0,  9,  0,  0,  10, 11, 12, 0,  15, 0},
                                    {12, 14, 0,  10, 0,  0,  16, 2,  0,  0,  13, 0,  1,  4,  5,  11},
                                    {15, 0,  11, 8,  12, 14, 0,  0,  0,  0,  0,  5,  7,  0,  6,  0},
                                    {0,  0,  14, 0,  0,  11, 0,  0,  9,  3,  0,  12, 0,  0,  0,  0},
                                    {0,  4,  0,  11, 1,  0,  0,  16, 0,  5,  0,  0,  6,  0,  0,  0},
                                    {0,  16, 0,  0,  7,  0,  0,  14, 13, 11, 8,  4,  0,  10, 9,  15},
                                    {13, 0,  0,  15, 3,  4,  0,  8,  0,  0,  0,  0,  16, 0,  12, 0},
                                    {0,  5,  0,  16, 0,  0,  0,  0,  15, 0,  2,  9,  13, 0,  0,  7},
                                    {9,  2,  12, 0,  13, 1,  8,  15, 6,  0,  0,  3,  0,  0,  10, 0},
                                    {0,  0,  0,  1,  0,  0,  7,  0,  5,  0,  0,  13, 11, 0,  8,  0},
                                    {0,  0,  0,  0,  4,  0,  2,  3,  0,  0,  7,  0,  0,  6,  0,  0},
                                    {0,  8,  0,  6,  2,  0,  0,  0,  0,  0,  5,  16, 10, 9,  0,  12},
                                    {1,  13, 2,  0,  0,  12, 0,  0,  10, 9,  0,  0,  15, 0,  4,  5},
                                    {0,  15, 0,  3,  14, 9,  0,  0,  1,  0,  0,  0,  0,  13, 7,  0},
                                    {0,  12, 0,  9,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0}};

    size_t size = board9x9.size();
    if(Sudoku(0, 0, board9x9))
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++)
                cout << board9x9[i][j] << ' ';
            cout << '\n';
        }
    else
        cout << "No solution found.\n";

    // size = board16x16.size();
    // if(Sudoku(0, 0, board16x16))
    //     for(int i=0; i<size; i++) {
    //         for(int j=0; j<size; j++)
    //             cout << board16x16[i][j] << ' ';
    //         cout << '\n';
    //     }
    // else
    //     cout << "No solution found.\n";

    return 0;
}