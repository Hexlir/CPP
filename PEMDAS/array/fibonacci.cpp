// fibonacci
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

void fibonacci(int n)
{
    int a = 0, b = 1, c;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}

int main()
{
    fastio();
    ll n;
    cout << "Masukkan jumlah deret fibonacci: ";
    cin >> n;

    fibonacci(n);
    
    cout << endl;

    return 0;
}