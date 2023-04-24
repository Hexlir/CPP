#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void permutasiZigZag(ll t){
    if (t > 0){
        permutasiZigZag(t-1);
        for (int i = 1; i <= t; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        permutasiZigZag(t-1);
    }
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    
    permutasiZigZag(t);

    return 0;
}