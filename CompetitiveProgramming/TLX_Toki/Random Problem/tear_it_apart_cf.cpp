// C. Tear It Apart
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a string s
// , consisting of lowercase Latin letters.

// In one operation, you can select several (one or more) positions in it such that no two selected positions are adjacent to each other. Then you remove the letters on the selected positions from the string. The resulting parts are concatenated without changing their order.

// What is the smallest number of operations required to make all the letters in s
//  the same?

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of testcases.

// The only line of each testcase contains a string s
// , consisting of lowercase Latin letters. Its length is from 1
//  to 2⋅105
// .

// The total length of the strings over all testcases doesn't exceed 2⋅105
// .

// Output
// For each testcase, print a single integer — the smallest number of operations required to make all the letters in the given string s
//  the same.

// Example
// inputCopy
// 5
// abacaba
// codeforces
// oooooooo
// abcdef
// mewheniseearulhiiarul
// outputCopy
// 1
// 3
// 0
// 2
// 4
// Note
// In the first testcase, you can select positions 2,4
//  and 6
//  and remove the corresponding letters 'b', 'c' and 'b'.

// In the third testcase, the letters in the string are already the same, so you don't have to make any operations.

// In the fourth testcase, one of the possible solutions in 2
//  operations is the following. You can select positions 1,4,6
//  first. The string becomes "bce". Then select positions 1
//  and 3
// . The string becomes "c". All letters in it are the same, since it's just one letter.

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

void solve(){
    string s;
    cin >> s;
    ll n = s.length();
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] != s[0]){
            ans = 1;
            break;
        }
    }
    if(ans == 0){
        cout << 0 << endl;
        return;
    }
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == s[0]){
            cnt++;
        }
        else{
            break;
        }
    }
    if(cnt == n){
        cout << 0 << endl;
        return;
    }
    cnt = 0;
    for(ll i = n - 1; i >= 0; i--){
        if(s[i] == s[n - 1]){
            cnt++;
        }
        else{
            break;
        }
    }
    if(cnt == n){
        cout << 0 << endl;
        return;
    }
    if(s[0] == s[n - 1]){
        cout << 2 << endl;
    }
    else{
        cout << 1 << endl;
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