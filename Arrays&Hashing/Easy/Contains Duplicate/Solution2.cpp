#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        // sort the array if any duplicates exist they are next to eachother //
        sort(nums.begin(), nums.end()); 
        
        // since the numbers are next to eachother we can check if duplicates exist //
        for(int i = 1; i < nums.size(); i++) if(nums[i] == nums[i - 1]) return true; 
        
        return false;
    }
};