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
    deque<int> dq;

    while(t--){
        string s;
        cin >> s;

        if(s == "push_back"){
            ll x;
            cin >> x;
            dq.push_back(x);
        }
        else if(s == "push_front"){
            ll x;
            cin >> x;
            dq.push_front(x);
        }
        else if(s == "pop_back"){
            dq.pop_back();
        }
        else if(s == "pop_front"){
            dq.pop_front();
        }
    }

    for(auto x : dq){
        cout << x << endl;
    }

    return 0;
}