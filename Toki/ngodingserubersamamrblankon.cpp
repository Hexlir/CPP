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

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    short urutan[4];
    for (int i = 0; i < 3; i++)
    {
        cin >> urutan[i];
    }
    sort(urutan, urutan + 3);
    bool k;
    cin >> k;
    if(k){
        for (int i = 0; i < 3; i++)
        {
            cout << urutan[i] << " ";
        }
    }else{
        for (int i = 2; i >= 0; i--)
        {
            cout << urutan[i] << " ";
        }
    }
    cout << endl;
    return 0;
}