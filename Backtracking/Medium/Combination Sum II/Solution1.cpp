#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> sub_sol;
        sort(candidates.begin(), candidates.end());
        
        recSum(candidates, target, sol, sub_sol, 0);

        return sol;
    }

    void recSum(vector<int>& candidates, int target, vector<vector<int>>& sol, vector<int>& sub_sol, int ind){

        if(target == 0){
            sol.push_back(sub_sol);
            return;
        }
        
        for(int i = ind;  i < candidates.size(); i++){
            sub_sol.push_back(candidates[i]);
            if(target - candidates[i] >= 0) recSum(candidates, target - candidates[i], sol, sub_sol, i + 1);
            sub_sol.pop_back();
            // same as first combination sum problem but we eliminate same elemets from subsets //
            if(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++;
        }
    }
};