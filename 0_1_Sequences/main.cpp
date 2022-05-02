#include <iostream>
#include <string>
#include<cmath> 

using namespace std;

void reverseStr(string& str)
{
    int n = str.length();
  
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

int pow2(int n, int m){
    int result = pow(2, n);
    return result % m;
}

int main() {
    string input;

    cin >> input;

    int nb_0 = 0;
    int nb_int = 0;
    long total = 0;

    int m = 1000000007;

    reverseStr(input);

    for(char& c : input){
        if(c == '0'){
            nb_0++;
        }else if(c == '1'){
            int zero = nb_0 * pow2(nb_int, m);
            int quest = 0;
            if(nb_int != 0){
                quest = nb_int * pow2(nb_int-1, m);
            }
            total = (total + zero + quest) % m;
        }else{
            total *= 2;
            int zero = nb_0 * pow2(nb_int, m);
            int quest = 0;
            if(nb_int != 0){
                quest = nb_int * pow2(nb_int-1, m);
            }
            total = (total + zero + quest) % m;
            nb_int++;
        }
    }

    cout << total;

}