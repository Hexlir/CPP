#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define standar using namespace std

const int inf = 1e9;

standar;

int main(int argc, char const *argv[])
{
    int n, m;

    cin >> n >> m;

    int min = inf;
    int c = inf;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        
        int diff = abs(a - m);
        if (diff < min)
        {
            min = diff;
            c = a;
        }
        if (diff == min && a < c)
        {
            c = a;
        }
    }
    
    cout << c << endl;
    return 0;
}
