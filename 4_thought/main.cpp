#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void computeOperator(int& v, char op, char prev_op){
    switch (op)
    {
    case '+':
        v += 4;
        break;
    case '-':
        v -= 4;
        break;
    case '*':
        if(prev_op == '+'){
            v -= 4;
            v += 16;
        }else if(prev_op == '-'){
            v += 4;
            v -= 16;
        }else if(prev_op == '/'){
            if(v == 3){
                v = 0;
            }else if(v == 5){
                v = 8;
            }else{
                v *= 4;
            }
        }else if(prev_op == '*'){
            if(v == 20){
                v = 68;
            }else if(v == -12){
                v = -60;
            }else{
                v *= 4;
            }
        }else{
            v *= 4;
        }
        break;
    case '/':
        if(prev_op == '+'){
            v -= 4;
            v += 1;
        }else if(prev_op == '-'){
            v += 4;
            v -= 1;
        }else if(prev_op == '/'){
            if(v == 3){
                v = 4;
            }else if(v == 5){
                v = 4;
            }else{
                v /= 4;
            }
        }else if(prev_op == '*'){
            if(v == 20){
                v = 8;
            }else if(v == -12){
                v = -0;
            }else{
                v /= 4;
            }
        }else{
            v /= 4;
        }
        break;
    default:
        break;
    }
    return;
}

int evaluateEquation(string e){
    int res = 4;
    char prev_op = ' ';

    for(char c : e){
        computeOperator(res, c, prev_op);
        prev_op = c;
    }

    return res;
    
}

void findEquation(int n){
    string operators = "+-*/";
    if(n < -60 || n > 256){
        cout << "no solution\n";
        return;
    }else if(n == 256){
        cout << "4 * 4 * 4 * 4 = 256";
        return;
    }else{
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    int tmp = evaluateEquation(string()+operators[i]+operators[j]+operators[k]);
                    if(tmp == n){
                        cout << "4 " << operators[i] << " 4 " << operators[j] << " 4 " << operators[k] << " 4 = " << tmp << endl;
                        return;
                    } 
                }
            }
        }
        cout << "no solution\n";
        return;
    }
}

int main(){
    int nb_cases;

    cin >> nb_cases;

    int* inputs = new int[nb_cases];

    for(int i = 0; i < nb_cases; i++){
        int input;
        cin >> input;
        inputs[i] = input;
    }

    for(int i = 0; i < nb_cases; i++){
        findEquation(inputs[i]); 
    }
}

