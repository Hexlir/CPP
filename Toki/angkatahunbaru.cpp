#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define tc     \
    int tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    fastio();
    int n;
    cin >> n;

    if (n >= 7){
        cout << "NO" << endl;
        return 0;
    }

    if (isPrime(n)){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}