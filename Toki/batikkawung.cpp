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
    short k,a;
    char c;
    cin>>k >> c >> a;

    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            if (i == 0 || i == k-1 || j == 0 || j == k-1){
                cout << a;
            }
            else{
                cout << c;
            }
        }
        cout << endl;
    }

    return 0;
}