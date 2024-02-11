#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        long long left_val = 1, right_val = *max_element(piles.begin(), piles.end()), mid_val, count = 0, sol;

        // The trick is that we dont have a array but consecutive sequence of numbers up to max element of piles array and we are going to search our optimal value inside our sequence// 

        while(left_val <= right_val){
            // since we are going to search consecutive numbers we dont need an array to store them //
            mid_val = (left_val + right_val) / 2;
            for(int i = 0; i < piles.size(); i++) count += ceil(double(piles[i]) / double(mid_val)); // getting time to eat all bananas //
            if(count > h) left_val = mid_val + 1;
            else{
                // binary search logic but we dont double check if our number is equal //
                right_val = mid_val - 1;
                sol = mid_val;
            }
            count = 0;
        }
        return sol;   
    }

};