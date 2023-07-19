#include "bits/stdc++.h"

using namespace std;

//this program will show even number from 20 till 120

int main(int argc, const char** argv) {
    int i = 20;
    while (i <= 120){
        if (i % 2 == 0){
            cout << i << endl;
        }
        i++;
    }
    return 0;
}