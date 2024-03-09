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
    TreeNode* balanceBST(TreeNode* root){
        vector<int> sorted;

        // inorder traversal for acquiring sorted array //
        inorder(root, sorted);
        
        // Since we have sorted array of numbers to build a balanced version of BST we have to start from middle index //
        int mid = sorted.size() / 2;

        return buildBST(sorted, 0, sorted.size() - 1);  
    }

    void inorder(TreeNode* root, vector<int>& sorted){

        if(root == nullptr) return;

        inorder(root->left, sorted);

        sorted.push_back(root->val);

        inorder(root->right, sorted);
    }

    TreeNode* buildBST(vector<int>& sorted, int l, int r){

        if(l > sorted.size() || r < 0 || l < 0 || r > sorted.size() || l > r ) return nullptr;

        
        // middle index very similiar to how binary search works //
        int mid = (l + r) / 2;

        TreeNode* new_node = new TreeNode(sorted[mid]);

        new_node->left = buildBST(sorted, l, mid - 1);
        new_node->right = buildBST(sorted, mid + 1, r);

        return new_node;
    }
};