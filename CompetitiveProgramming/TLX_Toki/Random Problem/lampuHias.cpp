#include "iostream"

#define ll long long
#define endl '\n'

using std::cin;
using std::cout;

bool isNyala(ll t, ll p, ll q, ll r)
{
    if ((t % p == 0) & (t % q == 0) && (t % r == 0))
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main()
{
    ll p, q, r, n;
    ll t;

    cin >> p >> q >> r;
    cin >> n;

    while (n--)
    {
        cin >> t;
        if(isNyala (t, p, q, r))
        {
            cout << "YA" << endl;
        }
        else
        {
            cout << "TIDAK" << endl;
        }
    }
}