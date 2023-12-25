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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        recBuild(root, preorder, inorder, 0, 0, int(preorder.size()) );

        return root;
    }

    void recBuild(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int pre_ind, int leftb, int rightb){
        if(!root) return;

        int left_size = 0;
        int curr_val = root->val;
        int inor_ind = 0;

        for(int i = leftb; i < rightb; i++){
            if(inorder[i] == curr_val){
                inor_ind = i;
                break;
            }
            left_size++; // finding how many nodes is left child to our current node //
        }

        int right_size = 0;

        for(int i = inor_ind + 1; i < rightb; i++) right_size++; //  finding how many nodes is right child to our current node 
        
        if(left_size > 0) root->left = new TreeNode(preorder[pre_ind + 1]); // if there is a left child than we add it as a left child //
        if(right_size > 0) root->right = new TreeNode(preorder[pre_ind + left_size + 1]); // if there is a right child than we add it as a right child //
        
        recBuild(root->left, preorder, inorder, pre_ind + 1, leftb, inor_ind); // updating the borders and call function // 
        recBuild(root->right, preorder, inorder, pre_ind + left_size + 1, inor_ind + 1, rightb);
    }
};