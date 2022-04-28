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
    string line;
    ifstream input(filename);
    if(input.is_open()){
        for(int i = 0; i < 4; i++){
            getline(input, line);
            grid[i] = stringToTable(line);
        }
    }
    input.close();
    input_info result = {grid, 3};
    return result;
}

int** moveGrid(int** grid, int direction){
    int** result = grid;
    for(int i = 0; i < direction; i++){
        result = reverseTranspose(result, 4);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%i,", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%i,", result[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 4 - direction; i++){
        result = reverseTranspose(result, 4);
    }

    return result;
}

int main() {
  input_info inputs = readFile("./Inputs/input_4.txt");
  moveGrid(inputs.grid, inputs.direction);

  return 0;
}