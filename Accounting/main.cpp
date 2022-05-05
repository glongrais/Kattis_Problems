#include <iostream>
#include <string>
#include <map>

using namespace std;

void parseCommand(map<int, int>& map, int& val){
    string command;

    cin >> command;

    if(command == "SET"){
        int user1, new_val;
        cin >> user1 >> new_val;
        map[user1] = new_val;
    }else if(command == "PRINT"){
        int user2;
        cin >> user2;
        auto it = map.find(user2);
        if (it != map.end()) {
            cout << it->second << "\n";
        }else{
            cout << val << "\n";
        }
    }else if(command == "RESTART"){
        map.clear();
        cin >> val;
    }
}

int main(){
    int nb_users, nb_commands;

    cin >> nb_users >> nb_commands;

    map<int, int> map;
    int base_val = 0;

    for(int i = 0; i < nb_commands; i++){
        parseCommand(map, base_val);
    }
    cout << flush;
}