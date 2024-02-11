#include<string>

using namespace std;

string operator *(string s, int b){
        // operator overload for string multipication //
        string multiplied;
        for(int i = 0; i < b; i++) multiplied += s;
        return multiplied;
}
class Solution {
public:
    string decodeString(string s){
        // look for number of atoms problem on leet code for harder version //
        string num_convert;
        string sol;
        int converted_num = 1, open_count = 0, first_ind;

        if(s.find("[") == string::npos) return s; // if there is no brackets inside then we just return string //

        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                // parsing numbers //
                while(isdigit(s[i + 1])){
                    num_convert += s[i];
                    i++;
                }
                num_convert += s[i];
                converted_num = stoi(num_convert);
                num_convert = "";
            }
            else if(s[i] == '['){
                // we get nested brackets and use recursion to open them //
                open_count++;
                first_ind = i + 1;
                while(open_count != 0){
                    if(s[i + 1] == ']') open_count--;
                    if(s[i + 1] == '[') open_count++;
                    i++;
                }
                string tmp_s = s.substr(first_ind, i - first_ind);
                sol += decodeString(tmp_s) * converted_num; // add it to our main string //
            }
            else sol += s[i];
        }
        // return main string //
        return sol;
    }
};