#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        // caching elements and their indexes //
        unordered_map<int, int> cache;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int second_ind = cache[target - num]; // getting complementary numbers index // 

             // if we can find our numbers complementary in our cache then we return it //
            if(second_ind) return{i, second_ind - 1};

            //indexes are 1 indexed // 
            cache[num] = i + 1;
        }

        return {};
    }
};