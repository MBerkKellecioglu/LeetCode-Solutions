#include<vector>
#include <limits>

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
    bool isValidBST(TreeNode* root){
        bool sol = true;

        double left_boundry = std::numeric_limits<double>::infinity() * (-1);
        double right_boundry = std::numeric_limits<double>::infinity();

        dfs(root, left_boundry, right_boundry, sol);

        return sol;    
    }

    void dfs(TreeNode* root, double left_boundry, double right_boundry, bool& sol){

        if(!root) return;

        if( (left_boundry >= root->val) || (right_boundry <= root->val) ){
            // if our value is not inside our interval then it is not valid // 
            sol = false;
            return;
        }

        // updating right boundry because we go left so left child should be lower than our current value //
        dfs(root->left, left_boundry, double(root->val), sol);
        // updating left boundry because we go right so right child should be lower than our current value //
        dfs(root->right, double(root->val), right_boundry, sol);
    }
};
 