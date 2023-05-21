#include "bits/stdc++.h"

using namespace std;

int a,b,m;
int arr[107][107];

int solve(int x, int y){
    int ans = 1;
    ans *= arr[x-1][y] * arr[x+1][y] * arr[x][y-1] * arr[x][y+1];
    return ans;
}

int main(){
    cin >> a >> b >> m;

    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= a ; i++){
        arr[i][0] = 1;
        arr[i][b+1] = 1;
    }

    for (int i = 1; i <= b; i++){
        arr[0][i] = 1;
        arr[a+1][i] = 1;
    }

    for (int j = 1; j <= b; j++){
        for (int i = 1; i <= a; i++){
            if (solve(i,j) == m){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "0 0" << endl;
}