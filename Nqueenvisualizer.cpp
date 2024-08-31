#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) return false;
    }
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col) {
    int n = board.size();
    if (col >= n) return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int n = 8; // Size of the board (8 for 8 Queens)
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0)) {
        printBoard(board);
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
