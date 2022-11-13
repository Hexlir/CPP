#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int s0, N, D;

    cin >> s0 >> N >> D;

    for (int i = s0; i <= (s0 + (N - 1) * D); i += D)
    {
        cout << i;
        if (i != (s0 + (N - 1) * D))
        {
            cout << endl;
        }
    } 
    return 0;
}
