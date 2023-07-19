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
    ll t, count = 0;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll temp1, temp2, temp3;

        cin >> temp1 >> temp2 >> temp3;

        if (temp1 + temp2 + temp3 >= 2)
            count++;
    }

    cout << count << endl;

    return 0;
}