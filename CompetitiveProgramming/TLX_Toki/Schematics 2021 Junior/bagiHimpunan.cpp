#include "iostream"

#define endl '\n'
#define ll long long

using std::cin;
using std::cout;

ll solve (ll n, ll m)
{
    if (n == 1) return 1;
    if (m == 1) return 1;

    return solve(n - 1, m) + solve(n, m - 1);
}


int main()
{
    ll n, m;
    cin >> n >> m;

    cout << solve(n, m) << endl;
}