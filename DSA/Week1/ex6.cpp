#include <iostream>
using namespace std;

const int N = 8;
int board[8][8] = {0};

// explain the solution: we can solve the N-Queens problem by using recursion. We start with the first row and at each step, we try to place a queen in each cell of the row. If it is safe to place a queen in the cell, we place the queen in the cell and continue the process with the next row. We continue this process until we reach the last row. If we reach the last row, we return 1. Otherwise, we return 0.

bool isSafe(int row, int col){
    for (int i = 0; i < row; ++i)
        // check whether there is a queen in the same column or diagonals
        if (board[i][col] || (col - (row - i) >= 0 && board[i][col - (row - i)]) || (col + (row - i) < N && board[i][col + (row - i)]))
            return false;
    return true;
}

int solve(int row){
    if (row == N)
        return 1;

    int solutions = 0;
    for (int col = 0; col < N; ++col)
        // if it is safe to place a queen in this cell
        if (isSafe(row, col)){
            board[row][col] = 1;
            solutions += solve(row + 1);
            board[row][col] = 0;
        }
    return solutions;
}

signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cout << solve(0);
}