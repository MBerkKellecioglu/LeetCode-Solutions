#include<vector>
#include <climits>
#include<queue>

using namespace std;


class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(0,0));
        int sol = INT_MAX;

        for(int i = 0; i < edges.size(); i++){
            // creating our undirected graph by using map //
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        bfs(adj,sol, n);

        if(sol == INT_MAX) return -1;

        return sol;   
    }

    void bfs(vector<vector<int>>& adj, int& sol, int& n){

        /* standart bfs traversal but since this is an undirected graph we dont want to traverse a node where we just came from(can create infinite loop) 
        so we keep track of where we just came from by using a parent vector*/

        queue<int> cache;

        for(int i = 0; i < n; i++){
            // distance vector is for keeping the cycles length and works as unchecked nodes vector aswell//
            vector<int> dist(n , INT_MAX);

            // parent vector //
            vector<int> par(n, -1);

            dist[i] = 0;
            queue<int> cache;

            cache.push(i);

            while(!cache.empty()){
                int curr = cache.front();
                cache.pop();

                vector<int> next = adj[curr];

                for(int child : next){
                    // child that has length of INT_MAX means it is not checked yet// 
                    if(dist[child] == INT_MAX){
                        dist[child] = 1 + dist[curr];
                        // parent child relation here //
                        par[child] = curr;
                        cache.push(child); 
                    }
                    // this if statement makes sure of we did not just came from the parent node //
                    else if(par[child] != curr && par[curr] != child){
                        sol = min(sol, dist[curr] + dist[child] + 1);
                    }
                }
            }
        }
    }
};