#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string main_s;
    vector<vector<string>> partition(string s){
        vector<vector<string>> sol;
        main_s = s;
        vector<string> sub_sol;
        int i = 0, j = 0;

        recPalindrome(sol, i, sub_sol, j);

        return sol;
    }

    void recPalindrome(vector<vector<string>>& sol, int& p_ind, vector<string>& sub_sol, int& p_count){
        if(p_count >= main_s.size()){
            // means we found our sub solution//
            sol.push_back(sub_sol);
            return;
        }
        
        for(int i = 1; i < main_s.size() + 1 - p_ind; i++){
            string sub_s = main_s.substr(p_ind, i);
            p_count += sub_s.size();
            if(isPalindrome(sub_s)){
                // normal backtracking partitioning if you have hard time understanding see my "Permutations" solution //
                sub_sol.push_back(sub_s);
                p_ind += i;
                recPalindrome(sol, p_ind, sub_sol, p_count);
                sub_sol.pop_back();
                p_ind -= i;
            }
            p_count -= sub_s.size();
        }
    }

    bool isPalindrome(string s){

        // function to check if our subset is palindrome or not //
        string reduced_s;
        // my way of checking palindrome is to just convert string to lower chars and reverse it //
        for(auto elements : s) if((isalpha(elements) || isdigit(elements )) && elements != ' ') reduced_s += tolower(elements);
        
        s = reduced_s;
        reverse(reduced_s.begin(), reduced_s.end());
        if(s == reduced_s) return true;
        else return false;

        return true;
    }
};