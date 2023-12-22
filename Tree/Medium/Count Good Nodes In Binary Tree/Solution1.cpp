#include <climits>

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
    int goodNodes(TreeNode* root){
        int count = 0;
        recGood(root, INT_MIN, count);

        return count;
    }

    void recGood(TreeNode* root, int max, int& count){
        if(root == nullptr) return;

        if(root->val >= max){
            // on our way if we find a bigger number than max then that means we find a good node so we increment our count // 
            count++;
            max = root->val;
        }

        recGood(root->left, max, count);
        recGood(root->right, max, count);
    }
};