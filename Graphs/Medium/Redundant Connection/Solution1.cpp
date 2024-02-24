#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){

        // Standart Union Find Algorithm //

        vector<int> parent;
        vector<int> ranks(edges.size() + 1, 1);

        for(int i = 0; i < edges.size() + 1; i++) parent.push_back(i);

        for(int i = 0; i < edges.size(); i++){
            if(!Union(parent, ranks, edges[i][0], edges[i][1])) return {edges[i][0], edges[i][1]};
        }

        return {};     
    }

    int find(vector<int>& parent, int vertex){

        /* So apparently there is this thing called 'Path Compression' but personally i did not understand it but you can implement it by researching it
        it makes algorithm work faster */
        int root = parent[vertex];
        while(root != parent[root]) root = parent[root];

        return root;
    }


    bool Union(vector<int>& parent, vector<int>& ranks, int vertex1, int vertex2){

        int root1 = find(parent, vertex1);
        int root2 = find(parent, vertex2);

        if(root1 == root2) return false;

        if(ranks[root1] > ranks[root2]){
            parent[root2] = root1;
            ranks[root1] += ranks[root2];
        }
        else{
            parent[root1] = root2;
            ranks[root2] += ranks[root1];
        }

        return true;
    }
};