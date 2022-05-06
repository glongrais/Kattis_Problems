#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int smallest_size;

    cin >> smallest_size;

    int* sheets = new int[smallest_size-1];

    float global_area_possible = 0.0;
    float tape = 0.0;

    for(int i = 0; i < smallest_size-1; i++){
        int nb_sheets;
        cin >> nb_sheets;

        global_area_possible += (0.5/pow(2.0, (float)i)) * (float)nb_sheets;

        sheets[i] = nb_sheets;

        if(nb_sheets == 1){
            tape += pow(2.0, (-5)/4);
        }

        if(global_area_possible == 1.0){
            cout << "yeah";
            break;
        }
    }

    if(global_area_possible < 1.0){
        cout << "impossible";
        return 1;
    }
}