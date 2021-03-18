class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<char>(n, '.'));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = mark[player];
        if(check(row, col, mark[player])) return player;
        else return 0;
    }

private:
    vector<vector<char>> board;
    vector<char> mark{'.', 'O', 'X'};
    bool check(int row, int col, char c){
        if(checkRow(row, c)) return true;
        if(checkCol(col, c)) return true;
        if(checkDiag(row, col, c)) return true;

        return false;
    }

    bool checkRow(int row, char c){
        int n = board.size();
        for(int col = 0; col < n; ++col){
            if(board[row][col] != c) return false;
        }
        return true;
    }

    bool checkCol(int col, char c){
        int n = board.size();
        for(int row = 0; row < n; ++row){
            if(board[row][col] != c) return false;
        }
        return true;
    }

    bool checkDiag(int row, int col, char c){
        int n = board.size();
        bool res = false;

        if(row == col){
            int i = 0;
            while(i < n){
                if(board[i][i] != c) break;
                ++i;
            }
            if(i == n) res = true;
        }
        if(row + col == n - 1){
            int i = 0;
            while(i < n){
                if(board[i][n - 1 - i] != c) break;
                ++i;
            }
            if(i == n) res = true;
        }

        return res;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */