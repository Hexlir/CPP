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
    ll t = 5,sum1,sum2,sum3,sum4,sum5;
    ll a[t];
    for (ll i = 1; i <= t; i++)
    {
        cin >> a[i];
    }

    sum1 = a[1] + a[2] + a[3] + a[4];
    sum2 = a[1] + a[2] + a[3] + a[5];
    sum3 = a[1] + a[2] + a[4] + a[5];
    sum4 = a[1] + a[3] + a[4] + a[5];
    sum5 = a[2] + a[3] + a[4] + a[5];

    cout << min(sum1,min(sum2,min(sum3,min(sum4,sum5)))) << " " << max(sum1,max(sum2,max(sum3,max(sum4,sum5)))) << endl;

    return 0;
}