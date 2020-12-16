#include <stddef.h> //size_t
#include <math.h>   //sqrt
#include <stdio.h>
#include "solver.h"

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

size_t countClues(int* board, const size_t n, size_t row, size_t col)
{
    size_t count = 0;
    bool visited[n];
    for(size_t i=0; i<n; i++)
        if(!board[i*n+col] | visited[board[i*n+col]-1])
        {
            count++;
            visited[i-1] = true;
        }

    for(int j=0; j<n; j++)
        if(!board[j*n+col] | visited[board[j*n+col]-1])
        {
            count++;
            visited[j-1] = true;
        }

    for(int i=CELLBEGIN(n, row); i<CELLEND(n, row); i++)
        for(int j=CELLBEGIN(n, col); j<CELLEND(n, col); j++)
            if(!board[i*n+col] | visited[board[i*n+col]-1])
            {
                count++;
                visited[i-1] = true;
            }
    return count;
}

bool nextBox(int* board, const size_t n, size_t* row, size_t* col)
{
    if(!countEmpty(board, n)) return false;                       //Done

    #ifdef SMART
    size_t maxClues = 0;
    for(size_t i=0; i<n; i++)
        for(size_t j=0; j<n; j++)
            if(!board[i*n+j])
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
        if(!board[(*row)*n+j])
        {
            *col = j;
            return true;
        }

        for(size_t i=*row+1; i<n; i++)
            for(size_t j=0; j<n; j++)
                if(!board[i*n+j])
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

    // if(board[i+j] > 6) {
    //     printf("\033c");
    // for(int i=0; i<n; i++){
    //         for(int j=0; j<n; j++){
    //             printf("%d ", board[i*(int)n+j]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
        
    // }

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
