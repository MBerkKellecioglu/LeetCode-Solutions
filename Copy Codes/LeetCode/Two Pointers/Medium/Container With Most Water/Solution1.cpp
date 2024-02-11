#include<vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height){
        int left_ind = 0, right_ind = height.size() - 1, max_area = 0, area;

        while(left_ind < right_ind){
            int lh = height[left_ind];
            int rh = height[right_ind];
            
            // we find the area and area is determined by lower wall //
            area = min(lh, rh) * (right_ind - left_ind);
            
            max_area = max(max_area, area);
            // basic two pointer logic // 
            if(lh < rh) left_ind++;
            else right_ind--;
        }
        return max_area;
    }
};