#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size() > nums2.size()) nums1.swap(nums2);
        
        int size1 = nums1.size(), size2 = nums2.size(), left_ind = 0, right_ind = size1, mid_ind;

        // for further explanation you can watch youtube videos about this problem //

        // basically what we are doing is we are binary searching two arrays and try to partition arrays so we can find middle value //
        while(left_ind <= right_ind){
            mid_ind = (left_ind + right_ind) / 2;
            int other_mid = (size1 + size2 + 1) / 2 - mid_ind;

            // these initializations below are for some edge cases so that we dont try to reach outside of arrays //
            int left_max1 = (mid_ind == 0) ? -1000001 : nums1[mid_ind - 1];
            int right_min1 = (mid_ind == size1) ? 1000001 : nums1[mid_ind];

            int left_max2 = (other_mid == 0) ? -1000001 : nums2[other_mid - 1];
            int right_min2 = (other_mid == size2) ? 1000001 : nums2[other_mid];

            if(left_max1 <= right_min2 && left_max2 <= right_min1){
                // if the size is even then there is two values we should consider //
                if((size1 + size2) % 2 == 0) return double( (double(max(left_max1, left_max2)) + double(min(right_min1, right_min2))) / 2);
                else return double(max(left_max1, left_max2)); // if not we just return the value //
            }
            else if(left_max1 > right_min2) right_ind = mid_ind - 1;
            else left_ind = mid_ind + 1;
        }

        return 0.0;
    }
};