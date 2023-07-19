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
    for (ll i = 1; i <= t; i++)
    {
        ll temp;

        cin >> temp;

        if (temp < 38)
        {
            cout << temp << endl;
        }
        else
        {
            ll temp2 = temp;
            while (temp2 % 5 != 0)
            {
                temp2++;
            }
            if (temp2 - temp < 3)
            {
                cout << temp2 << endl;
            }
            else
            {
                cout << temp << endl;
            }
        }
    }

    return 0;
}