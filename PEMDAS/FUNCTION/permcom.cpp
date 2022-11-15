#include "bits/stdc++.h"
#define endl '\n'

using namespace std;

auto factorial(auto n)
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

auto perm(auto n, auto r)
{
    return factorial(n) / factorial(n - r);
}

auto comb(auto n, auto r)
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
