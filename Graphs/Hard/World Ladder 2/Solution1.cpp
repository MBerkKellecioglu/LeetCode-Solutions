#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
    unordered_map<string, int> mp;
    vector<vector<string>> sol;
    string begin;

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        // Dude i swear this question is not worth it... Not hard to understand but optimising this was pretty rough //

        // This solution is combination of BFS and DFS traversal -> https://www.youtube.com/watch?v=AD4SFl7tu7I // 

        unordered_set<string> not_checked(wordList.begin(), wordList.end());
        queue<string> cache;

        begin = beginWord;
        mp[beginWord] = 1;
    
        not_checked.erase(beginWord);
        cache.push(beginWord);

        while(!cache.empty()){
            string word = cache.front();
            int steps = mp[word];
            cache.pop();

            if(word == endWord) break;

            for(int i = 0; i < word.size(); i++){
                char original = word[i];

                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;

                    if(not_checked.count(word)){
                        cache.push(word);
                        not_checked.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return sol;
    }

    void dfs(string word, vector<string> & seq){
        if(word == begin){
            reverse(seq.begin(), seq.end());
            sol.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mp[word];

        for(int i = 0; i < word.size(); i++){
            char original = word[i];

            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;

                if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
};