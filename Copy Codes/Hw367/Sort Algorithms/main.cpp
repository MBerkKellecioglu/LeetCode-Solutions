#include <ctime>
#include <cstdlib>
#include <iostream>
#include"selection.cpp"
#include"quick.cpp"
#include"merge.cpp"
#include"insertion.cpp"
#include"heap.cpp"
#include"comb.cpp"
#include"counting.cpp"

using namespace std;

#define n1 1000
#define n2 10000
#define n3 100000
#define n4 1000000

int * random_array(int size, int seed) {
    std::srand(seed);

    int *arr = new int[size];

    for (int i = 0; i < size; i++) arr[i] = std::rand() % 100;

    return arr;
}

int main(){

    int *arr = random_array(n4, 31);

    std::time_t start, end;

    start = std::clock();
    counting_sort(arr,n4);
    end = std::clock();

    double total_time = std::difftime(end, start) / CLOCKS_PER_SEC;

    cout << total_time;
    
}