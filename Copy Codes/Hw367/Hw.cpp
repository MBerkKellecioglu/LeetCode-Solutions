#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

void BFS(map<int, vector<int>>&, map<int, vector<int>>&, vector<int>&, int);
void detectAllCycles(map<int, vector<int>>&, vector<int>&, vector<vector<int>>&, vector<int>, int);

int main(){

    map<int, vector<int>> adj_list = { {1, {2, 8, 6}},
                                        {8, {7}},            
                                        {4, {1}},            
                                        {2, {1}},
                                        {7, {2}},
                                        {6, {5}},
                                        {5, {11, 2}},
                                        {11, {6, 3, 9}},
                                        {3, {9}},
                                        {9, {10}},
                                        {10, {11}}};

    map<int, vector<int>> bfs_list;
    vector<int> checked_vals(12, 0);
    vector<vector<int>> all_cycles;

    BFS(bfs_list, adj_list, checked_vals, 8);

    for(auto elements : adj_list){
        vector<int> checked_vals(12, 0);
        detectAllCycles(adj_list, checked_vals, all_cycles, {}, elements.first);
    }

    for(auto elements : all_cycles){
        for(auto element : elements) cout << element << " ";
        cout << endl;
    }
}

void BFS(map<int, vector<int>>& bfs_list, map<int, vector<int>>& adj_list, vector<int>& checked_vals, int key){

    queue<int> cache;

    cache.push(key);

    int count = 0;

    while(!cache.empty()){
        int q_size = cache.size();
        count++;

        for(int i = 0; i < q_size; i++){
            int curr = cache.front();
            cache.pop();

            vector<int> next = adj_list[curr];

            for(int i = 0; i < next.size(); i++){
                if(checked_vals[next[i]] == 1) continue;
                cache.push(next[i]);
                bfs_list[next[i]].push_back(curr);
                bfs_list[next[i]].push_back(count);
                checked_vals[next[i]] = 1;
            }
        }
    }
}

void detectAllCycles(map<int, vector<int>>& adj_list, vector<int>& checked_vals, vector<vector<int>>& all_cycles, vector<int> cycle, int key){

    if(checked_vals[key] == 1){
        auto it = find(cycle.begin(), cycle.end(), key);
        cycle.erase(cycle.begin(), it);
        bool flag = 1;
        for(auto c : all_cycles){
            if(c.size() != cycle.size()) continue;
            vector<int> cpy1 = c;
            vector<int> cpy2 = cycle;
            sort(cpy1.begin(), cpy1.end());
            sort(cpy2.begin(), cpy2.end());
            if(cpy2 == cpy1){
                flag = 0;
                break;
            }
        }
        if(flag) all_cycles.push_back(cycle);
        return;
    }
    if(adj_list[key].empty()) return;

    vector<int> next = adj_list[key];

    checked_vals[key] = 1;
    
    cycle.push_back(key);

    for(int i = 0; i < next.size(); i++) detectAllCycles(adj_list, checked_vals, all_cycles, cycle, next[i]);

    checked_vals[key] = 0;
}
