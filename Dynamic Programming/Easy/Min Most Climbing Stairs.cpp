#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        int dp[n + 2];

        dp[n] = 0;
        dp[n + 1] = 0;

        for(int i = n - 1; i > -1; i--){
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};