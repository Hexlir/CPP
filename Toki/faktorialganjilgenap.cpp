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

ll fakGanjilGenap(int t){
    if (t == 0)
    {
        return 1;
    }
    else if (t % 2 == 0)
    {
        return fakGanjilGenap (t-1) * (t/2);
    }
    else
    {
        return fakGanjilGenap (t-1) * t;
    }
}

int main()
{
    fastio();
    ll t;
    cin >> t;

    cout << fakGanjilGenap(t) << endl;

    return 0;
}