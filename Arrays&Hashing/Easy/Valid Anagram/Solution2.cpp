#include<string>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // sorting strings //
        sort(s.begin(), s.end()); 
        sort(t.begin(), t.end());

        // if sorted strings are equal than it is obvious that they are anagram //
        if(s == t) return true; 
        
        return false;
    }
};