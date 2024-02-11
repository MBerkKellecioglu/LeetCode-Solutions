#include<vector>
#include<math.h>

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
    bool isBalanced(TreeNode* root){
        vector<int> sol = recBalance(root);
        // first value holds max height second value holds boolean values //
        return sol[1];
    }

    vector<int> recBalance(TreeNode* root){
        if(root == nullptr) return {0,1};

        vector<int> lb = recBalance(root->left);
        vector<int> rb = recBalance(root->right);

        // if height difference is more than one or there is false boolean from other recursive calls then it is not height balanced //
        if((lb[1] == 0 || rb[1] == 0) || (abs(lb[0] - rb[0]) > 1) ) return {0,0}; 

        return {max(lb[0], rb[0]) + 1, 1};
    }
};