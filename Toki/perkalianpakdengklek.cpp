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
    ll a,b;
    cin >> a >> b;
    vector<ll> a_arr;
    while(a>0){
        a_arr.pb(a%10);
        a/=10;
    }
    vector<ll> b_arr;
    while(b>0){
        b_arr.pb(b%10);
        b/=10;
    }
    ll a_size = a_arr.size();
    ll b_size = b_arr.size();
    ll sum=0;
    for (int i=0;i<a_size;i++){
        for (int j=0;j<b_size;j++){
            sum += a_arr[i]*b_arr[j];
        }
    }
    cout << sum << endl;
    return 0;
}