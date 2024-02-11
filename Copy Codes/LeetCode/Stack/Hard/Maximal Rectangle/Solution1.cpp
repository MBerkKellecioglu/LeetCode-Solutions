#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int max_area = 0, area = 0;
        std::vector<int> vec(matrix[0].size(), 0);

        for(int i = 0; i < matrix.size(); i++){
            // for every row we use largestRectangleArea function to find largest area on a row//
            for(int j = 0; j < matrix[0].size(); j++){
                // we add rows and cols together to update our heights //
                if(matrix[i][j] == '1') vec[j]++;
                // if it there is no value then we reset our heights //
                else vec[j] = 0;
            }
            area = largestRectangleArea(vec);
            if(max_area < area) max_area = area;
        }
        return max_area;
    }

    // for further explanation about this function check my largestRectangleArea code //
    int largestRectangleArea(vector<int> heights){
        int max_area = 0, last_ind_popped = 0, area;
        std::pair<int, int> ind_val(0, heights[0]);
        std::stack<std::pair<int, int>> st;
        st.push(ind_val);

        for(int i = 1; i < heights.size(); i++){
            if(heights[i] < st.top().second){
                while(!st.empty() && st.top().second > heights[i]){
                    area = st.top().second * (i - st.top().first);
                    if(area > max_area) max_area = area;
                    last_ind_popped = st.top().first;
                    st.pop();
                }
                ind_val.first = last_ind_popped;
                ind_val.second = heights[i];
                st.push(ind_val);
            }
            else{
                ind_val.first = i;
                ind_val.second = heights[i];
                st.push(ind_val);
            }
        }
        while(!st.empty()){
            area = ((heights.size() - st.top().first) * st.top().second);
            if( area > max_area) max_area = area;
            st.pop();
        }
        return max_area;
    }
};