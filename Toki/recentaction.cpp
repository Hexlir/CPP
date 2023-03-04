// A. Recent Actions
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// On Codeforces the "Recent Actions" field shows the last n
//  posts with recent actions.

// Initially, there are posts 1,2,…,n
//  in the field (this is in order from top to down). Also there are infinitely many posts not in the field, numbered with integers n+1,n+2,…
// .

// When recent action happens in the post p
// :

// If it is in the "Recent Actions" field, it moves from its position to the top position.
// Otherwise, it is added to the top position, and the post on the down position is removed from the "Recent Actions" field.
// You know, that the next m
//  recent actions will happen in the posts p1,p2,…,pm
//  (n+1≤pi≤n+m
// ) in the moments of time 1,2,…,m
// . Note, that recent actions only happen with posts with numbers ≥n+1
// .

// For each post i
//  (1≤i≤n
// ), find the first time it will be removed from the "Recent Actions" field or say, that it won't be removed.

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases. Descriptions of test cases follow.

// The first line of each test case contains two integers n
// , m
//  (1≤n,m≤5⋅104
// ) — the size of the "Recent Actions" field and the number of actions.

// The next line contains m
//  integers p1,p2,…,pm
//  (n+1≤pi≤n+m
// ).

// It is guaranteed, that the sum of n
//  and the sum of m
//  for all test cases does not exceed 5⋅104
// .

// Output
// For each test case print n
//  integers t1,t2,…,tn
// , where ti=−1
//  if the post i
//  won't be removed or ti
//  equals to the first moment of time the post i
//  will be removed (1≤ti≤m
// ).

// Example
// inputCopy
// 10
// 1 1
// 2
// 3 2
// 5 4
// 4 5
// 5 9 9 5 7
// 5 5
// 6 7 8 9 10
// 3 4
// 4 4 4 4
// 4 4
// 5 5 6 6
// 3 5
// 4 5 5 5 4
// 4 20
// 5 5 24 24 24 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20
// 5 7
// 7 8 7 11 7 12 10
// 6 7
// 8 11 7 8 8 8 12
// outputCopy
// 1 
// -1 2 1 
// -1 5 2 1 
// 5 4 3 2 1 
// -1 -1 1 
// -1 -1 3 1 
// -1 2 1 
// 8 7 3 1 
// 7 6 4 2 1 
// -1 -1 7 3 2 1 
// Note
// In the first test case, the only post 1
//  will be removed at the moment 1
//  and replaced by the post 2
// .

// In the second test case the "Recent Actions" field will be (given an order from top to down):

// Before moment 1
// : [1,2,3]
// , after moment 1
// : [5,1,2]
// . Post number 3
//  was removed.
// Before moment 2
// : [5,1,2]
// , after moment 2
// : [4,5,1]
// . Post number 2
//  was removed.
// Post number 1
//  won't be removed.

// In the third test case the "Recent Actions" field will be (given an order from top to down):

// Before moment 1
// : [1,2,3,4]
// , after moment 1
// : [5,1,2,3]
// . Post number 4
//  was removed.
// Before moment 2
// : [5,1,2,3]
// , after moment 2
// : [9,5,1,2]
// . Post number 3
//  was removed.
// Before moment 3
// : [9,5,1,2]
// , after moment 3
// : [9,5,1,2]
// . Nothing was changed.
// Before moment 4
// : [9,5,1,2]
// , after moment 4
// : [5,9,1,2]
// . The order was changed.
// Before moment 5
// : [5,9,1,2]
// , after moment 5
// : [7,5,9,1]
// . Post number 2
//  was removed.
// Post number 1
//  won't be removed.

// Editorial: Recent Actions

// Problem Link: Codeforces 1567D

// Overview:
// Given a list of n posts, initially, the first n posts are shown in the "Recent Actions" field. If there is a new action on an existing post, that post will be moved to the top. If the new action is on a new post, the oldest post at the bottom of the list will be removed and the new post will be added to the top. We need to find the first time each of the n posts will be removed or determine that it will not be removed.

// Solution Approach:
// We can simulate the actions on the "Recent Actions" list. Let's call the list of the n shown posts l and the set of unseen posts s. We can initialize l with the first n integers and s with the integers from n+1 to m. Then we can iterate through each of the actions in the given sequence, and perform the corresponding operation on l and s.

// If the action is on an existing post, we remove that post from l and insert it at the top. If the action is on a new post, we remove the bottom post from l and add the new post to the top. We also remove the new post from s since it has now been added to l.

// We can keep track of the first time each post is removed in a dictionary called removal_time. Whenever a post is removed from l, we add its index to removal_time with the current time. We can also set the initial value of removal_time to -1 for all posts since we don't know yet if they will be removed.

// Finally, we can iterate through l and set the removal time for any post still in l to -1.

// Algorithm:

// For each test case, read the values of n and m.
// Initialize l with the first n integers and s with the integers from n+1 to m.
// Initialize removal_time dictionary with the values of -1 for all posts.
// For each action in the sequence, perform the following:
// a. If the action is in l, remove it from l and insert it at the top.
// b. If the action is in s, remove the bottom post from l, add the new post to the top, and remove the new post from s.
// c. If the removed post is in l, set its removal time in removal_time to the current time.
// For each post in l, set its removal time in removal_time to -1.
// Print the values of removal_time for all n posts.
// Time Complexity: O(t*m), where t is the number of test cases and m is the number of actions.

// Space Complexity: O(n+m), where n is the size of the "Recent Actions" field and m is the number of actions.

// Code:

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
    ll n, m;
    cin >> n >> m;
    vector<ll> l(n);
    for (ll i = 0; i < n; i++)
    {
        l[i] = i + 1;
    }
    set<ll> s;
    for (ll i = n + 1; i <= m; i++)
    {
        s.insert(i);
    }
    map<ll, ll> removal_time;
    for (ll i = 1; i <= m; i++)
    {
        removal_time[i] = -1;
    }
    ll time = 0;
    for (ll i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (find(l.begin(), l.end(), x) != l.end())
        {
            l.erase(find(l.begin(), l.end(), x));
            l.insert(l.begin(), x);
        }
        else
        {
            ll bottom = l.back();
            l.pop_back();
            l.insert(l.begin(), x);
            s.erase(x);
            removal_time[bottom] = time;
        }
        time++;
    }
    for (ll i = 0; i < n; i++)
    {
        removal_time[l[i]] = -1;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (removal_time[i] == -1)
        {
            cout << removal_time[i]  << " ";
        }
        else
        {
            cout << removal_time[i] + 1  << " ";
        }
    }
    cout << endl;
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