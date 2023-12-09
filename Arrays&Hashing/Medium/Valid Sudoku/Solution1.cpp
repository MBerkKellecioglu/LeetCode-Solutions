#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
        //first we check every row and collumn //
        for(int row = 0; row < 9; row++){
            //for every row and collumn we initialize our vectors to use them as hash maps //
            vector<int> row_mp(12,0);
            vector<int> col_mp(12,0);

            for(int col = 0 ; col < 9; col++){
                // we find our indexes and check if they are between 1-9 and if they only occur once //
                int row_num = board[row][col] - '0' + 2;
                int col_num = board[col][row] - '0' + 2; // we increment it by two because in empty spaces there is '.' character //
                if(row_num && ++row_mp[row_num] > 1) return false;
                if(col_num && ++col_mp[col_num] > 1) return false;
            }
        }
        
        // same operation for every 3x3 square //
        for(int row = 0; row < 9; row+=3){
            for(int col = 0; col < 9; col+= 3){
                vector<int> row_mp(12,0);
                for(int k = row; k < row + 3; k++){
                    for(int l = col; l < col + 3; l++){
                        int square = board[k][l] - '0' + 2;
                        if(square && ++row_mp[square] > 1) return false;
                    }
                }    
            }  
        }
        return true;
    }
};