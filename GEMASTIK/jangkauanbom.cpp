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
    ll x, y;
    cin >> x >> y;

    ll n, q;
    cin >> n;

    vector<pair<ll, ll>> v;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.pb(mp(a, b));
    }

    cin >> q;

    while (q--)
    {
        ll r;
        cin >> r;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll a = v[i].first;
            ll b = v[i].second;
            ll dist = (a - x) * (a - x) + (b - y) * (b - y);
            if (dist <= r * r)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}