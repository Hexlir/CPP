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
    ll t, a, b;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> a >> b;

        if ((b-a)%a == 0){
            cout << (b-a)/a << endl;
        }
        else{
            cout << ((b-a)/a) + 1 << endl;
        }
    }

    return 0;
}