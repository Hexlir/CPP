#include "bits/stdc++.h"

using namespace std;

//this program gonna show the square of 0 till input number

int main(int argc, const char** argv) {
    int row;

    cin >> row;

    for(int i = 0; i <= row; i++){
        cout << i << " " << pow(i, 2) << endl;
    }
}