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

string konversiBiner(ll t){
    if (t == 0)
    {
        return "0";
    }
    else if (t == 1)
    {
        return "1";
    }
    else
    {
        return konversiBiner(t/2) + konversiBiner(t%2);
    }
}


int main()
{
    fastio();
    ll t;
    cin >> t;
    
    cout << konversiBiner(t) << endl;

    return 0;
}