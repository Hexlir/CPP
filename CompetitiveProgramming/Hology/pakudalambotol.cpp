#include <bits/stdc++.h>
using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> v;
vector<int> a;

int main()
{
    fastio();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = abs(v[i] - a[i]);
        ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}