#include<string>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        unordered_map<char, char> close_bra{{')', '('}, {']', '['}, {'}', '{'}}; // we map our types of brackets // 
        char last_bra = ' ';
        int open_count = 0; 

        // if size is odd then it is impossible it to be valid //
        if(s.size() % 2 == 1) return false;

        for(auto elements : s){
            //checking if our bracket is close//
            if(close_bra.find(elements) != close_bra.end()){
                if(last_bra == ' ') return false; // if last bra is not used then string is not valid //
                else{
                    //if our latest bracket is matching with our latest open bracket we decrement open count //
                    if(close_bra[elements] == last_bra){
                        st.pop();
                        last_bra = 'flag'; // our flag for last bra being used //
                        
                        // updating last open bracket from stack//
                        if(!st.empty()) last_bra = st.top();
                        open_count--;
                    }
                    else return false; 
                }
            }
            else{
                // we update our last open bracket and push it to count //
                last_bra = elements;
                st.push(elements);
                open_count++;
            }
        }
        //if there is open brackets more than zero that means string is not valid //
        if(open_count != 0) return false;
        return true;
    }
};