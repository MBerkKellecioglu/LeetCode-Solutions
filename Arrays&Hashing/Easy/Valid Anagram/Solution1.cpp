#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t){
        unordered_map<char,int> cache;

        // if string sizes are not equal than it cant be anagram //
        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++){
            // mapping all elements and memorize its frequincies by incrementing and decrementing //
            cache[s[i]]++; 
            cache[t[i]]--;
        }
        // if all elements have zero frequincies than that means strings have equal frequiencies //
        for(auto elements : cache) if(elements.second != 0) return false;
        
        return true;
    }
};