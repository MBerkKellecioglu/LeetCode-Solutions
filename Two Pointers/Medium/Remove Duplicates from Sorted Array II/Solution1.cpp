#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int s = 0, f = 0;

        while(f < nums.size()){
            if(nums[s] == nums[f]) f++;
            else{
                if(f - s > 2){
                    nums.erase(nums.begin() + s, nums.begin() + f - 2);
                    f -= (f - s - 2);
                }
                s = f;
            }
        }

        if(f - s > 2) nums.erase(nums.begin() + s, nums.begin() + f - 2);        
        
        return nums.size();
    }
};