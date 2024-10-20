#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int res_len = 0;
        
        for(int i = 0; i < s.size(); i++){
            expand(i, i, s, result, res_len);
            expand(i, i + 1, s, result, res_len);
        }

        return result;
    }

    void expand(int l, int r, string& s, string& result, int& res_len){

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            if(r - l + 1 > res_len){
                result = s.substr(l, r - l + 1);
                res_len = r - l + 1;
            }
            l--;
            r++;
        }
    }
};