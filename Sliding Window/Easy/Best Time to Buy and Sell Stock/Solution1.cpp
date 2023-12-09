#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left_ind = 0, right_ind = 1, sol = 0, diff;

        while(right_ind < prices.size()){
            // if our left value is less than right value that means we can profit if we buy at left value price //
            if(prices[left_ind] < prices[right_ind]){
                diff = prices[right_ind] - prices[left_ind];
                // we compare it to max profit //
                sol = max(sol, diff);
            }
            else left_ind = right_ind; // if our left value is not less than right value we should slide our window //
            
            // at every iteration we should update our window aswell by incrementing right side of window //
            right_ind++;
        }
        return sol;
    }
};