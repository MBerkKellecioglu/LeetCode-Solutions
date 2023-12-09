#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    
    int longestConsecutive(vector<int>& nums){
        int length = 0;
        int max_length = 0;
        //we initialize our set to sort and get rid of duplicates // 
        std::set<int> sol(nums.begin(), nums.end());

        for(auto it : sol){
            // if our number has a number that comes before itself than our number cannot be the start of the sequence // 
            if(sol.find(it - 1) != sol.end() ) continue;
            else{
                // we found our start number now we check if our number has consecutive numbers that comes after itself // 
                while(sol.find(it + length) != sol.end()) length++;
                
                max_length = max(length, max_length);
                length = 0;
            }
        }
        return max_length;
    }
};