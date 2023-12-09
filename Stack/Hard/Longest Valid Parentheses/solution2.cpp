#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s){
        int longest_seq = 0, longest_seq2 = 0, seq = 0, count = 0, count2 = 0, seq2 = 0, j = s.size() - 1; // initialize two pointers //

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')count++; // getting our open bracket count //
            else{
                if(count != 0){
                    // if its not open bracket it is closed so we update our sequence and open count //
                    seq++;
                    count--;
                    if(count == 0) longest_seq = max(longest_seq, seq); // if there is no open bracket then our sequence is done //
                }
                else seq = 0; // if there is no open brackets then the current sequence is not valid so we reset //
            }
            if(s[j] == ')') count2++; // at this portion we start from end and do the same above according to close brackets //
            else{
                if(count2 != 0){
                    seq2++;
                    count2--;
                    if(count2 == 0) longest_seq2 = max(longest_seq2, seq2);
                }
                else seq2 = 0;
            }
            j--;
        }
        // the logic here is that if we traverse the whole array according to both of open and close brackets we find longest sequence. You can try it yourself on paper //
        return max(longest_seq, longest_seq2) * 2;
    }
};