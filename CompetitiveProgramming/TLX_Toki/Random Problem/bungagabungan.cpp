#include "bits/stdc++.h"

using namespace std;

int main(){
    int P, Q, sum;

    cin >> P >> Q;

    sum = P*P + Q*Q + 1;

    if (sum%4 == 0){
        cout << sum/4 << endl;
    }
    else{
        cout << -1 << endl;
    }
}