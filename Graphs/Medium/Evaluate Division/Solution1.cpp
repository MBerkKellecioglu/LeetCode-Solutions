#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        vector<double> sol;

        // this is our undirected graph //
        unordered_map<string, vector<pair<string, double>>> adj;

        /* checked map is for 1- Differentiating variables that has not been included in equations vs has been included in equations */
        /*                    2- Keeping track of where we checked in dfs                                                            */
        unordered_map<string, int> checked;
        

        for(int i = 0; i < equations.size(); i++){
            // mapping variables //
            vector<string> equation = equations[i];
            checked[equation[0]] = 0;
            checked[equation[1]] = 0;
            adj[equation[0]].push_back({equation[1], values[i]});
            adj[equation[1]].push_back({equation[0], 1 / values[i]});
        }

        for(int i = 0; i < queries.size(); i++){
            string dest = queries[i][1];
            double res = -1;
            // if any of the variables has not been included than we cant find answer //
            if(checked.find(dest) == checked.end() || checked.find(queries[i][0]) == checked.end()){
                sol.push_back(double(-1));
                continue;
            }
            checked[queries[i][0]] = 1;
            // if they have been included than let the dfs do the work :) //
            dfs(adj, 1, queries[i][0], dest, res, checked);
            sol.push_back(res);
            checked[queries[i][0]] = 0;
        }

        return sol;
    }

    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, double multp, string var, string& dest, double& res, unordered_map<string, int> checked){
        
        // base case //
        if(var == dest){
            res = multp;
            return;
        }

        for(auto neighbors : adj[var]){
            // if it is not checked we can traverse //
            if(!checked[neighbors.first]){
                checked[neighbors.first] = 1;
                dfs(adj, multp * neighbors.second, neighbors.first, dest, res, checked);
            }
        }
    }
};