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

ll minim = 10e18;
ll maks = -10e18;
ll n, d, x[1001], y[1001];

ll calculate(ll u, ll v){
    ll a = 1;
    ll b = 1;
    for(int i=0; i < d; i++){
        a = a * abs(x[u] - x[v]);
        b = b * abs(y[u] - y[v]);
    }
    return a+b;
}

int main()
{
    fastio();
    cin >> n >> d;
    for(ll i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(ll i=0; i < n; i++){
        for(ll j=0; j < n; j++){
            if (i == j) continue;
            ll temp = calculate(i, j);
            if(temp < minim){
                minim = temp;
            }
            if(temp > maks){
                maks = temp;
            }
        }
    }
    cout << minim << " " << maks << endl;
    return 0;
}