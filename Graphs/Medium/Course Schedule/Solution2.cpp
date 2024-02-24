#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        map<int, vector<int>> adj;

        // instead of mapping parent classes as keys i mapped child classes as keys and ran dfs // Same result but slower //
        for(int i = 0; i < prerequisites.size(); i++) adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> checked_vals(numCourses, 0);

        for(auto& elements : adj) if(!dfs(adj, elements.first, checked_vals)) return false;
        
        return true;
    }

    bool dfs(map<int, vector<int>>& adj, int key, vector<int>& checked_vals){

        if(checked_vals[key] == 1) return false;
        if(adj[key].empty()) return true;

        checked_vals[key] = 1;

        vector<int> curr_prereq = adj[key];

        for(auto& elements : curr_prereq) if(!dfs(adj, elements, checked_vals)) return false;
        
        checked_vals[key] = 0;
        adj[key] = {}; 

        return true;
    }
};