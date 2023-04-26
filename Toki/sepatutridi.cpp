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

int bebek[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> bebek[i];
    }

    sort(bebek, bebek + n);

    int ans = 0;
    for(int i = 0; i < m; i++) {
        int temp; cin >> temp;
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(temp - bebek[j] == 0 || temp - bebek[j] == 1 || temp - bebek[j] == -1) {
                count++;
            }
            if(count == n-1) {
                ans++;
            }
        }
    }    

    cout << ans << endl;

    return 0;
}