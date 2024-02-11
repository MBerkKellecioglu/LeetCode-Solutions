#include<vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        std::vector<int> sol(nums.size(), 0);
        int pre = 1;
        sol[0] = 1;
        //caching prefixes in our solution vector //
        for(int i = 1; i < nums.size(); i++){
            sol[i] = nums[i - 1] * pre;
            pre *= nums[i - 1];
        }
        pre = 1;
        //caching our postfixes in our solution vector //
        for(int i = nums.size() - 2; i >= 0; i--){
            sol[i] *= nums[i + 1] *pre;
            pre *= nums[i + 1];
        } 
        return sol;
    }
};