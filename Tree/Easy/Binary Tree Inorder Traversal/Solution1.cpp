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
    vector<int> inorderTraversal(TreeNode* root) {

        // standart inorder traversal //
        vector<int> sol;

        inorder(root, sol);

        return sol;
    }

    void inorder(TreeNode* root, vector<int>& sol){

        if(root == nullptr) return;


        inorder(root->left, sol);

        sol.push_back(root->val);

        inorder(root->right, sol);
    }
};