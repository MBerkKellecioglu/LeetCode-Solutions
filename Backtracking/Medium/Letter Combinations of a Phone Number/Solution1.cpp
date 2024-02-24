#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits){
        std::vector<string> alpha = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<string> rec_alpha;

        // edge case // 
        if(digits == "") return rec_alpha;

        // adding elements to convert them //
        for(auto elements : digits) rec_alpha.push_back(alpha[elements - '0' - 2]);

        rec_alpha = RecComb(rec_alpha, 0, "");
        return rec_alpha;
    }
    
    vector<string> RecComb(std::vector<string> alpha, int ind_alpha, string sub_sol){
        vector<string> sol;
        vector<string> tmp;
        
        // base case // 
        if(ind_alpha >= alpha.size()){
            sol.push_back(sub_sol);
            return sol;
        }

        for(auto elements : alpha[ind_alpha]){
            // using map to convert our values //
            tmp = RecComb(alpha, ind_alpha + 1, sub_sol += elements);
            sub_sol.pop_back();
            sol.insert(sol.end(), tmp.begin(), tmp.end());
        }
        return sol;
    }
};