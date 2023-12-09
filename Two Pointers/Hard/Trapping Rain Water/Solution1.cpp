#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height){
        int left_max = height[0], right_max = height.back() , max_ind = max_element(height.begin(), height.end()) - height.begin();
        int left_ind = 1, right_ind = height.size() - 2, count = 0;

        while(left_ind < max_ind || right_ind > max_ind){
            // update our left max value //
            if(left_max < height[left_ind]) left_max = height[left_ind];

            // update our right max value //
            if(right_max < height[right_ind]) right_max = height[right_ind];

            // if our current window is smaller than left max and we are left at of the max wall then we can trap water // 
            if(left_max - height[left_ind] > 0 && left_ind < max_ind) count += left_max - height[left_ind];

            // same goes for right side of max wall aswell // 
            if(right_max - height[right_ind] > 0 && right_ind > max_ind) count += right_max - height[right_ind];
            
            // update our wall indexes //
            left_ind++;
            right_ind--;
        }

        return count;
    }
};