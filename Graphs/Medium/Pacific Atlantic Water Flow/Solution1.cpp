#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> sol;

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                bool pac = false, atlan = false;
                dfs(heights, i, j, heights[i][j], pac, atlan);
                if(pac && atlan) sol.push_back({i, j});
            }
        }

        return sol;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, int val, bool& pac, bool& atlan){

        // standart dfs traversal but pretty slow -> See Solution 2 for optimised version //

        if(pac && atlan) return;
        if(x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size() || heights[x][y] == -1 || heights[x][y] > val) return;

        if(x == 0 || y == 0) pac = true;
        if(x == heights.size() - 1 || y == heights[0].size() - 1) atlan = true;

        int tmp = heights[x][y];
        heights[x][y] = -1;
        
        dfs(heights, x + 1, y, tmp, pac, atlan);
        dfs(heights, x - 1, y, tmp, pac, atlan);
        dfs(heights, x, y + 1, tmp, pac, atlan);
        dfs(heights, x, y - 1, tmp, pac, atlan);

        heights[x][y] = tmp;
    }
};