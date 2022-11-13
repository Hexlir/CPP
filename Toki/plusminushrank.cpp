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
    double t, k, cp = 0, cn = 0, cz = 0;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> k;
        if (k > 0){
            cp++;
        }
        else if (k < 0){
            cn++;
        }
        else{
            cz++;
        }
    }

    cout << fixed << setprecision(6) << cp/t << endl << cn/t << endl << cz/t << endl;

    return 0;
}