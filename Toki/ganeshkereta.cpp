#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int list[N];

    for (int i = 1; i <= N; i++)
    {
        cin >> list[i];
    }

    for (int i = N; i >= 1; i--)
    {
        cout << list[i];
        if (i != 1)
        {
            cout << ",";
        }
    }

    
    return 0;
}
