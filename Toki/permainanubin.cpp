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

int solve(int n,int m)
{
    int ans=0;
    ans = ((n/2) * (m/2) * 4);
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;

    cout << solve(n,m) << endl;
    return 0;
}