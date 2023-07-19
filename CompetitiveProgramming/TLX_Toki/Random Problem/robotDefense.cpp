#include "iostream"
#include "string"

#define endl '\n'
#define R 1
#define L -1
#define U 1
#define D -1

using std::cin;
using std::cout;
using std::string;

void solve(string *S, int *x, int *y){
    for(int i = 0; i < S->length(); i++){
        if(S->at(i) == 'R'){
            *x += R;
        }
        else if(S->at(i) == 'L'){
            *x += L;
        }
        else if(S->at(i) == 'U'){
            *y += U;
        }
        else if(S->at(i) == 'D'){
            *y += D;
        }
    }
}

int main(){
    string S;
    int x = 0, y = 0;
    cin >> S;

    solve(&S, &x, &y);
    cout << x << " " << y << endl;
}