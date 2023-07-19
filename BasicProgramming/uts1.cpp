#include "bits/stdc++.h"

using namespace std;

int main()
{
    int t, n;
    cin >> t >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 0)
            t += t * 0.5;
        else if (i % 3 == 0 || i % 2 == 0)
            t += 1;
        else
            t *= 2;
    }

    cout << "jawaban = " << t << endl;
    return 0;
}