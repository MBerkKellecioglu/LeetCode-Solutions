#include <iostream>
#include <fstream>
#include "movie.cpp"
#include <vector>

using namespace std;

void split_assign_Strings(vector<Movie>&v, string line);
void swap(vector<Movie> &v, int i, int j);
void sortFilms(vector<Movie> &v);
void erase_Space(string &n1,string &n2);
string Upper(string n);
void split_Year(string y, int &y1, int &y2);

int main(){

    string txt_name, user_genre, user_year, txt_line, temp_user_genre, temp_mov_genre;

    ifstream Fptr;

    int selec, k2, year1, year2, year3;

    vector<Movie> mov_vec, spec_mov_vec;
    
    cout << "Please enter the movie list filename:";
    cin >> txt_name;

    Fptr.open(txt_name.c_str());

    if(!Fptr.is_open()){
        while(!Fptr.is_open()){
            cout << "Please check filename! Enter a correct movie list filename:";
            cin >> txt_name;

            Fptr.open(txt_name.c_str());
        }
    }

    while(getline(Fptr,txt_line)){
        split_assign_Strings(mov_vec, txt_line);
    }

    sortFilms(mov_vec);

    cout << "Please select your action:" << endl;
    cout << "1. Select the genre of the movie that you want to watch" << endl;
    cout << "2. Select the year of the movie that you want to watch" << endl;
    cout << "3. Exit program" << endl;

    while(1){
        cout << "Enter your choice:";
        cin >> selec;

        if(selec == 1){
            cout << "Please enter the genre of the movie you want to watch:";
            cin >> user_genre;

            temp_user_genre = Upper(user_genre);

            for(int i = 0; i < mov_vec.size(); i++){
                temp_mov_genre = Upper(mov_vec[i].getGenre());
                if(temp_user_genre == temp_mov_genre) spec_mov_vec.push_back(mov_vec[i]);
            }

            if(spec_mov_vec.size() == 0){
                cout << "There are no" << user_genre << "movies!" << endl;
                continue;
            }

            cout << user_genre << " " << "movies from newest to oldest:" << endl;

            sortFilms(spec_mov_vec);

            for(int i = 0; i < spec_mov_vec.size(); i++){
                spec_mov_vec[i].print(user_genre);
            }
            
            spec_mov_vec.clear();
        }
        else if(selec == 2){
            cout << "Please enter the year of the movie you want to watch:";
            cin >> user_year;

            if(user_year.find('-') != std::string::npos){
                split_Year(user_year, year1, year2);

                for(int i = 0; i < mov_vec.size(); i++){
                    if(year1 <= mov_vec[i].getYear() && mov_vec[i].getYear() <= year2) spec_mov_vec.push_back(mov_vec[i]);
                }

                if(spec_mov_vec.size() == 0){
                    cout << "There are no movies released between" << year1 << "-" << year2 << endl;
                    continue;
                }

                cout << "Movies released between the years" << year1 << "-" << year2 << "from A to Z with decreasing year ordering:" << endl;

                sortFilms(spec_mov_vec);

                for(int i = 0; i < spec_mov_vec.size(); i++){
                    spec_mov_vec[i].print();
                }

                spec_mov_vec.clear();
            }
            else{
                year3 = stoi(user_year);

                for(int i = 0; i < mov_vec.size(); i++){
                    if(year3 == mov_vec[i].getYear()) spec_mov_vec.push_back(mov_vec[i]);
                }

                if(spec_mov_vec.size() == 0){
                    cout << "There are no movies released in" << year3 << endl;
                    continue;
                }

                cout << "Movies released in " << year3 << " from A to Z:" << endl;

                for(int i = 0; i < spec_mov_vec.size(); i++){
                    spec_mov_vec[i].print(year3);
                }

                spec_mov_vec.clear();
            }
        }
        else if(selec == 3) break;
        else{
            cout << "Invalid Action" << endl;
            continue;
        }
    }
}

void split_assign_Strings(vector<Movie>&v, string line){

    int i = 0, st_ind = 0;

    string n;

    Movie obj;

    while(!isdigit(line[i])) i++;

    n = line.substr(0, i);

    obj.setName(n);

    st_ind = i;

    while(isdigit(line[i])) i++;

    n = line.substr(st_ind, i - st_ind);

    obj.setYear(stoi(n));

    st_ind = i;

    while(i != line.size()) i++;

    n = line.substr(st_ind + 1, i - st_ind);

    obj.setGenre(n);

    v.push_back(obj);

}

void sortFilms(vector<Movie> &v){

    string name1, name2;

    int lim;
    
    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i].getYear() < v[j].getYear()) swap(v,i,j);
        }
    }

    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i].getYear() == v[j].getYear()){
                name1 = v[i].getName();
                name2 = v[j].getName();
                erase_Space(name1, name2);

                if(name1.size() >= name2.size()) lim = name2.size();
                else lim = name1.size();

                for(int k = 0; k < lim; k++){
                    if(name1[k] > name2[k]){
                        swap(v,i,j);
                        break;
                    }
                    else if(name1[k] == name2[k]) continue;
                    else break;
                }
            }
        }
    }

}

void swap(vector<Movie> &v, int i, int j){

    int temp_year = v[i].getYear();
    string temp_name = v[i].getName(), temp_genre = v[i].getGenre();

    v[i].setName(v[j].getName());
    v[i].setYear(v[j].getYear());
    v[i].setGenre(v[j].getGenre());

    v[j].setName(temp_name);
    v[j].setYear(temp_year);
    v[j].setGenre(temp_genre);
}

void erase_Space(string &n1, string &n2){

    int ind = 0;

    while(ind <= n1.size()){
        if(n1[ind] == ' ') n1.erase(ind, 1);
        ind++;
    }

    ind = 0;

    while(ind <= n2.size()){
        if(n2[ind] == ' ') n2.erase(ind, 1);
        ind++;
    }
}

string Upper(string n){

    for(int i = 0; i < n.size(); i++){
        n[i] = toupper(n[i]);
    }

    return n;
}

void split_Year(string y, int &y1, int &y2){

    int i = 0, i2;

    while(y[i] != '-') i++;

    y1 = stoi(y.substr(0,i));

    i2 = i;

    while(i != y.size()) i++;

    y2 = stoi(y.substr(i2 + 1, i - i2));

}
