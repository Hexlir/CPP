#include "bits/stdc++.h"

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using std::cin;
using std::cout;
#define endl '\n'

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int ans = 0;
    ans += n - x;
    ans += 2 * (m - y);

    if(ans > 25){
        cout << "LOLOS" << endl;
    }else{
        cout << "TIDAK LOLOS" << endl;
    }
}