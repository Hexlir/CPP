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
    ll a[t][t];
    ll sum1 = 0, sum2 = 0;

    for (ll i = 0; i < t; i++)
    {
        for(ll j = 0; j < t; j++)
        {
            cin >> a[i][j];
            if(i == j)
            {
                sum1 += a[i][j];
            }
            if(i + j == t - 1)
            {
                sum2 += a[i][j];
            }
        }
    }
    cout << abs(sum1 - sum2) << endl;

    return 0;
}