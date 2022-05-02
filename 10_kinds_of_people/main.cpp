#include <iostream>
#include <string>

using namespace std;

struct query
{
    int r1;
    int c1;
    int r2;
    int c2;
};


void readInput(char**& grid, query*& queries){
    int x = 0;
    int y = 0;

    cin >> x >> y;

    grid = new char* [x];

    for(int i = 0; i < x; i ++){
        grid[i] = new char[y];
        cin >> grid[i];
    }

    int nb_queries = 0;

    cin >> nb_queries;

    queries =  new query[nb_queries];

    for(int j = 0; j < nb_queries; j++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        queries[j].r1 = r1;
        queries[j].c1 = c1;
        queries[j].r2 = r2;
        queries[j].c2 = c2;
    }

}

int main(){
    char** grid;
    query* queries;

    readInput(grid, queries);

}