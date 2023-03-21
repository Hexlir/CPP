#include "bits/stdc++.h"

using namespace std;

int main(){
    unsigned n;
    cin >> n;

    unsigned long long arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}