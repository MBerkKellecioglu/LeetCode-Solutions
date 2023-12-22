#include<vector>
#include<set>

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
        vector<int> sol;

        recValid(root, sol); // we get all values inside a vector and we check if it contains any repeating number or if it is sorted // 

        set<int> valid(sol.begin(), sol.end());

        vector<int> sol2(valid.begin(), valid.end());

        if(sol != sol2) return false;

        return true;
    }

    void recValid(TreeNode* root, vector<int>& all_values){
        if(root == nullptr) return;

        recValid(root->left, all_values);

        all_values.push_back(root->val);

        recValid(root->right, all_values);
    }
};