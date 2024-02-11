#include<string>
#include<map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        std::map<string, int> main_mp;
        string sol = "";

        main_mp = RecAtoms(formula); // returns ordered map for elements and their count //

        for(auto elements : main_mp){
            sol += elements.first;
            if(elements.second == 1) continue;
            sol += to_string(elements.second); // we add our elements and their values to a string and return it //
        }
        return sol;        
    }

    std::map<string, int> RecAtoms(string formula){
        string tmp_s = "";
        int count = 1, close_count = 0, last_ind, first_ind;
        std::map<string, int> main_mp;
        std::map<string, int> tmp_mp;

        //starting from end of string because our numbers comes after our elements so starting from end makes it eaiser to parse the values //
        for(int i = formula.size() - 1; i > -1; i--){
            if(isdigit(formula[i])){
                // parsing numbers into integers //
                tmp_s += formula[i];
                while(isdigit(formula[i - 1])){
                    i--;
                    tmp_s.insert(0,string(1,formula[i]));
                }
                count = stoi(tmp_s);
                tmp_s = "";
            }
            else if(islower(formula[i])){
                // parsing elements and put it to a map //
                tmp_s += formula[i - 1];
                tmp_s += formula[i];
                main_mp[tmp_s] += count;
                i--;
                count = 1;
                tmp_s = "";
            }
            else if(isupper(formula[i])){
                // same here //
                tmp_s += formula[i];
                main_mp[tmp_s] += count;
                count = 1;
                tmp_s = "";  
            }
            else if(formula[i] == ')'){
                // we get nested brackets and use recursion to open them //
                close_count++;
                last_ind = i - 1;
                while(close_count != 0){
                    // we get whole nested bracket //
                    if(formula[i - 1] == ')') close_count++;
                    else if(formula[i -1] == '(') close_count--;
                    i--;
                }
                first_ind = i + 1;
                // we use recursion to operate inside nested brackets //
                tmp_mp = RecAtoms(formula.substr(first_ind, last_ind - first_ind + 1));
                
                // we add map values to our current map which holds elements and their values //
                for(auto elements : tmp_mp) main_mp[elements.first] += (elements.second * count); 
                count = 1;
            }
        }
        // return main map //
        return main_mp;  
    }
};