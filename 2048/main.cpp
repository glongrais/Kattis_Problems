#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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

int** readFile(string filename){
    int** result;
    result = new int*[4];
    string line;
    ifstream input(filename);
    if(input.is_open()){
        for(int i = 0; i < 4; i++){
            getline(input, line);
            result[i] = stringToTable(line);
        }
    }
    input.close();
    return result;
}

int main() {
  int** inputs = readFile("./Inputs/input_1.txt");
  for(int i = 0; i < 4; i++){
      for(int j = 0; j<4;j++){
          printf("%i,", inputs[i][j]);
      }
      printf("\n");
  }
  return 0;
}