#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int, int>
#define LL long long
        using namespace std;

int main()
{
    // clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL t;
    cin >> t;

    while (t--) {
        LL n;
        cin >> n;
        LL a[n+5];

        for (LL i=1;i<=n;i++) {
            cin >> a[i];
        }

        LL ans = -1;
        LL maks = a[n];
        for (LL i=n-1;i>=1;i--) {
            if (a[i] > maks) {
                maks = a[i];
            } else {
                ans = max(ans, maks - a[i]);
            }
        }
        if (ans == 0) cout << -1 << endl;
        else cout << ans << endl;
        
    }
    // cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}