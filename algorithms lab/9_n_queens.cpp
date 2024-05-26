#include <bits/stdc++.h>
using namespace std;
#define N 8

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }

    i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    i = row, j = col;
    while (i < N && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j--;
    }

    return true;
}

bool solveNQueen(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQueen(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    int board[N][N] = {0};
    if (!solveNQueen(board, 0))
    {
        cout << "No solution found.";
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << (board[i][j] ? "Q" : " . ");
            }
            cout << endl;
        }
    }
    return 0;
}