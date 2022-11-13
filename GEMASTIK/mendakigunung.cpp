

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
    ll n, m;
    cin >> n >> m;

    vector<ll> h(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(mp(v, abs(h[u] - h[v])));
        adj[v].pb(mp(u, abs(h[u] - h[v])));
    }

    vector<vector<ll>> dist(n, vector<ll>(n, 1e18));

    for (ll i = 0; i < n; i++)
    {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push(mp(0, i));
        dist[i][i] = 0;
        while (!pq.empty())
        {
            ll d = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            if (d > dist[i][u])
                continue;
            for (auto x : adj[u])
            {
                ll v = x.first;
                ll w = x.second;
                if (dist[i][v] > dist[i][u] + w)
                {
                    dist[i][v] = dist[i][u] + w;
                    pq.push(mp(dist[i][v], v));
                }
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        ll ans = 1e18;
        for (ll j = 0; j < n; j++)
        {
            ans = min(ans, dist[i][j] + abs(h[j] - h[i]));
        }
        cout << ans << endl;
    }

    return 0;
}