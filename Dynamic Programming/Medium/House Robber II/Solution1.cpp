#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums){

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        int tmp = nums[0];

        nums.erase(nums.begin());

        int max1 = house1(nums);

        nums.insert(nums.begin(), tmp);

        nums.erase(--nums.end());

        int max2 = house1(nums);

        return max(max1, max2);        
    }

    int house1(vector<int>& nums){
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int dp[nums.size()];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    } 
};