#include <bits/stdc++.h>
    using namespace std;
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<pair<string, int>> v;

int main()
{
    fastio();

    long long int n;
    long long int start = -1;
    cin >> n;
    while (n--)
    {
        string s;
        long long int a;
        cin >> s;
        cin >> a;
        v.push_back({s, a + start});
        start += a;
    }

    int m;
    cin >> m;
    int x = 0;
    int y = 0;
    while (m--)
    {
        long long int i;
        cin >> i;
        i--;
        for (int j = 0; j < v.size(); j++)
        {
            if (i < v[j].second)
            {
                if (v[j].first == "kiri")
                {
                    x--;
                }
                if (v[j].first == "kanan")
                {
                    x++;
                }
                if (v[j].first == "atas")
                {
                    y++;
                }
                if (v[j].first == "bawah")
                {
                    y--;
                }
            cout << x << " " << y << endl;
            cout << v[j].first << " " << v[j].second << endl;
            break;
            }
        }
    }

    cout << "(" << x << "," << y << ")" << endl;
    return 0;
}