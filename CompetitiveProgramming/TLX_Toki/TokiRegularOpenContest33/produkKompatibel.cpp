#include "iostream"

#define endl "\n"
#define ll long long

using std::cin;
using std::cout;

#define fastIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll MOD = 998244353;

int main()
{
    fastIO;
    ll N, res = 1, g[200009];

    cin >> N;

    for (auto i = 0; i < N; ++i)
    {
        cin >> g[i];
        res = (res * g[i]) % MOD;
    }

    cout << res << endl;

    return 0;
}