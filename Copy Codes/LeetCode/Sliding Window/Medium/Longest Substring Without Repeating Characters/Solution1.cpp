#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        string sub_s;
        int sol = 0;

        for(char c : s){
            string tmp_s = string(1, c); // we convert our char to string //

            // if our current char is inside the string than we should erase it and slide our window to right //
            if(sub_s.find(tmp_s) != string::npos){
                auto ind = sub_s.find(tmp_s); // we find the index of our repeating char //

                // we get the size of our current string and compare it to the max //
                sol = max(sol, int(sub_s.size()));

                // we delete the string to our repeating character //
                sub_s.erase(0, ind + 1);

                // we add our current char to our string(repeating character) //
                sub_s += tmp_s;
                continue;
            }
            sub_s += tmp_s;
        }
        sol = max(sol, int(sub_s.size())); // we compare it again since we just compare when we encounter repeating characters //
        return sol;
    }
};