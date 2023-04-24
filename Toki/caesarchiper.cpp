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
    string s; cin >> s;
    int k; cin >> k;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = 'a' + (s[i] - 'a' + k) % 26;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'A' + (s[i] - 'A' + k) % 26;
        }
    }
    cout << s << endl;
    return 0;
}