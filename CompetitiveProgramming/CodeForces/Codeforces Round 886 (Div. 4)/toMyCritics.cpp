#include "iostream"

#define endl '\n'
using std::cin;

int t;
short a,b,c;

__inline bool solve(short a, short b, short c)
{
    if ( a + b >= 10 || b + c >= 10 || a + c >= 10)
        return true;

    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;

        solve(a,b,c) ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}