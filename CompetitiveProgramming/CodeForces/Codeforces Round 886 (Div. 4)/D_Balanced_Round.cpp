#include "iostream"
#include "math.h"
#include "algorithm"
#include "vector"

using std::vector;
using std::cin;

#define endl '\n'
#define ll long long

int t;
ll n, k;

inline int inputX()
{
    int x;
    scanf("%d", &x);
    return x;
}

int main()
{
    scanf("%d", &t);

    while ( t-- )
    {
        scanf("%lld %lld", &n, &k);
        if (n == 1)
        {
            scanf("%lld", &k);
            printf("0\n");
            continue;
        }

        vector<ll> a(n);
        std::generate(a.begin(), a.end(), inputX);

        ll min_rem = 0;
        std::sort(a.begin(), a.end());
        
        int curr = 1;
        for (int i = 1; i < n; ++i)
        {
            if ( a[i] <= a[i - 1] + k )
            {
                ++curr;
            }
            else
            {
                min_rem = std::max(min_rem, (ll) curr);
                curr = 1;
            }
        }

        min_rem = std::max( (ll) min_rem, (ll) curr);
        printf("%lld\n", n - min_rem);
    }
}