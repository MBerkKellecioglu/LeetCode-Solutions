#include<vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> cache;
        string tmp;
        vector<vector<string>> sol;

        for(string elements : strs){
            tmp = elements;
            // we sort the strings to see which group of anagrams they are in //
            sort(tmp.begin(), tmp.end()); 
            
            // then we push the orginal string into the group anagram vector //
            cache[tmp].push_back(elements); 
        }
        
        // we push our group anagram vectors into our solution vector //
        for(auto elements : cache) sol.push_back(elements.second); 

        return sol;
    }
};