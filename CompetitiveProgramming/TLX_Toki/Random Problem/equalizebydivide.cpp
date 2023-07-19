// B. Equalize by Divide
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given an array a1,a2,…,an
//  of positive integers.

// You can make this operation multiple (possibly zero) times:

// Choose two indices i
// , j
//  (1≤i,j≤n
// , i≠j
// ).
// Assign ai:=⌈aiaj⌉
// . Here ⌈x⌉
//  denotes x
//  rounded up to the smallest integer ≥x
// .
// Is it possible to make all array elements equal by some sequence of operations (possibly empty)? If yes, print any way to do it in at most 30n
//  operations.

// It can be proven, that under the problem constraints, if some way exists to make all elements equal, there exists a way with at most 30n
//  operations.

// Input
// The first line contains a single integer t
//  (1≤t≤1000
// ) — the number of test cases. Descriptions of test cases follow.

// The first line of each test case description contains a single integer n
//  (1≤n≤100
// ).

// The second line of each test case description contains n
//  integers a1,a2,…,an
//  (1≤ai≤109
// ).

// It is guaranteed, that the sum of n
//  for all test cases does not exceed 1000
// .

// Output
// For each test case print a single integer q
//  (−1≤q≤30n
// ). If q=−1
// , there is no solution, otherwise q
//  is equal to the number of operations.

// If q≥0
// , on the next q
//  lines print two integers i
// , j
//  (1≤i,j≤n
// , i≠j
// ) — descriptions of operations.

// If there are multiple solutions, you can print any.

// Example
// inputCopy
// 10
// 1
// 100
// 3
// 1 1 1
// 2
// 2 1
// 2
// 5 5
// 3
// 4 3 2
// 4
// 3 3 4 4
// 2
// 2 100
// 5
// 5 3 6 7 8
// 6
// 3 3 80 3 8 3
// 4
// 19 40 19 55
// outputCopy
// 0
// 0
// -1
// 0
// 2
// 1 3
// 2 1
// 4
// 3 1
// 4 2
// 1 3
// 2 4
// 6
// 2 1
// 2 1
// 2 1
// 2 1
// 2 1
// 2 1
// 8
// 5 2
// 4 2
// 3 2
// 1 3
// 1 3
// 2 1
// 4 1
// 5 1
// 4
// 5 1
// 3 1
// 3 1
// 3 1
// 9
// 4 2
// 2 1
// 1 2
// 1 2
// 3 2
// 3 2
// 1 4
// 2 4
// 3 4
// Note
// In the first and second, fourth test cases all numbers are equal, so it is possible to do nothing.

// In the third test case, it is impossible to make all numbers equal.

// In the fifth test case: [4,3,2]→[2,3,2]→[2,2,2]
// .

// In the sixth test case: [3,3,4,4]→[3,3,2,4]→[3,3,2,2]→[2,3,2,2]→[2,2,2,2]
// .

// Here the red numbers are i
//  indices (that will be assigned), blue numbers are j
//  indices.

// Editorial: Codeforces 1037B Equalize by Divide

// Problem Link: https://codeforces.com/problemset/problem/1037/B

// Overview:
// Given an array of n positive integers, you can perform the following operation multiple times (possibly zero): Choose two indices i, j (1 ≤ i, j ≤ n, i ≠ j). Assign ai := ceil(ai/aj). Here ceil(x) denotes x rounded up to the smallest integer ≥x. Determine whether it is possible to make all array elements equal by some sequence of operations (possibly empty), and if so, print any way to do it in at most 30n operations.

// Solution Approach:
// In this problem, we need to find out whether it is possible to make all array elements equal by performing the given operation multiple times, where we can choose any two indices i and j (i≠j) and update ai:=ceil(ai/aj).

// We can start by observing that ceil(x/y)≥x/y, which implies that at every operation, the value of ai can only increase or remain the same. Thus, the final value of all elements in the array will be greater than or equal to its initial value.

// To solve the problem, we can try to make all array elements as small as possible by dividing the maximum element of the array, and then we can continue reducing all elements until they become equal. We can choose any index i (1≤i≤n) and assign ai:=⌈ai/a1⌉. This will reduce the maximum value of the array, and we can continue this operation until all values become equal. We can prove that this approach will always work as follows:

// Let k be the maximum value in the array initially. After the first operation, we will have at least one value in the array that is less than k. Let p be the minimum value in the array after the first operation. Then after the second operation, we will have at least one value in the array that is less than p, and so on. Since the values of the array can only increase or remain the same after each operation, the maximum value in the array will always decrease or remain the same, and we will eventually reach a state where all values are equal.

// Now, we need to print the sequence of operations that we perform to reduce all elements to their minimum value. To do this, we can keep track of the indices i and j that we choose at each operation, and print them at the end.

// Time Complexity:
// The time complexity of the solution approach is O(n^2), which is sufficient to pass the given constraints (n≤100).

// Space Complexity:
// The space complexity of the solution approach is O(n), which is required to store the input array.

// Let's look at the implementation of the solution approach:

// Implementation:

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
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll max = *max_element(a, a + n);
    ll min = *min_element(a, a + n);
    if (max == min)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == max)
        {
            for (ll j = 0; j < n; j++)
            {
                if (a[j] != max)
                {
                    v.pb({i + 1, j + 1});
                    a[i] = ceil((double)a[i] / a[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    while (a[0] != min)
    {
        for (ll i = 0; i < n; i++)
        {
            if (a[i] == max)
            {
                for (ll j = 0; j < n; j++)
                {
                    if (a[j] != max)
                    {
                        v.pb({i + 1, j + 1});
                        a[i] = ceil((double)a[i] / a[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    for (ll i = 0; i < ans; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
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