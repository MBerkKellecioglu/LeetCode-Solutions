#include<iostream>
#include<fstream>

using namespace std;

int main(){
    
    string anan = "Ozan31.txt";

    ofstream outputFile(anan);

    if(outputFile.is_open()){
        outputFile << "ANAN GÜZEL Mİ\n";
        outputFile << "O ZAMAN ANANI SKM";
    }
}