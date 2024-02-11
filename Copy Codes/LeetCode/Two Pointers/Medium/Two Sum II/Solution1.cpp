#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        int left_ind = 0, right_ind = numbers.size() - 1;

        while(left_ind < right_ind){
            // similar to binary search if our sum is bigger than target than we should lower our sum or if its lower than target we should increase it //
            int sum = numbers[left_ind] + numbers[right_ind];

            if(sum > target) right_ind--;
            else if(sum < target) left_ind++;
            else return {left_ind + 1, right_ind + 1};
        }
        return numbers;
    }
};