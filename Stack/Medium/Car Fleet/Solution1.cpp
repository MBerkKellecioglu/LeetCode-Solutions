#include<vector>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){

        pair<int, int> pos_speed;
        vector<pair<int, int>> all_cars;
        stack<pair<int, int>> st;

        float time , time2;

        for(int i = 0; i < position.size(); i++){
            // caching all cars pos and speed in a vector // 
            pos_speed.first = position[i];
            pos_speed.second = speed[i];
            all_cars.push_back(pos_speed);
        }
        sort(all_cars.begin(), all_cars.end()); // sorting all cars according to their position //

        // we get closest car time to get to finish line //
        time = float((target - all_cars.back().first)) / float((all_cars.back().second)); 
        st.push(all_cars.back());

        for(int i = all_cars.size() - 2; i > - 1; i--){
            // getting our current car's time to get to finish line //
            time2 = float((target - all_cars[i].first)) / float((all_cars[i].second));
            // if our current car gets to finish line faster than or at exact time with our latest car then it will make a fleet with cars infront of it //
            if(time2 <= time) continue; 
            else{
                // if not then the cars infront of our current will be fleet and our current car will be the first car of our new fleet //
                time = time2;
                st.push(all_cars[i]);
            }
        }
        // the stack has the first cars of our all fleets so the size is equal to fleet count //
        return st.size();
    }
};