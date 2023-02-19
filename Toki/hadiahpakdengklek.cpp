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
    ll a,b,c,n;
    cin >> a >> b >> c >> n;
    
    ll pangkat = b*c;
    ll hasil = pow(a,pow(b,c));

    cout << hasil % (n + 1) << endl; 
    return 0;
}