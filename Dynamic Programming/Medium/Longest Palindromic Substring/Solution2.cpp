#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        
        int sz = s.size();

        string sol = "";

        // -1 means that cell has not been checked yet //
        vector<vector<int>> dp(sz, vector<int>(sz, -1));

        for(int i = 0; i < sz; i++){
            for(int j = i; j < sz; j++){
                if(s[i] == s[j]){
                    if(validate(dp, i, j, s)){
                        dp[i][j] = 1;
                        if(j - i + 1 > sol.size()){
                            sol = s.substr(i, j - i + 1);
                        }
                    }
                    else dp[i][j] = 0;
                }
                else dp[i][j] = 0;
            }
        }

        return sol; 
    }

    bool validate(vector<vector<int>>& dp, int x, int y, string& s){

        if(s[x] != s[y] || dp[x][y] == 0) return false;
        
        if(dp[x][y] == 1 || abs(x - y) == 0) return true;
        
        if(abs(x - y) == 1){
            if(s[x] == s[y]){
                dp[x][y] = 1;
                return true;                
            }
            else{
                dp[x][y] = 0;
                return false;
            }
        }

        bool valid = validate(dp, x + 1, y - 1, s);

        if(valid){
            dp[x][y] = 1;
            return true;
        }
        else{
            dp[x][y] = 0;
            return false;
        }

        return true;
    }
};