#include "bits/stdc++.h"

using namespace std;

int main(){
    int row;
    cin >> row;

    cout << "    ";

    for (int i = 1 ; i <= row; i++){
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1 ; i <= row; i++){
        cout << i << " ";
        for (int j = 1; j <= row; j++){
            cout << i*j << " ";
        }
        cout << endl;
    }
}