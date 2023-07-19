// menginputkan sejumlah integer dan mengeluarkan nilai terbesar

#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(){
    ull n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int max = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] > max){
            max = v[i];
        }
    }
    cout << max << endl;
}