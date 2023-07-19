//find the max number in the array and count it

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
    ll a[t];
    for (ll i = 1; i <= t; i++)
    {
        cin >> a[i];
    }
    
    ll max = a[1], count = 0;

    for (ll i = 1; i <= t; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        else if (a[i] == max)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}