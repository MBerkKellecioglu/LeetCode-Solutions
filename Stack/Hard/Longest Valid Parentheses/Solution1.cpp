#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s){
        //same question as longest consecutive subsequence in unsorted array//
        std::stack<int> st;
        int longest_seq = 0, seq = 0;
        std::vector<int> all_seq(s.size(),0);

        // we get indexes of our brackets to turn the question into a different one as mentioned above//
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            else{
                if(st.empty()) continue;
                else{
                    all_seq[st.top()]++;
                    all_seq[i]++;
                    st.pop();
                }
            }
        }
        // check my longest consecutive subsequence problem solution if you didnt understand this part //
        for(int i = 0; i < s.size(); i++){
            if(all_seq[i] == 1) seq++;
            else{
                if(seq > longest_seq) longest_seq = seq;
                seq = 0;
            }
        }
        if(seq > longest_seq) longest_seq = seq;
        return longest_seq;
    }    
};