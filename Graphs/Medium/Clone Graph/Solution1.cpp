#include<vector>
#include<queue>
#include<map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node){
        if(node == nullptr) return {};

        if(node->neighbors.size() == 0){
          Node* single = new Node(node->val);
          return single;
        }

        queue<Node*> cache;

        map<Node*, Node*> mp;

        cache.push(node);

        Node* curr = new Node(node->val);

        mp[node] = curr;

        while(!cache.empty()){
            // BFS //
            curr = cache.front();
            cache.pop();

            vector<Node*> curr_vec = curr->neighbors;

            for(int i = 0; i < curr_vec.size(); i++){
                if(mp[curr_vec[i]] == NULL){
                    // cloning all neighbors //
                    Node* clone = new Node(curr_vec[i]->val);
                    mp[curr_vec[i]] = clone;
                    cache.push(curr_vec[i]);
                }

                mp[curr]->neighbors.push_back(mp[curr_vec[i]]);
            }
        }

        return mp[node];
    }
};