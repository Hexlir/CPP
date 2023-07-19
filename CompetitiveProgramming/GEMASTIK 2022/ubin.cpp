
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


int main()
{
    fastio();
    ll t;
    cin >> t;

    ll arr[t + 1];
    arr[0] = 1;
    arr[1] = 1;

    for (ll i = 2; i <= t; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
    }

    cout << arr[t] << endl;

    

    return 0;
}