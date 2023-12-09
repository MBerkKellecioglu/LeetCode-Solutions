#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens){
        std::vector<char> operators = {'+', '*', '/', '-'};
        std::stack<int> st;
        int value = 0, value2 = 0, flag = 0;
        for(auto elements : tokens){
            // checking whether our token is number or not then push it to stack //
            if(isdigit(elements[0]) || isdigit(elements[1])) st.push(stoi(elements)); 
            else{
                // when we see our operators we take 2 values from stack and do the operation //
                value = st.top();
                st.pop();
                value2 = st.top();
                st.pop();
                if(elements == "+") value2 += value;
                else if(elements == "-") value2 -= value;
                else if(elements == "/"){
                    if(value == 0 || value2 == 0){
                        st.push(0);
                        continue;
                    }
                    value2 /= value;
                }
                else value2 *= value;
                st.push(value2); 
            }
        }
        return st.top();
    }
};