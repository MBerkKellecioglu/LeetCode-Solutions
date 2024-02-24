#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();

        vector<vector<int>> atlantic(row, vector<int>(col, 0));
        vector<vector<int>> pacific(row, vector<int>(col, 0));
        vector<vector<int>> sol;

        for(int i = 0; i < col; i++){
            // here is the tricky part //
            dfs(heights, 0, i, pacific, heights[0][i], row, col);
            // instead of traversing all nodes over and over we just check if current node has any access to oceans //
            dfs(heights, row - 1, i, atlantic, heights[row - 1][i], row, col);
        }

        for(int i = 0; i < row; i++){
            // we do that by starting from nodes near ocean and on our way we check all of our nodes //
            dfs(heights, i, 0, pacific, heights[i][0], row, col);
            // since we start from nodes near ocean if we can reach current node that means it has access to current ocean //
            dfs(heights, i, col - 1, atlantic, heights[i][col - 1], row, col);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // And if current node has access to both oceans it is the answer :) //
                if(atlantic[i][j] && pacific[i][j]) sol.push_back({i, j});
            }
        }

        return sol;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<int>>&ocean, int& val, int& row, int& col){

        // standart dfs traversal //

        if(x < 0 || y < 0 || x >= row || y >= col) return;
        
        if(ocean[x][y]) return;

        if(heights[x][y] < val) return;


        ocean[x][y] = 1;
        int tmp = heights[x][y];

        dfs(heights, x + 1, y, ocean, tmp, row, col);
        dfs(heights, x - 1, y, ocean, tmp, row, col);
        dfs(heights, x, y + 1, ocean, tmp, row, col);
        dfs(heights, x, y - 1, ocean, tmp, row, col);
    }
};