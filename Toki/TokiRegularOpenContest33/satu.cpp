#include <bits/stdc++.h>

#define inf INT_MAX
#define ll long long

#define endl "\n"
#define fastio                             \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(0);                            \
    cout.tie(0);

using std::cin;
using std::cout;
using std::vector;

ll n, m, k, q;
ll s, a;
ll res = 0;

void solve()
{
    cin >> n >> k;
    ll a[n + 9][k + 9];
    ll pos[n * k + 9];
    for (auto i = 1; i <= n; ++i)
    {
        for (auto j = 1; j <= k; ++j)
        {
            cin >> a[i][j];
            pos[a[i][j]] = j;
        }
    }
}