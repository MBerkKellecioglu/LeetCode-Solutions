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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p != nullptr && q != nullptr){
            // if our pointers are both on nodes we compare it values //
            if(q->val != p->val) return false;
        }
        // if one of the nodes is equal to null and the other one is on node since we are traversing simultaneously on both trees that means they are not the same //
        else if( (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) ) return false; 
        else return true;
        
        bool b1 = isSameTree(p->left, q->left);
        bool b2 = isSameTree(p->right, q->right);
        
        // we return using and operator because even if one false bool returns trees are not same //
        return b1 && b2;
    }
};