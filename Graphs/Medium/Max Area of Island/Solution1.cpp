#include<vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int count = 0;
        int max_area = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, area, max_area);
                }
            }
        }

        return max_area;  
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int& area, int& max_area){

        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0){
            // comparing islands and finding biggest one //
            max_area = max(max_area, area);
            return;
        }

        grid[x][y] = 0;

        //standart dfs but as we expand further we keep count of how big island is // 
        area++;
        dfs(grid, x + 1, y, area, max_area);
        dfs(grid, x - 1, y, area, max_area);
        dfs(grid, x, y + 1, area, max_area);
        dfs(grid, x, y - 1, area, max_area);
    }
};