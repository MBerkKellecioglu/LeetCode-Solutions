#include<vector>
#include <map>
#include<climits>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // mapping values according to their x and y coordinates //
        map<pair<int,int>, vector<int>> cache;
        
        vector<vector<int>> sol;

        int prev = INT_MAX;

        // standart dfs traversal //
        dfs(root, cache, 0, 0);

        for(auto elements : cache){
            vector<int> nodes = elements.second;
            int curr = elements.first.first;


            // if there are more than one nodes on same coordinate pairs then question wants us to sort them //
            if(nodes.size() > 1) sort(nodes.begin(), nodes.end());

            if(prev == curr){
                for(auto nums : nodes) sol.back().push_back(nums);
            }
            else sol.push_back(nodes);

            prev = curr;
        }

        return sol;
    }

    void dfs(TreeNode* root, map<pair<int,int>, vector<int>>& cache, int x, int y){
        if(root == NULL) return;

        cache[{y, x}].push_back(root->val);

        dfs(root->left, cache, x + 1, y - 1);

        dfs(root->right, cache, x + 1, y + 1);
    }
};