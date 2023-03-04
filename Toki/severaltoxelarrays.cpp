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

void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> v(n,vector<ll>(m));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    ll ans = 0;

    for (ll i = 0; i < n/2; i++)
    {
        for (ll j = 0; j < m/2; j++)
        {
            vector<ll> temp;
            temp.pb(v[i][j]);
            temp.pb(v[n-i-1][j]);
            temp.pb(v[i][m-j-1]);
            temp.pb(v[n-i-1][m-j-1]);
            sort(temp.begin(),temp.end());
            ans += abs(temp[0]-temp[1]);
            ans += abs(temp[1]-temp[2]);
            ans += abs(temp[2]-temp[3]);
        }
    }

    if (n%2 == 1){
        for (ll j = 0; j < m/2; j++)
        {
            ans += abs(v[n/2][j]-v[n/2][m-j-1]);
        }
    }

    if (m%2 == 1){
        for (ll i = 0; i < n/2; i++)
        {
            ans += abs(v[i][m/2]-v[n-i-1][m/2]);
        }
    }

    cout << ans << endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}