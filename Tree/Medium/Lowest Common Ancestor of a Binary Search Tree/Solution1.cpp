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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* curr = root;

        while(curr){
            // if our both values(p and q) is bigger than current node than we should go right so our value gets bigger //
            if(q->val > curr->val && p->val > curr->val) curr = curr->right;
            // same logic, if our values(p and q) is lesser than we should go to left value // 
            else if(q->val < curr->val && p->val < curr->val) curr = curr->left;
            // if our current value is bigger than q and lesser than p  than that means we found our ancestor(you can check by drawing any search tree and trying this logic) // 
            else return curr;
        }

        return curr;
    }
};