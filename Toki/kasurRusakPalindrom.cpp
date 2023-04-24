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

bool isPalindrome(string s){
    if (s.length() == 0 || s.length() == 1)
    {
        return true;
    }
    else if (s[0] == s[s.length()-1])
    {
        return isPalindrome(s.substr(1, s.length()-2));
    }
    else
    {
        return false;
    }
}

int main()
{
    fastio();
    string s; cin >> s;

    if (isPalindrome(s))
    {
        cout << "YA" << endl;
    }
    else
    {
        cout << "BUKAN" << endl;
    }

    return 0;
}