#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol = {{}};
        vector<int> sub_set;

        recSet(nums, sub_set ,sol, 0);

        return sol;
    }

    void recSet(vector<int>& nums, vector<int>& sub_set, vector<vector<int>>& sol, int ind){
        if(sub_set.size() >= nums.size() || ind >= nums.size()) return;

        for(int i = ind; i < nums.size(); i++){
            // adding elements to the current subset//
            sub_set.push_back(nums[i]);
            recSet(nums, sub_set, sol, i + 1);
            // adding subset to solution//
            sol.push_back(sub_set);
            // we need to backtrack, so we pop the element from current subset//
            sub_set.pop_back();
        }
    }
};