#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        unordered_map<string, set<string>> adj;

        for(auto s : wordList){
            for(int i = 0; i < s.size(); i++){
                /* Instead of checking words word by word we replace all of words by a 'Wildcard' character
                it makes algorithm work faster by reducing complexity -> search in youtube for further explanation */
                string pattern = s;
                pattern[i] = '*';
                adj[pattern].insert(s);
            }
        }

        queue<string> cache;
        set<string> checked;

        cache.push(beginWord);

        int level = 1;

        while(!cache.empty()){
            // Standart BFS //
            int q_size = cache.size();

            for(int i = 0; i < q_size; i++){
                string curr = cache.front();
                if(curr == endWord) return level;
                cache.pop();

                for(int i = 0; i < curr.size(); i++){
                    string pattern = curr;
                    pattern[i] = '*';
                    for(auto words : adj[pattern]){
                        if(checked.find(words) == checked.end()){
                            checked.insert(words);
                            cache.push(words);
                        }
                    }
                }
            }
            level++;
        }

        return 0;
    }
};