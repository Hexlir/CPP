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
    string s, t; cin >> s >> t;
    // remove string t in s
    // input : sabunkeramaskekerara kera
    // output : sabunmas
    while (s.find(t) != string::npos)
    {
        s.erase(s.find(t), t.length());
    }
    
    cout << s << endl;
    return 0;
}