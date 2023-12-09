#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left_ind = 0, max_freq = 0, sol = 0;
        map<char,int> cache;

        for(int right_ind = 0; right_ind < s.size(); right_ind++){
            int tmp = ++cache[s[right_ind]]; // we increment our character value first than assign it to tmp //
            // we compare it to max frequency //
            max_freq = max(max_freq, tmp);
            // if our string has more than k characters to convert for it to be a longest sequence with repeating characters than we should slide our window //
            if((right_ind - left_ind + 1 - max_freq) > k){
                // we increment left side of our window and decrement that characters value // 
                cache[s[left_ind]]--; 
                left_ind++;
            }
            sol = max(sol, (right_ind - left_ind + 1)); // we get our longest string // 
        }
        return sol;
    }
};