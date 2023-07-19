// A. Matching
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// An integer template is a string consisting of digits and/or question marks.

// A positive (strictly greater than 0
// ) integer matches the integer template if it is possible to replace every question mark in the template with a digit in such a way that we get the decimal representation of that integer without any leading zeroes.

// For example:

// 42
//  matches 4?;
// 1337
//  matches ????;
// 1337
//  matches 1?3?;
// 1337
//  matches 1337;
// 3
//  does not match ??;
// 8
//  does not match ???8;
// 1337
//  does not match 1?7.
// You are given an integer template consisting of at most 5
//  characters. Calculate the number of positive (strictly greater than 0
// ) integers that match it.

// Input
// The first line contains one integer t
//  (1≤t≤2⋅104
// ) — the number of test cases.

// Each test case consists of one line containing the string s
//  (1≤|s|≤5
// ) consisting of digits and/or question marks — the integer template for the corresponding test case.

// Output
// For each test case, print one integer — the number of positive (strictly greater than 0
// ) integers that match the template.

// Example
// inputCopy
// 8
// ??
// ?
// 0
// 9
// 03
// 1??7
// ?5?
// 9??99
// outputCopy
// 90
// 9
// 0
// 1
// 0
// 100
// 90
// 100

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
    string s;
    cin >> s;
    ll n = s.length();
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            if (i == 0)
            {
                ans *= 9;
            }
            else
            {
                ans *= 10;
            }
        }
        else if (s[i] == '0')
        {
            if (i == 0)
            {
                ans = 0;
                break;
            }
        }
    }
    cout << ans << endl;
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