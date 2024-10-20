#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> fib(n + 1, 0);
        fib[0] = 1;
        fib[1] = 1;

        for(int i = 2; i < n + 1; i++){
            fib[i] = fib[i - 1] + fib[i - 2]; 
        }

        return fib.back();
    }
};