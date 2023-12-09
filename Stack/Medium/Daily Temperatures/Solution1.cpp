#include<stack>
#include<math.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        std::vector<int> sol(temperatures.size(), 0);
        std::stack<pair<int,int> > st;
        std::pair<int, int> ind_value(temperatures.size() - 1, temperatures.back());
        st.push(ind_value);

        for(int i = temperatures.size() - 1; i > 0; i--){
            while(!st.empty()){
                // getting our temperature and its index //
                ind_value.first = i - 1;
                ind_value.second = temperatures[i - 1];

                if(temperatures[i - 1] > st.top().second) st.pop(); // if our current temperature is bigger than top of stack the top of stack value for sol should be 0 //

                else if(temperatures[i - 1] == st.top().second){
                    // if our temperature is same as top of stack then its solution value should be same as the other duplicate's solution plus the distance between duplictes //
                    if(sol[st.top().first] == 0) sol[i - 1] = 0; // if it is duplicates solution is zero then current temp should be zero aswell //
                    else sol[i - 1] = sol[st.top().first] + abs(i - 1 - st.top().first);
                    st.push(ind_value); // we push our temperatures here //
                    break;
                } 
                else{
                    // if our temperature is lesser than top of stack than we can just add distance between them to solution //
                    sol[i - 1] = abs(i - st.top().first - 1);
                    st.push(ind_value);
                    break;
                }
                // if stack is empty than we just push current temperature //
                if(st.empty()) st.push(ind_value);
            }
        }
        return sol;
    }
};