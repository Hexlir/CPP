// B. Count the Number of Pairs
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Kristina has a string s
//  of length n
// , consisting only of lowercase and uppercase Latin letters. For each pair of lowercase letter and its matching uppercase letter, Kristina can get 1
//  burl. However, pairs of characters cannot overlap, so each character can only be in one pair.

// For example, if she has the string s
//  = "aAaaBACacbE", she can get a burl for the following character pairs:

// s1
//  = "a" and s2
//  = "A"
// s4
//  = "a" and s6
//  = "A"
// s5
//  = "B" and s10
//  = "b"
// s7
// = "C" and s9
//  = "c"
// Kristina wants to get more burles for her string, so she is going to perform no more than k
//  operations on it. In one operation, she can:

// either select the lowercase character si
//  (1≤i≤n
// ) and make it uppercase.
// or select uppercase character si
//  (1≤i≤n
// ) and make it lowercase.
// For example, when k
//  = 2 and s
//  = "aAaaBACacbE" it can perform one operation: choose s3
//  = "a" and make it uppercase. Then she will get another pair of s3
//  = "A" and s8
//  = "a"

// Find maximum number of burles Kristina can get for her string.

// Input
// The first line of input data contains a single integer t
//  (1≤t≤104
// ) — the number of test cases.

// The description of the test cases follows.

// The first line of each test case contains two integers n
//  (1≤n≤2⋅105
// ) and k
//  (0≤k≤n
// ) — the number of characters in the string and the maximum number of operations that can be performed on it.

// The second line of each test case contains a string s
//  of length n
// , consisting only of lowercase and uppercase Latin letters.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, print exactly one integer on a separate line: the maximum number of burles that Kristina can get for her string s
// .

// Example
// inputCopy
// 5
// 11 2
// aAaaBACacbE
// 2 2
// ab
// 4 1
// aaBB
// 6 0
// abBAcC
// 5 3
// cbccb
// outputCopy
// 5
// 0
// 1
// 3
// 2
// Note
// The first test case is explained in the problem statement.

// In the second test case, it is not possible to get any pair by performing any number of operations.

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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    ll upper=0, lower=0;
    for(ll i=0; i<n; i++){
        if(s[i]>='a' && s[i]<='z'){
            lower++;
        }
        else{
            upper++;
        }
    }
    ll ans = min(upper, lower);
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