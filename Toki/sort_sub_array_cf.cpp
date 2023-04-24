// B. Sort the Subarray
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// Monocarp had an array a
//  consisting of n
//  integers. He has decided to choose two integers l
//  and r
//  such that 1≤l≤r≤n
// , and then sort the subarray a[l..r]
//  (the subarray a[l..r]
//  is the part of the array a
//  containing the elements al,al+1,al+2,…,ar−1,ar
// ) in non-descending order. After sorting the subarray, Monocarp has obtained a new array, which we denote as a′
// .

// For example, if a=[6,7,3,4,4,6,5]
// , and Monocarp has chosen l=2,r=5
// , then a′=[6,3,4,4,7,6,5]
// .

// You are given the arrays a
//  and a′
// . Find the integers l
//  and r
//  that Monocarp could have chosen. If there are multiple pairs of values (l,r)
// , find the one which corresponds to the longest subarray.

// Input
// The first line contains one integer t
//  (1≤t≤104
// ) — the number of test cases.

// Each test case consists of three lines:

// the first line contains one integer n
//  (2≤n≤2⋅105
// );
// the second line contains n
//  integers a1,a2,…,an
//  (1≤ai≤n
// );
// the third line contains n
//  integers a′1,a′2,…,a′n
//  (1≤a′i≤n
// ).
// Additional constraints on the input:

// the sum of n
//  over all test cases does not exceed 2⋅105
// ;
// it is possible to obtain the array a′
//  by sorting one subarray of a
// ;
// a′≠a
//  (there exists at least one position in which these two arrays are different).
// Output
// For each test case, print two integers — the values of l
//  and r
//  (1≤l≤r≤n
// ). If there are multiple answers, print the values that correspond to the longest subarray. If there are still multiple answers, print any of them.

// Example
// inputCopy
// 3
// 7
// 6 7 3 4 4 6 5
// 6 3 4 4 7 6 5
// 3
// 1 2 1
// 1 1 2
// 3
// 2 2 1
// 2 1 2
// outputCopy
// 2 5
// 1 3
// 2 3

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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll l = -1, r = -1;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            l = i;
            break;
        }
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            r = i;
            break;
        }
    }
    reverse(a.begin() + l, a.begin() + r + 1);
    if (a == b)
    {
        cout << l + 1 << " " << r + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}