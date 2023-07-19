#include "iostream"

const int MOD = 1e9 + 7;
#define endl '\n'

long long DP[1005][1005];

using std::cin;
using std::cout;

int main()
{
    DP[0][0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if ( j - i >= 0)
                DP[i][j] = (DP[i - 1][j] + DP[i][j - i]) % MOD;
            else if (j < i)
                DP[i][j] = DP[i - 1][j];
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;

        cout << DP[n][m] << endl;
    }
}