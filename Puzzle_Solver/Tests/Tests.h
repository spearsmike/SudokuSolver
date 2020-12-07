#include <cxxtest/TestSuite.h>
//#include <stringstream>
#include <fstream>
#include <iostream>
#include <string>
#include "../sudoku.h"

using std::to_string;
using std::string;

class Tests : public CxxTest::TestSuite
{
public:
    void read_puzzle(size_t file_index, int* puzzle, size_t n)
    {
        puzzle = new int[n*n];
        string file_name = to_string(n) + "x" + to_string(n) + "_" 
                         + to_string(file_index) + ".csv";
        std::ifstream puzzle_file(file_name);
        if(puzzle_file.fail())
            TS_FAIL("Failed to open " + file_name + ".");
        
        string row;
        string num;
        for(int i=0; i<n; i++)
        {
            std::getline(puzzle_file, row);
            std::stringstream ss(row);
            for(int j=0; j<n; j++)
            {
                std::getline(ss, num, ',');
                puzzle[i*n+j] = num=="X" ? 0 : std::stoi(num);
            }
        }
    }

    void test1_9x9()
    {
        int* puzzle;
        size_t n = 9;
        read_puzzle(1, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test2_16x16()
    {
        int* puzzle;
        size_t n = 16;
        read_puzzle(1, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
};