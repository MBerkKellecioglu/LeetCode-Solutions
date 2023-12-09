#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map since it works faster compered to a normal map //
        unordered_map<int, int> cache; 

        for(int elements : nums){
            // mapping all elements and update their frequincies //
            cache[elements]++;

            // if an element occurs more then array is not distinct//
            if(cache[elements] > 1) return true; 
        }
        
        // since we couldnt find any duplicates array is distinct//
        return false;
    }
};

