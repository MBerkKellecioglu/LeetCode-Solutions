#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){

        int max_area = 0, last_ind_popped = 0, area;
        pair<int, int> ind_val(0, heights[0]);
        stack<pair<int, int>> st; // index and heights cache //
        st.push(ind_val);

        for(int i = 1; i < heights.size(); i++){
            if(heights[i] < st.top().second){
                // if our current height is lesser than the top of stack that means for the top of stack it cant be expanding further for more area//
                while(!st.empty() && st.top().second > heights[i]){
                    // we find area of the top of the stack //
                    area = st.top().second * (i - st.top().first);
                    max_area = max(max_area, area); // if its bigger than current max our new max is updated //

                    // we take last index that popped so we can update our current walls index because it slides to indexes of bigger walls //
                    last_ind_popped = st.top().first;
                    st.pop();
                }
                // we push our updated lower wall into our stack //
                ind_val.first = last_ind_popped;
                ind_val.second = heights[i];
                st.push(ind_val);
            }
            else{
                //while our current height is bigger than our top of stack we push our index and height pair to stack //
                ind_val.first = i;
                ind_val.second = heights[i];
                st.push(ind_val);
            }
        }
        while(!st.empty()){
            // for every slided lower wall we get the area and find the max //
            area = ((heights.size() - st.top().first) * st.top().second);
            max_area = max(max_area, area);
            st.pop();
        }
        return max_area;
    }
};