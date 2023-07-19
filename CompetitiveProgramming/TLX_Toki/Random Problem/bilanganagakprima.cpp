#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define tc     \
    int tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool solve()
{
    int a, count;
    cin >> a; 
    count = 0;

    for(int i = 2; i * i <= a; i++){
        if (a % i == 0){
            count++;
        }
    }

    if (count >= 2){
        return false;
    }
    return true;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        if (solve())
        {
            cout << "YA" << endl;
        }
        else
        {
            cout << "BUKAN" << endl;
        }
    }
    return 0;
}