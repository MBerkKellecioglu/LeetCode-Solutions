#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        map<int, vector<int>> all_nodes;
        vector<int> checked_vals(numCourses, 0);

        // mapping prerequisites //
        for(int i = 0; i < prerequisites.size(); i++) all_nodes[prerequisites[i][0]].push_back(prerequisites[i][1]);

        for(auto elements : all_nodes) if(!dfs(all_nodes, elements.first, checked_vals)) return false;
    
        return true;
    }

    bool dfs(map<int, vector<int>>& all_nodes, int key, vector<int>& checked_vals){

        // base cases //
        if(checked_vals[key] == 1) return false;
        if(all_nodes.find(key) == all_nodes.end()) return true;

        // we check the current node //
        checked_vals[key] = 1;

        vector<int> prerequisites = all_nodes[key];

        for(int i = 0; i < prerequisites.size(); i++) if(!dfs(all_nodes, prerequisites[i], checked_vals)) return false;

        // we bactrack so we uncheck our values //
        checked_vals[key] = 0;
        all_nodes[key] = {};
        
        return true;
    }
};