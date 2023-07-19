#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int N;

    cin >> N;

    for(int i = 1; i <= N; i++){
        if (i >= 42){
            cout << "ERROR" << endl;
            return 0;
        }

        if ( i == 10){
            continue;
        }

        if (i == 20){
            continue;
        }

        if (i == 30){
            continue;
        }

        if (i == 40){
            continue;
        }

        if (i == 50){
            continue;
        }
        cout << i << endl;
    }
    return 0;
}
