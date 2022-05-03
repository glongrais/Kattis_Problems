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


void readInput(char**& grid, query*& queries, int& x, int& y, int& nb_queries){
    x = 0;
    y = 0;

    cin >> x >> y;

    grid = new char* [x];

    for(int i = 0; i < x; i ++){
        grid[i] = new char[y];
        cin >> grid[i];
    }

    nb_queries = 0;

    cin >> nb_queries;

    queries =  new query[nb_queries];

    for(int j = 0; j < nb_queries; j++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        queries[j].r1 = r1-1;
        queries[j].c1 = c1-1;
        queries[j].r2 = r2-1;
        queries[j].c2 = c2-1;
    }

}

int checkNeighbors(char** grid, int** checked, int x, int y, char target, int target_x, int target_y, int max_x, int max_y){

    if(x < 0 || x >= max_x || y < 0 || y >= max_y){
        return 0;
    }

    if(checked[x][y] == 1){
        return 0;
    }

    if(grid[x][y] != target){
        checked[x][y] = 1;
        return 0;
    }else if(x == target_x && y == target_y){
        return 1;
    }else{
        checked[x][y] = 1;
        return checkNeighbors(grid, checked, x-1, y, target, target_x, target_y, max_x, max_y) +
               checkNeighbors(grid, checked, x, y-1, target, target_x, target_y, max_x, max_y) +
               checkNeighbors(grid, checked, x+1, y, target, target_x, target_y, max_x, max_y) +
               checkNeighbors(grid, checked, x, y+1, target, target_x, target_y, max_x, max_y);
    }
}

void findRoute(char** grid, query q, int max_x, int max_y){
    int** checked;
    
    checked = new int*[max_x];

    for(int i = 0; i < max_x; i++){
        checked[i] = new int[max_y];
        for(int j = 0; j < max_y; j++){
            checked[i][j] = 0;
        }
    }

    char target = grid[q.r1][q.c1];

    int res = checkNeighbors(grid, checked, q.r1, q.c1, target, q.r2, q.c2, max_x, max_y);

    if(res == 0){
        cout << "neither" << endl;
    }else if(target == '0'){
        cout << "binary" << endl;
    }else{
        cout << "decimal" << endl;
    }

}

int main(){
    char** grid;
    query* queries;
    int x, y, nb_queries;

    readInput(grid, queries, x, y, nb_queries);

    for(int i = 0; i < nb_queries; i++){
        findRoute(grid, queries[i], x, y);
    } 
}