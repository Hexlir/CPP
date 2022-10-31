// Petya has got an interesting flower. Petya is a busy person, so he sometimes forgets to water it. You are given n days from Petya's live and you have to determine what happened with his flower in the end.

// The flower grows as follows:

// If the flower isn't watered for two days in a row, it dies.
// If the flower is watered in the i-th day, it grows by 1 centimeter.
// If the flower is watered in the i-th and in the (i−1)-th day (i>1), then it grows by 5 centimeters instead of 1.
// If the flower is not watered in the i-th day, it does not grow.
// At the beginning of the 1-st day the flower is 1 centimeter tall. What is its height after n days?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

// The first line of each test case contains the only integer n (1≤n≤100).

// The second line of each test case contains n integers a1,a2,…,an (ai=0 or ai=1). If ai=1, the flower is watered in the i-th day, otherwise it is not watered.

// Output
// For each test case print a single integer k — the flower's height after n days, or −1, if the flower dies


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


int main()
{
    fastio();
    
    tc{
        ll n;
        cin >> n;
        ll a[n];
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        ll h = 1;
        ll c = 0;
        for (int i=0; i<n; i++){
            if (a[i] == 1){
                if (c == 0){
                    h += 1;
                    c = 1;
                }
                else{
                    h += 5;
                    c = 1;
                }
            }
            else{
                c = 0;
            }
            if (h > 100){
                h = -1;
                break;
            }
        }
        cout << h << endl;
    }
    
    return 0;
}