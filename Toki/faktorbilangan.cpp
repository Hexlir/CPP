#include "bits/stdc++.h"

using namespace std;

int main()
{
    long long N;

    cin >> N;

    for(int i = N; i > 0; i--){
        if(N % i == 0){
            cout << i << endl;
        }
    }
}
    