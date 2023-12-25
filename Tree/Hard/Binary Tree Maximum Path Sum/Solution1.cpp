#include<vector>
#include <climits>
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
    int maxPathSum(TreeNode* root) {
        int sol = INT_MIN;
        recPath(root, sol);
        return sol;
    }

    int recPath(TreeNode* root, int &sol){
        if(root == nullptr) return -10001; // -10001 because it is the lowest constraint //

        int l = recPath(root->left, sol);
        int r = recPath(root->right, sol);

        // we calculate our current sub_tree's value by adding path sums and current value //
        int sub_tree_max = l + r + root->val;
        // we also find our maximum path sum by selecting either left or right path sum and deciding wheter we should add our current value to the (because it can be negative) path//
        int path_max = max(max(l, r) + root->val, root->val);

        // then we compare our current max(sol) and other 2 values that we calculated and update our new max // 
        sol = max({path_max, sub_tree_max, sol});

        return path_max;
    }
};