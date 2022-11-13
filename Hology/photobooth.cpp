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
    ll n,m,a;

    cin>>n>>m>>a;

    ll x = n/a;
    ll y = m/a;

    if(n%a!=0) x++;
    if(m%a!=0) y++;

    cout<<x*y<<endl;

    return 0;
}