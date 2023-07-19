#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[10] = {1000,500,200,100, 50, 20,10, 5,2,1};

    for (int i = 0; i < 10 && n >= 0; i++){
        if(n >= arr[i]){
            cout << arr[i] << " " << floor(n/arr[i]) << endl;
            n -= floor(n/arr[i]) * arr[i];
        }
    }

    return 0;
}