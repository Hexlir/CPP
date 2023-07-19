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

string solve(ll n){
    string ans = "";
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            ll cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            if(cnt > 1){
                ans += to_string(i) + "^" + to_string(cnt) + " x ";
            }else{
                ans += to_string(i) + " x ";
            }
        }
    }
    if(n > 1){
        ans += to_string(n);
    }else{
        ans.pop_back();
        ans.pop_back();
    }
    return ans;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    cout << solve(t);
    return 0;
}