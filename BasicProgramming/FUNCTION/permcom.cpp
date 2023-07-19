#include "bits/stdc++.h"
#define endl '\n'

using namespace std;

unsigned long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

unsigned long long perm(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

unsigned long long comb(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n, r;

    cin >> n >> r;

    cout << "Permutasi: " << perm(n, r) << endl;
    cout << "Kombinasi: " << comb(n, r) << endl;

    return 0;
}
