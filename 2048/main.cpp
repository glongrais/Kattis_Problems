#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct input_info{
    int** grid;
    int direction;
};

int* stringToTable(string s){
    int* l = new int[4];
    stringstream ssin(s);
    int i = 0;

    while(ssin.good() && i < 4){
        ssin >> l[i];
        ++i;
    }

    return l;
}

int** reverseTranspose(int** matrix, int size){
    int** result;

    result = new int*[size];

    for(int i = 0; i < size; i++){
        result[i] = new int[size];
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            result[j][i] = matrix[i][size-j-1];
        }
    }

    return result;
}

input_info readFile(string filename){
    int** grid;
    grid = new int*[4];
    int direction = 0;
    string line;
    ifstream input(filename);
    if(input.is_open()){
        for(int i = 0; i < 4; i++){
            getline(input, line);
            grid[i] = stringToTable(line);
        }
        getline(input, line);
        direction = stoi(line);

    }
    input.close();
    input_info result = {grid, direction};
    return result;
}

int** moveGrid(int** grid, int direction){
    int** result = grid;
    for(int i = 0; i < direction; i++){
        result = reverseTranspose(result, 4);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(result[i][j]==0){
                int tmp = j+1;
                while(tmp < 3 && result[i][tmp] == 0){
                    tmp++;
                }
                result[i][j] = result[i][tmp];
                result[i][tmp] = 0;
            }
        }

        for(int k = 0; k < 3; k++){
            if(result[i][k]==result[i][k+1]){
                result[i][k] *= 2;
                result[i][k+1] = 0;
            }
        }

        for(int l = 0; l < 3; l++){
            if(result[i][l]==0){
                int tmp = l+1;
                while(tmp < 3 && result[i][tmp] == 0){
                    tmp++;
                }
                result[i][l] = result[i][tmp];
                result[i][tmp] = 0;
            }
        }
    }

    for(int i = 0; i < 4 - direction; i++){
        result = reverseTranspose(result, 4);
    }

    return result;
}

int main(int argc,  char **argv) {
    input_info inputs = readFile(argv[1]);
    int** result = moveGrid(inputs.grid, inputs.direction);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%i ", result[i][j]);
        }
        printf("\n");
    }

  return 0;
}