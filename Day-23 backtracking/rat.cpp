#include <iostream>
using namespace std;

void printGrid(int suduko[][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            cout << suduko[row][col] << " ";
        cout << endl;
    }
}

bool issafe(int suduko[][9], int row, int col, int n)
{
    if (row < 0 || col < 0 || row >= n || col >= n)
        return false;

    if (suduko[row][col] != 1) // blocks 0 and visited -1
        return false;

    return true;
}

int ways(int suduko[][9], int row, int col, int n)
{
    // destination reached
    if (row == n - 1 && col == n - 1 && suduko[row][col] == 1)
    {
        printGrid(suduko);
        cout << "-----------------\n";
        return 1;
    }

    int count = 0;

    if (issafe(suduko, row, col, n))
    {
        suduko[row][col] = -1; // mark visited

        // move in 4 directions
        count += ways(suduko, row, col + 1, n); // right
        count += ways(suduko, row, col - 1, n); // left
        count += ways(suduko, row - 1, col, n); // up
        count += ways(suduko, row + 1, col, n); // down

        suduko[row][col] = 1; // backtrack
    }

    return count;
}

int main()
{
    int suduko[9][9] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 1, 0, 1, 1, 1}};

    int totalways = ways(suduko, 0, 0, 9);
    cout << "Total paths: " << totalways << endl;

    return 0;
}
