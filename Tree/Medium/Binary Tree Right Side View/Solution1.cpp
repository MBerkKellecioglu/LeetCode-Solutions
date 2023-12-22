#include<vector>

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
    vector<int> rightSideView(TreeNode* root) {
        return recRight(root, {}, 1);
    }

    vector<int> recRight(TreeNode* root, vector<int> sol, int level){
        if(root == nullptr) return sol;

        // for every level we have only one value so if level is not visited yet we push the first most right value to our solution // 
        if(level > sol.size()) sol.push_back(root->val);

        // going right first(dfs) so we can get the most right values// 
        sol = recRight(root->right, sol, level + 1); 
        // if we cant find any values on right side wee need to go left aswell // 
        sol = recRight(root->left, sol, level + 1);

        return sol;
    }
};