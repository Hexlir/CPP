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
}


int main()
{
    fastio();
    ll t;
    cout << "Masukkan jumlah bilangan yang akan diinput: ";
    cin >> t;
    ll arr[t];

    for (ll i = 0; i < t; i++)
    {
        ll temp;
        cout << "Masukkan bilangan ke-" << i + 1 << ": ";
        cin >> temp;
        arr[i] = temp;
    }

    cout << "Bilangan yang telah dimasukkan : ";

    for (ll i = 0; i < t; i++)
    {
        cout << arr[i] << " " ;
    }

    return 0;
}