#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<char>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------" << endl;
}

bool isShafe(vector<vector<char>> board, int row, int col)
{
    int n = board.size();
    // horizenttal

    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // vertical
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // left digonal;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    // right digonal;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

bool nQueens(vector<vector<char>> board, int row)
{
    int n = board.size();
    if (row == n)
    {
        print(board);

        return true;
    }

    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (isShafe(board, row, j))
        {
            board[row][j] = 'Q';
            // count += nQueens(board, row + 1);
            if (nQueens(board, row + 1))
                return true;
            board[row][j] = '.';
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board;

    int n = 8;
    for (int i = 0; i < n; i++)
    {
        vector<char> newrow;
        for (int j = 0; j < n; j++)
        {
            newrow.push_back('.');
        }
        board.push_back(newrow);
    }
    nQueens(board, 0);

    // cout << "count = " << count;

    return 0;
}