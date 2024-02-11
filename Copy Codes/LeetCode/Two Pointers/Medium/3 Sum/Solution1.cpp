#include<vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<std::vector<int>> sol;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            int anchor = nums[i];
            //if our anchor number is bigger than 0 since array is sorted sum will never be zero so we break//
            if(anchor > 0) break;

            // check if we encounter any same anchors(duplicates)//
            if(i != 0) if(anchor == nums[i - 1]) continue;

            //rest is the same logic as Two Sum //
            int left_ind = i + 1;
            int right_ind = nums.size() - 1;
            while(left_ind < right_ind){
                int sum = anchor + nums[left_ind] + nums[right_ind];
                if(sum > 0) right_ind--;
                else if(sum < 0) left_ind++;
                else{
                    sol.push_back({anchor, nums[left_ind], nums[right_ind]});
                    left_ind++;
                    //we dodge duplicates here aswell //
                    while(nums[left_ind] == nums[left_ind - 1] && left_ind < right_ind) left_ind++;
                }
            }
        }
        return sol;
    }
};