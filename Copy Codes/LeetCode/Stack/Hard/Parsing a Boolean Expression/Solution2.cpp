#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        char op;

        for(int i = 0; i < expression.size(); i++){
            // if our current char is a boolean exp or operation then we push it to stack //
            if(expression[i] != ',' && expression[i] != '(' && expression[i] != ')') st.push(expression[i]);
            
            else if(expression[i] == ')'){
                vector<char> exp; // memorizing expressions //
                while (st.top() != '&' && st.top() != '|' && st.top() != '!'){
                    // getting boolean expressions //
                    exp.push_back(st.top());
                    st.pop();
                }
                op = st.top(); // getting operation//
                st.pop();

                if (op == '&') st.push((find(exp.begin(), exp.end(), 'f') != exp.end()) ? 'f' : 't'); // if there is even one false then and operation returns false //
                else if (op == '|') st.push((find(exp.begin(), exp.end(), 't') != exp.end()) ? 't' : 'f'); // if there is no true then or operation returns false //
                else st.push((exp[0] == 't') ? 'f' : 't'); // ! operation return oposite of the exp //
            }
        }       
        return st.top() == 't';
    }
};
