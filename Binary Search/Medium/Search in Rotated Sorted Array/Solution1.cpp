#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target){
        int left_ind = 0, right_ind = nums.size() - 1, mid_ind;

        // if array is not rotated we search the array //
        if(nums[0] < nums[nums.size() - 1] || nums.size() == 1) return BinarySearch(nums, target, 0, nums.size() - 1); 

        while(left_ind <= right_ind){
            //finding mininum element of array which is also critical point between right and left side of the array //
            if(nums[left_ind] < nums[0]) break;
            mid_ind = (left_ind + right_ind) / 2;
            if(nums[mid_ind] < nums[left_ind]) right_ind = mid_ind - 1;
            else left_ind = mid_ind + 1;
        }
        // determining if our value belongs to right side or left side of the array // 
        if(target < nums[0]) return BinarySearch(nums, target, left_ind, nums.size() - 1); // sending right side //
        else return BinarySearch(nums, target, 0, left_ind); // sending left side //
          
        return 0;
    }
    
    // normal binary search //
    int BinarySearch(vector<int> nums, int target, int left_ind, int right_ind){
        int mid_ind;

        while(left_ind <= right_ind){
            mid_ind = (left_ind + right_ind) / 2;
            if(nums[mid_ind] < target) left_ind = mid_ind + 1;
            else if(nums[mid_ind] > target) right_ind = mid_ind -1;
            else return mid_ind;
        }
        return -1;
    }
};