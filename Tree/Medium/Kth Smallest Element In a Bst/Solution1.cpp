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
    int kthSmallest(TreeNode* root, int k){
        return recSmallest(root, k);
    }

    int recSmallest(TreeNode* root, int &k){
        if(root == nullptr) return 0;

        int sol = recSmallest(root->left, k); // going left as much as we can so we can find smallest value and start searching from there by backtracking //

        k--; 
        
        // if k is zero than we found our value //
        if(k == 0) sol = root->val;
        // if k is lesser than zero that means we already found our value and we dont need to search anymore //
        if(k <= 0) return sol;

        sol = recSmallest(root->right, k); // if we still cant find our value then we should search the right side aswell // 

        return sol;
    }
};