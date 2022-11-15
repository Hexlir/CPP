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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

int main()
{
    fastio();
    ll a, pa, harga, totala, totalpa;
    float d;
    cin >> a >> pa >> d >> harga;

    totala = harga/gcd(harga, a);
    totalpa = harga/gcd(harga, pa);

    cout << totala << endl;
    cout << totalpa << endl;
    cout << harga*d << endl;

    
    return 0;
}