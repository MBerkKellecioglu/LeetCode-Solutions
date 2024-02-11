#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int, int> cache;
        vector<vector<int>> freq(nums.size() + 1, vector<int>(0,0));
        vector<int> sol;

        // we push numbers and their frequincies into a map //
        for(int elements : nums) cache[elements]++; 

        /* then we make a vector of frequincies and add vectors of numbers belonging to those frequincies */
        for(auto elements : cache) freq[elements.second].push_back(elements.first); 
        
        for(int i = freq.size() - 1; i > -1; i--){
            vector<int> tmp = freq[i];

            // we extend our solution vector from end of freq vector because we want top most frequincies //
            if(!tmp.empty()) sol.insert(sol.end(), tmp.begin(), tmp.end());

            // if our solution vector is bigger than k we want to return it since we find all numbers//
            if(sol.size() >= k) return sol; 
        }
        
        return sol;
    }  
};