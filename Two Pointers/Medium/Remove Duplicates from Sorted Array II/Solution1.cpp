#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // slow and fast pointers //
        int s = 0, f = 0;

        while(f < nums.size()){ 
            if(nums[s] == nums[f]) f++; // for finding the range of repeated numbers //
            else{
                if(f - s > 2){
                    // erasing numbers so that there is only 2 numbers left at most //
                    nums.erase(nums.begin() + s, nums.begin() + f - 2);
                    // rearranging fast pointer since we deleted some elements //
                    f -= (f - s - 2);
                }
                s = f;
            }
        }

        // erasing numbers again since when f pointer breaks the loop the last deletion has not been occurred //
        if(f - s > 2) nums.erase(nums.begin() + s, nums.begin() + f - 2);        
        
        return nums.size();
    }
};