#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> board, string word){
        int flag = 1;

        if(board.size() * board[0].size() < word.size()) return false;
        
        for(int i = 0; i < board.size(); i++){
            if(find(board[i].begin(), board[i].end(), word[word.size() - 1]) != board[i].end() ){
                // if we cant find last element in grid we return false //
                flag = 0;
                break;
            }
        }

        if(flag == 1) return false;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    if(RecWord(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }

    bool RecWord(vector<vector<char>>& board, string& word, int count, int x, int y){

        // base case -> find the word//
        if(count == word.size()) return true;

        // base case -> cant find the word//
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || word[count] != board[x][y]) return false;
        
        char tmp = board[x][y];
        // '!' means we checked here //
        board[x][y] = '!';

        // going all 4 directions//
        bool result = RecWord(board, word, count + 1, x + 1, y) || RecWord(board, word, count + 1, x - 1, y) || RecWord(board, word, count + 1, x, y + 1) || RecWord(board, word, count + 1, x, y - 1);

        // backtracked so we change our value to its normal one //
        board[x][y] = tmp;

        return result;
    }
};