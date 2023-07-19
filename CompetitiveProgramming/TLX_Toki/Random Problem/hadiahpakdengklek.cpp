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

ll modexp(ll n, ll m, ll mod){
    ll temp = 1;
    while(m){
        if (m & 1){
            temp = (temp * n) % mod;
        }
        n = (n * n) % mod;
        m >>= 1;
    }
    return temp;
}

int main(){
    ll a,b,c,n;
    cin >> a >> b >> c >> n;
    while(c--){
        a = modexp(a,b,n) % n;
    }
    cout << a + 1 << endl;
}