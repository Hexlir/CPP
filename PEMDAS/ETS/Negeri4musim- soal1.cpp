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
    ll t,n;
    cin >> t;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        if (i % 4 == 0)
            t += t * 0.5;
        else if (i % 3 == 0 || i % 2 == 0)
            t += 1;
        else
            t *= 2;
    }

    cout << t << endl;
    return 0;
}