#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int row;
    vector<vector<string>> solveNQueens(int n) {
        int i = 1;
        int j = 0;
        row = n;
        vector<vector<string>> sol;
        vector<vector<int>> valid_pos(row, vector<int> (row, 1));

        recQueens(sol, valid_pos, {}, 0);

        return sol;
    }

    void recQueens(vector<vector<string>>& sol, vector<vector<int>> valid_pos, vector<string> sub_sol, int level){

        // base case //
        if(level == row){
            sol.push_back(sub_sol);
            return;
        }

        for(int i = 0; i < row; i++){
            if(valid_pos[level][i]){
                // standart backtracking here //
                sub_sol.push_back(queenFormat(i));
                recQueens(sol, posValidator(valid_pos, i, level), sub_sol, level + 1);
                sub_sol.pop_back();
            }
        }
    }

    string queenFormat(int& pos){

        // this function just formats the solution // 
        string format;

        for(int i = 0; i < row; i++) format += ".";

        format[pos] = 'Q';

        return format;
    }

    vector<vector<int>> posValidator(vector<vector<int>> valid_pos, int& pos, int& level){

        // this function eliminates invalid positions on the remaining board based on where we put our queens on the board previously //  
        int diagonal = 1;

        for(int i = level + 1; i < row; i++){
            if(pos + diagonal < row) valid_pos[i][pos + diagonal] = 0;
            valid_pos[i][pos] = 0;
            if(pos - diagonal > -1) valid_pos[i][pos - diagonal] = 0;
            diagonal++;
        }

        return valid_pos;
    }

};