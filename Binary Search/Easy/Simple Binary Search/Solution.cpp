#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Pretty simple binary search //
        int left_ind = 0, right_ind = nums.size() - 1, mid_ind;

        while(left_ind <= right_ind){
            mid_ind = (left_ind + right_ind) / 2;

            if(nums[mid_ind] > target) right_ind = mid_ind - 1;
            else if(nums[mid_ind] < target) left_ind = mid_ind + 1;
            else return mid_ind;
        }
        return -1;
    }
};