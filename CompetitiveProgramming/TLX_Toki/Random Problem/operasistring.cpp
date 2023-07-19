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
    string str1; cin >> str1;
    string str2; cin >> str2;
    string str3; cin >> str3;
    string str4; cin >> str4;

    str1.erase(str1.find(str2), str2.length());
    str1.insert(str1.find(str3) + str3.length(), str4);

    cout << str1 << endl;

    return 0;
}