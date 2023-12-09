#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula){
        std::stack<std::pair<int, int>> st;
        std::pair<int, int> pr;
        int multpl = 1;
        string tmp_s = "";
        std::map<string, int> main_mp;

        //starting from end of the string not only because it is eaiser to parse (see the recursion solution) but element multipliers are after brackets //
        for(int i = formula.size() - 1; i > -1; i--){
            if(isdigit(formula[i])){
                tmp_s += formula[i];
                // parsing integers //
                while(isdigit(formula[i - 1])){
                    i--;
                    tmp_s.insert(0, string(1,formula[i]));
                }
                pr.first = stoi(tmp_s);
                // getting a flag to differentiate if a multiplier only belongs to a element or a whole bracket of elements //
                if(isalpha(formula[i - 1])) pr.second = 1; // 1 means it belongs to an element //
                else pr.second = 0; // 0 means it belongs to a bracket //
                st.push(pr); 
                multpl *= pr.first; // we get multiplier on the way for nested brackets -> (()2)2 multiplr = 4 //
                tmp_s = "";
            }
            else if(isalpha(formula[i])){
                tmp_s += formula[i];
                if(islower(formula[i])){
                    // parsing elements //
                    tmp_s.insert(0, string(1,formula[i - 1]));
                    i--;
                }
                main_mp[tmp_s] += multpl; // adding element values to map of element values //
                if(!st.empty() && st.top().second == 1){
                    //if our multiplier belongs to an element we want to get rid of it since we just add the multpl value //
                    multpl /= st.top().first;
                    st.pop();
                }
                tmp_s = "";
            }
            else if(formula[i] == '('){
                if(!st.empty()){
                    // this is where we get rid of brackets multpls //
                    multpl /= st.top().first;
                    st.pop();
                }
            }
        }

        for(auto elements : main_mp){
            tmp_s += elements.first;
            if(elements.second == 1) continue;
            tmp_s += to_string(elements.second); // add element and their values to string //
        }
        return tmp_s;
    }
};