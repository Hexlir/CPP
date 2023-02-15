#include "bits/stdc++.h"

using namespace std;

int dp[1001];
bool done[1001];

int count(int n){
    if(n<= 4){
        return (n/2) + (n/3) + (n/4);
    }
    if (done[n]){
        return dp[n];
    }
    int best = max(count(n/2), n/2) + max(count(n/3), n/3) + max(count(n/4), n/4);
    done[n] = true;
    dp[n] = max(best, n);
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}