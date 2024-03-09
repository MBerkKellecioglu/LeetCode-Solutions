#include<vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected){

        // I mean standart dfs checking similiar to Number Of Island problem //

        vector<int>checked(isConnected.size(), 0);
        int count = 0;

        for(int i = 0; i < checked.size(); i++){
            if(!checked[i]){
                // if it has not been checked find the neighbors of the current node //
                count++;
                checked[i] = 1;
                dfs(isConnected, checked, i);
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int>&checked, int city){

        // pretty standart dfs //

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[city][i] && !checked[i]){
                checked[i] = 1;
                dfs(isConnected, checked, i);
            }
        }
    }
};