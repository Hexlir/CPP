// Vlad decided to compose a melody on his guitar. Let's represent the melody as a sequence of notes corresponding to the characters 'a', 'b', 'c', 'd', 'e', 'f', and 'g'.

// However, Vlad is not very experienced in playing the guitar and can only record exactly two notes at a time. Vlad wants to obtain the melody s
// , and to do this, he can merge the recorded melodies together. In this case, the last sound of the first melody must match the first sound of the second melody.

// For example, if Vlad recorded the melodies "ab" and "ba", he can merge them together and obtain the melody "aba", and then merge the result with "ab" to get "abab".

// Help Vlad determine the minimum number of melodies consisting of two notes that he needs to record in order to obtain the melody s
// .

// Input
// The first line of input contains an integer t
//  (1≤t≤104
// ) — the number of test cases.

// Following that are the descriptions of the test cases.

// The first line of each test case contains an integer n
//  (2≤n≤50
// ) — the length of the melody s
// .

// The second line of each test case contains a string s
//  of length n
// , consisting of characters 'a', 'b', 'c', 'd', 'e', 'f', 'g'.

// Output
// Output t
//  integers, each representing the answer for the corresponding test case. As the answer output minimum number of melodies consisting of two notes that Vlad needs to record.

// Example
// inputCopy
// 5
// 4
// abab
// 7
// abacaba
// 6
// aaaaaa
// 7
// abcdefg
// 5
// babdd
// outputCopy
// 2
// 4
// 1
// 6
// 4
// Note
// In the first sample, you need to record the melodies "ab" and "ba", as described in the problem statement.

// In the second sample, you need to record the melodies "ab", "ba", "ac", and "ca".

// In the third sample, the only necessary melody is "aa".



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

#define cout(a) cout << a << endl
#define cout2(a, b) cout << a << " " << b << endl
#define cin(a) cin >> a
#define cin2(a, b) cin >> a >> b

#define str string
#define i32 int
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long

const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    i32 n;
    cin(n);

    str s;
    cin(s);

    str cleanedDuplicated = "";
    // first, clean the duplicated characters but keep the first one
    for (i32 i = 0; i < n; i++)
    {
        if (cleanedDuplicated.size() == 0 || cleanedDuplicated.back() != s[i])
        {
            cleanedDuplicated += s[i];
        }
    }

    // second, count how much 2-char melodies we need to record
    i32 ans = 0;

    for (i32 i = 0; i < cleanedDuplicated.size(); i++)
    {
        if (i == 0 || i == cleanedDuplicated.size() - 1)
        {
            ans++;
        }
        else if (cleanedDuplicated[i] != cleanedDuplicated[i - 1] && cleanedDuplicated[i] != cleanedDuplicated[i + 1])
        {
            ans++;
        }
    }
    cout(ans);
}

int main()
{
    fastio();
    ll t;
    cin(t);
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}