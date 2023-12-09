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
    TreeNode* invertTree(TreeNode* root){
        // our base case //
        if(root == NULL) return NULL; 
        
        // we change the nodes //
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        // we make recursion call for child nodes to swap them aswell //
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};