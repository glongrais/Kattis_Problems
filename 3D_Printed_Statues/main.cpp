#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void readInput(int& n){
    cin >> n;
}

void findMininmumTime(int n){
    int p = ceil(log2(n));
    cout << p+1;
}

int main(){
    int n;

    readInput(n);
    findMininmumTime(n);
}