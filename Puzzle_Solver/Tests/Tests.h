#include <cxxtest/TestSuite.h>
#include <sstream>
#include <fstream>
#include <string>
#include "../sudoku.h"

using std::to_string;
using std::string;

class Tests : public CxxTest::TestSuite
{
public:
    void read_puzzle(size_t file_index, bool solution, int* puzzle, size_t n)
    {
        puzzle = new int[n*n];
        string file_name = to_string(n) + "x" + to_string(n) + "_";
        file_name += (solution) ? "solution" : "nosolution";
        file_name += "_" + to_string(file_index) + ".csv";
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
    void test_9x9_1()
    {
        int* puzzle;
        size_t n = 9;
        read_puzzle(1, true, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_9x9_2()
    {
        int* puzzle;
        size_t n = 9;
        read_puzzle(2, true, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_9x9_3()
    {
        int* puzzle;
        size_t n = 9;
        read_puzzle(3, true, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_9x9_4()
    {
        int* puzzle;
        size_t n = 9;
        read_puzzle(4, true, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_9x9_5()
    {
        int* puzzle;
        size_t n = 9;
        read_puzzle(5, true, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }

    void test_16x16_1()
    {
        int* puzzle;
        size_t n = 16;
        read_puzzle(1, true, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_16x16_2()
    {
        int* puzzle;
        size_t n = 16;
        read_puzzle(2, true, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
    void test_16x16_3()
    {
        int* puzzle;
        size_t n = 16;
        read_puzzle(3, false, puzzle, n);
        TS_ASSERT(Sudoku(puzzle, n, 0, 0));
    }
};