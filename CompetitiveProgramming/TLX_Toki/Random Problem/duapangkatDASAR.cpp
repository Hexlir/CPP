#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    long N, I = 1, P;

    cin >> N;

    while(true){
        if( I == N){
            cout << "ya" << endl;
            return 0;
        }
        I *= 2;
        if( I > pow(2,16)){
            break;
        }
    }

    cout << "bukan" << endl;
    return 0;
}
