class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(0,0));
        int sol = INT_MAX;

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        bfs(adj,sol, n);

        if(sol == INT_MAX) return -1;

        return sol;   
    }

    void bfs(vector<vector<int>>& adj, int& sol, int& n){

        queue<int> cache;

        for(int i = 0; i < n; i++){
            vector<int> dist(n , INT_MAX);

            vector<int> par(n, -1);

            dist[i] = 0;
            queue<int> cache;

            cache.push(i);

            while(!cache.empty()){
                int curr = cache.front();
                cache.pop();

                vector<int> next = adj[curr];

                for(int child : next){
                    if(dist[child] == INT_MAX){
                        dist[child] = 1 + dist[curr];
                        par[child] = curr;
                        cache.push(child); 
                    }
                    else if(par[child] != curr && par[curr] != child){
                        sol = min(sol, dist[curr] + dist[child] + 1);
                    }
                }
            }
        }
    }
};