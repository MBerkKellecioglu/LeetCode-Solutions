#include<vector>
#include <climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges){
        vector<int> checked_vals(edges.size(), 0);
        int sol = INT_MIN;
        vector<int> cycle;

        // if we did not checked the values yet we start dfs traversal //
        for(int i = 0; i < edges.size(); i++) if(!checked_vals[i]) dfs(edges, checked_vals, i, sol, cycle);
        
        // no cycle has been found //
        if(sol == INT_MIN || sol == 0) return -1;
 
        return sol;
    }

    void dfs(vector<int>& edges, vector<int>& checked_vals, int key, int& sol, vector<int>& cycle){

        // Standart dfs traversal but we just keep track of our path //

        if(checked_vals[key]){
            auto it = find(cycle.begin(), cycle.end(), key);
            // finding the start of the cycle //
            int curr = cycle.size() - (it - cycle.begin());
            // compare it to the max //
            sol = max(sol, curr);
            return;
        }

        checked_vals[key] = 1;
        cycle.push_back(key);

        if(edges[key] != -1) dfs(edges, checked_vals, edges[key], sol, cycle);

        cycle.pop_back();
    }
};