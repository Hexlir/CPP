#include "iostream"

#define ll unsigned long long
#define endl '\n'

const ll MOD = 1e9 + 7;

using std::cin;
using std::cout;

ll n;

inline ll solve (ll n)
{
    ll fib[2][2] = {{1,1},{1,0}};
    ll res[2][2] = {{1,0},{0,1}};
    ll tmp[2][2] = {{0,0},{0,0}};

    ll i, j, k;

    while (n) 
    {
        if (n & 1)
        {
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    tmp[i][j] = 0;
                    for (k = 0; k < 2; k++)
                    {
                        tmp[i][j] += (res[i][k] * fib[k][j]) % MOD;
                    }
                }
            }
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    res[i][j] = tmp[i][j];
                }
            }
        }
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                tmp[i][j] = 0;
                for (k = 0; k < 2; k++)
                {
                    tmp[i][j] += (fib[i][k] * fib[k][j]) % MOD;
                }
            }
        }

        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                fib[i][j] = tmp[i][j];
            }
        }
        n >>= 1;
    }

    return res[0][1];
}

int main()
{
    cin >> n;
    cout << solve (n + 1) * solve (n + 1) % MOD << endl;
}