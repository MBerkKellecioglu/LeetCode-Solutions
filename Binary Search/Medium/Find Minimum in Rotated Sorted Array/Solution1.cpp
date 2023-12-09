#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums){
        int left_ind = 0, right_ind = nums.size() - 1, mid_ind;

        if(nums[0] < nums[nums.size() - 1] || nums.size() == 1) return nums[0]; // if it is not rotated we just return first value //

        while(left_ind <= right_ind){
            // if our current value is smaller than first value of rotated array then it is the first element of right side of array(smaller side) //
            if(nums[left_ind] < nums[0]) break;

            // rest is reverse binary search logic //
            mid_ind = (left_ind + right_ind) / 2;

            // if mid index number is lower than left index number it belongs to right side of array so we go to left //
            if(nums[mid_ind] < nums[left_ind]) right_ind = mid_ind - 1; 
            // same here but belongs to left side so we go to right side //
            else left_ind = mid_ind + 1; 
        }

        return nums[left_ind]; 
    }
};