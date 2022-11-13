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
    ll n,k,count = 0;
    cin >> n >> k;
    
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;

        if (temp > k)
        {
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}