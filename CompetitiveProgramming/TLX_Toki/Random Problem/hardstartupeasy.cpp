// D1. Hot Start Up (easy version)
// time limit per test1 second
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// This is an easy version of the problem. The constraints of t
// , n
// , k
//  are the only difference between versions.

// You have a device with two CPUs. You also have k
//  programs, numbered 1
//  through k
// , that you can run on the CPUs.

// The i
// -th program (1≤i≤k
// ) takes coldi
//  seconds to run on some CPU. However, if the last program we ran on this CPU was also program i
// , it only takes hoti
//  seconds (hoti≤coldi
// ). Note that this only applies if we run program i
//  multiple times consecutively  — if we run program i
// , then some different program, then program i
//  again, it will take coldi
//  seconds the second time.

// You are given a sequence a1,a2,…,an
//  of length n
// , consisting of integers from 1
//  to k
// . You need to use your device to run programs a1,a2,…,an
//  in sequence. For all 2≤i≤n
// , you cannot start running program ai
//  until program ai−1
//  has completed.

// Find the minimum amount of time needed to run all programs a1,a2,…,an
//  in sequence.

// Input
// Input consists of multiple test cases. The first line contains a single integer t
// , the number of test cases (1≤t≤5000
// ).

// The first line of each test case contains n
//  and k
//  (1≤n,k≤5000
// ).

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤k
// ).

// The third line of each test case contains k
//  integers cold1,cold2,…,coldk
//  (1≤coldi≤109
// ).

// The fourth line of each test case contains k
//  integers hot1,hot2,…,hotk
//  (1≤hoti≤coldi
// ).

// It is guaranteed the sum of n
//  and the sum of k
//  over all test cases do not exceed 5000
// .

// Output
// For each test case, print the minimum time needed to run all programs in the given order.

// Example
// inputCopy
// 9
// 3 2
// 1 2 2
// 3 2
// 2 1
// 4 2
// 1 2 1 2
// 5 3
// 2 1
// 4 3
// 1 2 3 1
// 100 100 100
// 1 1 1
// 5 2
// 2 1 2 1 1
// 65 45
// 54 7
// 5 3
// 1 3 2 1 2
// 2 2 2
// 1 1 1
// 5 1
// 1 1 1 1 1
// 1000000000
// 999999999
// 5 6
// 1 6 1 4 1
// 3 6 4 1 4 5
// 1 1 1 1 4 1
// 1 3
// 3
// 4 5 6
// 1 2 3
// 8 3
// 3 3 3 1 2 3 2 1
// 10 10 8
// 10 10 5
// outputCopy
// 6
// 11
// 301
// 225
// 8
// 4999999996
// 11
// 6
// 63
// Note
// In the first test case, we can do the following:

// Run program a1=1
//  on CPU 1
// . It takes cold1=3
//  seconds to run.
// Run program a2=2
//  on CPU 2
// . It takes cold2=2
//  seconds to run.
// Run program a3=2
//  on CPU 2
// . The last program run on this CPU was also program 2
// , so it takes hot2=1
//  second to run.
// In total, we need 3+2+1=6
//  seconds to run them all. We can show this is optimal.

// In the second test case, we can use do the following:

// Run program a1=1
//  on CPU 1
// . It takes cold1=5
//  seconds to run.
// Run program a2=2
//  on CPU 2
// . It takes cold2=3
//  seconds to run.
// Run program a3=1
//  on CPU 1
// . The last program run on this CPU was also program 1
// , so it takes hot1=2
//  seconds to run.
// Run program a4=2
//  on CPU 2
// . The last program run on this CPU was also program 2
// , so it takes hot2=1
//  second to run.
// In total, we need 5+3+2+1=11
//  seconds. We can show this is optimal.

//  Solution for D1 - Hot Start Up (easy version):

// Observations:

// We need to minimize the time needed to run all programs in sequence. Hence, we need to minimize the time needed to run each individual program as well.
// Since each program takes less time to run if the last program on the same CPU was also the same program, we can try to run consecutive programs on the same CPU if possible.
// To determine which CPU to use for a program, we need to know which program was run last on each CPU.
// Approach:

// We will use two DP tables - one for each CPU.

// Let's define the state of each DP table as dp[i][j], where i is the index of the program we are currently processing, and j is the index of the last program run on the CPU.

// We can compute dp[i][j] for each i and j in a bottom-up manner, starting from dp[1][j] = cold[j], where j is the index of the first program to run on the CPU.

// For each subsequent program i, we can compute dp[i][j] by considering two cases:

// Run program i on the same CPU as program i-1: If a[i-1] == j, we can reuse the same CPU and use the hot time for program i. Hence, dp[i][j] = dp[i-1][j] + hot[i].

// Run program i on a different CPU: If a[i-1] != j, we need to switch CPUs and use the cold time for program i. Hence, dp[i][j] = dp[i-1][j'] + cold[i], where j' is the index of the last program run on the other CPU.

// The minimum time needed to run all programs in sequence will be min(dp[n][j]), where j is the index of the last program run on any CPU.

// Time Complexity:

// We have two DP tables, each of size O(nk).
// Computing each dp[i][j] takes O(1) time.
// Hence, the overall time complexity of the algorithm is O(nk).
// Space Complexity:

// We need to store two DP tables, each of size O(nk).
// Hence, the overall space complexity of the algorithm is O(nk).
// Let's see the implementation for the same.

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
    vector<ll> cold(n + 1), hot(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> cold[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> hot[i];
    }
    vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        dp[0][i] = cold[i];
        dp[1][i] = cold[i];
    }
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            if (j == 1)
            {
                dp[0][i] = min(dp[0][i], dp[1][i - 1] + cold[i]);
                dp[1][i] = min(dp[1][i], dp[0][i - 1] + hot[i]);
            }
            else
            {
                dp[0][i] = min(dp[0][i], dp[0][i - 1] + cold[i]);
                dp[1][i] = min(dp[1][i], dp[1][i - 1] + hot[i]);
            }
        }
    }
    cout << min(dp[0][n], dp[1][n]) << endl;
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