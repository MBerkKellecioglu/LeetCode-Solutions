#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left_ind = 0, right_ind= matrix.size() - 1, mid_ind, capacity = matrix[0].size() - 1, mid_ind2;

        while(left_ind <= right_ind){
            // The trick is to implement two binary search algorithms one that searches the main vector that holds other vectors and other is to search single vector //
            mid_ind = (left_ind + right_ind) / 2;
            if(target < matrix[mid_ind][0]) right_ind = mid_ind - 1;
            else if(target > matrix[mid_ind][capacity]) left_ind = mid_ind + 1;
            else{
                left_ind = 0;
                right_ind = capacity;
                while(left_ind <= right_ind){
                    // this is the binary search that searches single vector //
                    mid_ind2 = (left_ind + right_ind) / 2;

                    if(matrix[mid_ind][mid_ind2] > target) right_ind = mid_ind2 - 1;
                    else if(matrix[mid_ind][mid_ind2] < target) left_ind = mid_ind2 + 1;
                    else return true;
                }
                return false;
            }
        }
        return false;
    }
};