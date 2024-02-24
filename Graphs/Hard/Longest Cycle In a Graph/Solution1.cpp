class Solution {
public:
    int longestCycle(vector<int>& edges){
        vector<int> checked_vals(edges.size(), 0);
        int sol = INT_MIN;
        vector<int> cycle;

        for(int i = 0; i < edges.size(); i++) if(!checked_vals[i]) dfs(edges, checked_vals, i, sol, cycle);
        
        if(sol == INT_MIN || sol == 0) return -1;
 
        return sol;
    }

    void dfs(vector<int>& edges, vector<int>& checked_vals, int key, int& sol, vector<int>& cycle){

        if(checked_vals[key]){
            auto it = find(cycle.begin(), cycle.end(), key);
            int curr = cycle.size() - (it - cycle.begin());
            sol = max(sol, curr);
            return;
        }

        checked_vals[key] = 1;
        cycle.push_back(key);

        if(edges[key] != -1) dfs(edges, checked_vals, edges[key], sol, cycle);

        cycle.pop_back();
    }
};