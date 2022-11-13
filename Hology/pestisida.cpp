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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        int y = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j] > x)
            {
                y++;
            }
        }
        ans = max(ans, y);
    }
    cout << ans << endl;

    return 0;
}