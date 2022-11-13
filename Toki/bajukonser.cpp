#include "bits/stdc++.h"

using namespace std;

int main() {
    //baju konser blankon toki
    int B, P , L;
    cin >> B >> P >> L;

    if (B <= 10 && P <= 40 && L <= 90){
        cout << "S" << endl;
    }
    else if (B <= 14 && P <= 60 && L <= 120){
        cout << "M" << endl;
    }
    else if (B <= 18 && P <= 80 && L <= 180){
        cout << "L" << endl;
    }
    else{
        cout << "X" << endl;
    }
    return 0;
}