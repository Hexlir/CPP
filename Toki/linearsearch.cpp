//
// Created by el on 26/10/2022.
//
#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long N,D;
    vector<long> A;
    cin >> N >> D;

    for(long i = 0; i < N; i++){
        long temp;
        cin >> temp;
        A.push_back(temp);
    }

    for(long i = 0; i<= N; i++){
        if(A[i] == D){
            cout << i << endl;
            return 0;
        }

    }
    cout << -1 << endl;
}
