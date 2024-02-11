#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        string reduced_s;
        // we take our string and get rid of unnecessary characters, lower our mandatory characters and store them in a string//
        for(auto elements : s) if( (isalpha(elements) || isdigit(elements)) && elements != ' ') reduced_s += tolower(elements);

        s = reduced_s;
        //then we reverse our reduced string to see if its equal to its initial form //
        reverse(reduced_s.begin(), reduced_s.end());
        
        if(s == reduced_s) return true; // if it is then we return true;
        else return false;

        return true;
    }
};