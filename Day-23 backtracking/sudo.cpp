#include <iostream>
using namespace std;

void printGrid(int suduko[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            cout << suduko[row][col] << " ";
        cout << endl;
    }
}

bool issafe(int suduko[9][9], int row, int col, int digit)
{

    for (int i = 0; i <= 8; i++)
    {
        if (suduko[i][col] == digit)
        {
            return false;
        }
    }

    for (int j = 0; j <= 8; j++)
    {
        if (suduko[row][j] == digit)
        {
            return false;
        }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i <= startRow + 2; i++)
    {
        for (int j = startCol; j <= startCol + 2; j++)
        {

            if (suduko[i][j] == digit)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int suduko[9][9], int row, int col)
{
    if (row == 9)
    {
        printGrid(suduko);
        return true;
    }
    int nextrow = row;
    int nextcol = col + 1;
    if (col + 1 == 9)
    {
        nextrow = row + 1;
        nextcol = 0;
    }

    if (suduko[row][col] != 0)
    {
        return sudokuSolver(suduko, nextrow, nextcol);
    }

    for (int digit = 1; digit <= 9; digit++)
    {
        if (issafe(suduko, row, col, digit))
        {
            suduko[row][col] = digit;
            if (sudokuSolver(suduko, nextrow, nextcol))
            {
                return true;
            }
            suduko[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int suduko[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    sudokuSolver(suduko, 0, 0);

    return 0;
}