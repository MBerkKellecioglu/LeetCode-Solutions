#include<vector>
#include<queue>
#include<utility>

using namespace std;

class Solution {
public:
    int row;
    int col;
    int orangesRotting(vector<vector<int>>& grid) {
        
        row = grid.size();
        col = grid[0].size();
        int fresh = 0;
        int total_time = 0;

        queue<pair<int, int>> rotten;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // counting fresh oranges //
                if(grid[i][j] == 1) fresh++;
                // getting rotten ones //
                else if(grid[i][j] == 2) rotten.push({i, j});
            }
        }

        if(fresh == 0) return 0;

        while(!rotten.empty()){
            // BFS traversal //

            int tmp_size = rotten.size();

            for(int i = 0; i < tmp_size; i++){
                int x = rotten.front().first;
                int y = rotten.front().second;

                rotten.pop();

                // current rotten orange refutes fresh ones near itself in 4 directions //
                if(x + 1 < row && grid[x + 1][y] == 1){
                    grid[x + 1][y] = 2; 
                    // since the old fresh orange is now rotten we can add it to rotten vector //
                    rotten.push({x + 1, y});
                    fresh--;
                }
                if(x - 1 > -1 && grid[x - 1][y] == 1){
                    grid[x - 1][y] = 2; 
                    rotten.push({x - 1, y});
                    fresh--;
                }
                if(y + 1 < col && grid[x][y + 1] == 1){
                    grid[x][y + 1] = 2; 
                    rotten.push({x, y + 1});
                    fresh--;
                }
                if(y - 1 > -1 && grid[x][y - 1] == 1){
                    grid[x][y - 1] = 2; 
                    rotten.push({x, y - 1});
                    fresh--;
                }
            }
            // counting total time it took //
            total_time++; 
        }

        if(fresh != 0) return - 1;

        return total_time - 1; 
    }
};