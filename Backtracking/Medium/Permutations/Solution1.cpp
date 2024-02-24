#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> used_index(nums.size(), 0);
        vector<int> sub_sol;

        //standart backtracking// 
        recPermute(nums, sol, sub_sol, used_index);

        return sol;
    }

    void recPermute(vector<int>& nums, vector<vector<int>>& sol, vector<int>& sub_sol, vector<int>& used_index){

        //base case//
        if(nums.size() == sub_sol.size()){
            sol.push_back(sub_sol);
            return;
        }
        else if(nums.size() < sub_sol.size()) return;

        for(int i = 0; i < nums.size(); i++){
            // if not used add it to the current perm //
            if(!used_index[i]) sub_sol.push_back(nums[i]);
            else continue;
            used_index[i]++;
            recPermute(nums, sol, sub_sol, used_index);
            sub_sol.pop_back();
            used_index[i]--;
        }
    }
};