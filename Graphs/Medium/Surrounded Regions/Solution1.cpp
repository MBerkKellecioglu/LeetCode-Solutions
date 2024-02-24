#include<vector>

using namespace std;

class Solution {
public:
    int row;
    int col;
    void solve(vector<vector<char>>& board) {
        
        row = board.size();
        col = board[0].size();

        for(int i = 0; i < col; i++){
            if(board[0][i] == 'O') dfs(board, 0, i);
            if(board[row - 1][i] == 'O') dfs(board, row - 1, i);
        }

        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][col - 1] == 'O') dfs(board, i, col - 1);
        }


        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] != 'C') board[i][j] = 'X';
                else board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y){

        if(x < 0 || y < 0 || x >= row || y >= col || board[x][y] == 'X' || board[x][y] == 'C') return;

        // 'C' stands for checked //
        board[x][y] = 'C';

        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};