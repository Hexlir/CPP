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

ll solve(ll a,ll b,ll k,ll x){
    if (k == 1){
        return abs(a*x + b);
    }
    else{
        return solve(a,b,k-1,abs(a*x + b));
    }
}

int main()
{
    fastio();
    ll a,b,k,x;
    cin >> a >> b >> k >> x;

    cout << solve(a,b,k,x) << endl;

    return 0;
}