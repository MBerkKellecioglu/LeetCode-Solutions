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
    int diameterOfBinaryTree(TreeNode* root){
        return RecDiameter(root, 0);
    }
    
    int RecDiameter(TreeNode* root, int max_len){
        if(root == nullptr) return max_len;
        // Brute Force Approach//
        // Simply we get every nodes depth and compare them to eachother to find maximum //

        int depth;
        depth = maxDepth(root->left) + maxDepth(root->right);

        max_len = max(max_len, depth);

        int ml1 = RecDiameter(root->left, max_len);
        int ml2 = RecDiameter(root->right, max_len);

        max_len = max(ml1, max_len);
        max_len = max(ml2, max_len);

        return max_len;
    }

    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

};