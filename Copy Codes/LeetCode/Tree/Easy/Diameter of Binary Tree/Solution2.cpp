#include<vector>
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
    int diameterOfBinaryTree(TreeNode* root){
        vector<int> sol = RecDiameter(root);
        // we return max diameter which is on second element of our vector as mentioned below //
        return sol[1];
    }

    vector<int> RecDiameter(TreeNode* root){
        if(root == nullptr) return {0,0};

        // instead of checking every height we store max height of nodes and calculate maximum diamater on the way //

        // first element of vector stores max height second element stores max diameter //

        vector<int> ld = RecDiameter(root->left);
        vector<int> rd = RecDiameter(root->right);

        // we return max height plus one because start counting height from end nodes and we compare our diameters then we return it //
        return {max(ld[0], rd[0]) + 1, max({ld[0] + rd[0], ld[1], rd[1]})}; 
    }
};