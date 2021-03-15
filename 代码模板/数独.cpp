#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>> &board) {
    vector<pair<int, int>> blanks;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == '.') blanks.push_back({i, j});
      }
    }
    dfs(board, blanks, 0);
  }

 private:
  bool dfs(vector<vector<char>> &board, vector<pair<int, int>> &blanks,
           int idx) {
    if (idx >= blanks.size()) return true;

    int x = blanks[idx].first, y = blanks[idx].second;

    for (int i = 1; i <= 9; ++i) {
      if (!checkValid(board, x, y, i)) continue;
      board[x][y] = '0' + i;
      if (dfs(board, blanks, idx + 1)) return true;
      board[x][y] = '.';
    }
    return false;
  }

  bool checkValid(vector<vector<char>> &board, int x, int y, int val) {
    return checkRow(board, x, y, val) && checkCol(board, x, y, val) &&
           checkSquare(board, x, y, val);
  }

  bool checkRow(vector<vector<char>> &board, int x, int y, int val) {
    for (int col = 0; col < board[0].size(); ++col) {
      if (board[x][col] == '0' + val) return false;
    }
    return true;
  }

  bool checkCol(vector<vector<char>> &board, int x, int y, int val) {
    for (int row = 0; row < board.size(); ++row) {
      if (board[row][y] == '0' + val) return false;
    }
    return true;
  }

  bool checkSquare(vector<vector<char>> &board, int x, int y, int val) {
    x = x / 3 * 3;
    y = y / 3 * 3;
    for (int row = x; row < x + 3; ++row) {
      for (int col = y; col < y + 3; ++col) {
        if (board[row][col] == '0' + val) return false;
      }
    }
    return true;
  }
};

int main() {
  vector<vector<char>> board{{'.', '.', '5', '1', '.', '.', '.', '.', '.'},
                             {'6', '.', '1', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '8', '.', '.', '.', '7', '.'},
                             {'1', '.', '.', '.', '.', '.', '.', '9', '.'},
                             {'.', '2', '3', '.', '.', '6', '4', '.', '.'},
                             {'4', '.', '.', '.', '.', '5', '.', '.', '.'},
                             {'.', '.', '6', '.', '9', '.', '3', '4', '.'},
                             {'3', '7', '8', '.', '.', '.', '1', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '8', '2', '.'}};

  Solution slt;
  slt.solveSudoku(board);
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}