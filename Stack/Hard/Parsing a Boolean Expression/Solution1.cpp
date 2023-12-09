#include<string>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression){
        string sol = RecExp(expression, ' ');

        if(sol == "t") return true;
        else return false;

        return false;
    }

    string RecExp(string exp, char op){
        char tmp_op;
        int open_count = 0, first_index;
        string reduced_exp = "";

         // base case, if there is no brackets then we dont need recursion to get rid of brackets //
        if(exp.find("(") == string::npos) return CheckFunc(exp, op);

        for(int i = 0; i < exp.size(); i++){
            if(exp[i] == '|' || exp[i] == '&' || exp[i] == '!'){
                tmp_op = exp[i]; // memorize operation //

                // getting inside the bracket because after op there is open bracket //
                i += 2; 
                open_count++;
                first_index = i; // first index of nested brackets //
                while(open_count != 0){
                    //getting last index of nested brackets //
                    if(exp[i + 1] == '(') open_count++;
                    else if(exp[i + 1] == ')') open_count--;
                    i++;
                }
                // we initiate our recursion on nested brackets //
                reduced_exp += RecExp(exp.substr(first_index, i - first_index), tmp_op);
            }
            // if our char is bool then we just add it to reduced exp //
            else if(exp[i] == 't') reduced_exp += "t";
            else if(exp[i] == 'f') reduced_exp += "f";
        }
        // we also check our last reduced exp which is a string that was removed from nested brackets //
        return CheckFunc(reduced_exp, op);
    }

    string CheckFunc(string exp, char op){
        // we check operations and return boolean string according to that //
        if(op == '!'){
            if(exp[0] == 't') return "f";
            else return "t";
        }
        else if(op == '|'){
            if(exp.find("t") == string::npos) return "f"; // if there is no true then 'or' operation is false //
            else return "t";
        }
        else{
            if(exp.find("f") != string::npos) return "f"; // if there is even one false then 'and' operation is false //
            else return "t";
        }
        return "";
    }
};