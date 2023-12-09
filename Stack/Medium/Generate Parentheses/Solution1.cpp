#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n){
        return PermParentheses(n, "(", 1, 0);
    }
    vector<string> PermParentheses(int count, std::string perm, int open_count, int close_count){
        vector<string> sol;

        if(close_count == count && open_count == count) return {perm}; // if close count and open count is equal to count then the perm is valid //
        
        if(open_count < count){
            // we take our single perm and add it to solution //
            vector<string> sub_sol = PermParentheses(count, perm + '(', open_count + 1, close_count);
            sol.insert(sol.begin(), sub_sol.begin(), sub_sol.end());
        }
        if(open_count > close_count){
            // same here //
            vector<string> sub_sol = PermParentheses(count, perm + ')', open_count, close_count + 1);
            sol.insert(sol.begin(), sub_sol.begin(), sub_sol.end());
        }
        // return our solution vector //
        return sol;
    }

};