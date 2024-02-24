#include<vector>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {

        // If you did not understood how this algorithm works research Kahn's Algorithm for Topological Sorting //

        vector<int> degree(numCourses, 0);

        map<int, vector<int>> adj;
        vector<int> topological;

        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            degree[pre[i][0]]++;
        }

        queue<int> kahn;
        bool flag = 1;

        for(int i = 0; i < numCourses; i++) if(degree[i] == 0) kahn.push(i);;
        
        while(!kahn.empty()){
            int q_size = kahn.size();

            for(int i = 0; i < q_size; i++){
                int vertex = kahn.front();
                kahn.pop();
                topological.push_back(vertex);

                vector<int> single_pre = adj[vertex];

                for(auto& nums : single_pre){
                    degree[nums]--;
                    if(!degree[nums]) kahn.push(nums);
                }
            }
        }
        if(numCourses != topological.size()) return {};

        return topological;
    }
};