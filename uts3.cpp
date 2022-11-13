#include "bits/stdc++.h"

using namespace std;

int main(){
    double h, d, m, u;
    cin >> h >> d >> m >> u;

    int i = 0;

    while(u >= h){
        if(h < m){
            h = m;
        }

        u -= h;

        if(h >= m){
            h -= (h * d);
        }

        i++;
    }

    cout << i << endl;
}  