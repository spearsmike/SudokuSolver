#include <stddef.h> //size_t
#include <math.h>   //sqrt
#include "sudoku.h"

#define CELLBEGIN(n, index) (size_t)sqrt(n)*(index/(size_t)sqrt(n))
#define CELLEND(n, index) (size_t)sqrt(n)*(index/(size_t)sqrt(n)+1)

bool valid(int* board, const size_t n, int guess, size_t row, size_t col)
{
    for(int i=0; i<n; i++)
        if(board[i*n+col] == guess)
            return false;

    for(int j=0; j<n; j++)
        if(board[row*n+j] == guess)
            return false;

    for(int i=CELLBEGIN(n, row); i<CELLEND(n, row); i++)
        for(int j=CELLBEGIN(n, col); j<CELLEND(n, col); j++)
            if(board[i*n+j] == guess)
                return false;

    return true;
}

size_t countEmpty(int* board, size_t n)
{
    size_t count = 0;
    for(size_t i=0; i<n; i++)
        for(size_t j=0; j<n; j++)
            if(!board[i*n+j])
                count++;
    return count;
}

bool nextBox(int* board, const size_t n, size_t* row, size_t* col)
{
    if(!countEmpty(board, n)) return false;                       //Done

    #ifdef SMART
    size_t maxClues = 0;
    for(size_t i=0; i<n; i++)
        for(size_t j=0; j<n; j++)
            if(board[i*n+j] == 0)
            {
                size_t count;
                if((count=countClues(board, n, i, j)) > maxClues)
                {
                    maxClues = count;
                    *row = i;
                    *col = j;
                }
            }
    #else
    for(size_t j=*col; j<n; j++)
        if(board[(*row)*n+j] == 0)
        {
            *col = j;
            return true;
        }

        for(size_t i=*row+1; i<n; i++)
            for(size_t j=0; j<n; j++)
                if(board[i*n+j] == 0)
                {
                    *row = i;
                    *col = j;
                    return true;
                }
    #endif

    return true;
}

bool Sudoku(int* board, size_t n, size_t i, size_t j)
{
    if(!nextBox(board, n, &i, &j))
        return true;

    for(int guess=1; guess<=n; guess++)
        if(valid(board, n, guess, i, j))
        {
            board[i*n+j] = guess;
            if(!Sudoku(board, n, i, j))
                board[i*n+j] = 0;                 //Backtrack
            else
                return true;
        }

    return false;                                //Bad guess or unsolvable
}

// int main()
// {
//     #if N == 9
//     int board9x9[][9] = 
//         #include "9x9.txt"
//     const size_t size = sizeof(board9x9)/sizeof(*board9x9);
    
//     if(Sudoku(board9x9, size, 0, 0))
//         for(int i=0; i<size; i++) {
//             for(int j=0; j<size; j++)
//                 printf("%d ", board9x9[i][j]);
//             printf("\n");
//         }
//     else
//         printf("No solution found.\n");
//     #elif N == 16
//     int board16x16[][16] = 
//         #include "16x16.txt"
//     int size = sizeof(board16x16)/sizeof(*board16x16);
//     if(Sudoku(board16x16, size, 0, 0))
//         for(int i=0; i<size; i++) {
//             for(int j=0; j<size; j++)
//                 printf("%d ", board16x16[i][j]);
//             printf("\n");
//         }
//     else
//         printf("No solution found.\n");
//     #endif

//     return 0;
// }