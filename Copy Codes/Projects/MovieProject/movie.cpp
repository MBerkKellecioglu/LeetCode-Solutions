#include "movie.hpp"

using namespace std;

Movie::Movie(){

}

Movie::Movie(string n, int y, string g){
    setName(n);
    setYear(y);
    setGenre(g);
}

void Movie::setName(string n){
    name = n;
}

string Movie::getName() const{
    return name;
}

void Movie::setGenre(string g){
    genre = g;
}

string Movie::getGenre() const{
    return genre;
}

void Movie::setYear(int y){
    year = y;
}

int Movie::getYear() const{
    return year;
}

void Movie::print() const{
    cout <<  "Movie Name:" << name << "Release Year: " << year << " Genre:" << genre << endl;
}

void Movie::print(string g) const{

    cout <<  "Movie Name:" << name << "Release Year: " << year << endl;
}

void Movie::print(int y) const{

    cout <<  "Movie Name:" << name << "Genre:" << genre << endl;
}




