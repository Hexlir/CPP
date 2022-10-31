// hackerrank game theory powersgame
// https://www.hackerrank.com/challenges/powersgame

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
    for (ll i = 1; i <= t; i++)
    {
        ll n;

        cin >> n;

        if(n % 8 == 0){
            cout << "Second" << endl;
        }
        else{
            cout << "First" << endl;
        }
    }

    return 0;
}