#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int r = nums.size() - 1, l = 0, mid;


        while(l <= r){
            mid = l + (r - l) / 2;

            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid - 1;
            else return mid;
        }

        if(nums[mid] < target) return mid + 1;

        return mid;
    }
};