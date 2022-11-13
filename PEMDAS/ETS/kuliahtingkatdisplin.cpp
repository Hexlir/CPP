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
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        int n, batas, penentu = 0;
        float per;

        cin >> n >> per;
        cin >> batas;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x>= batas){
                penentu++;
            }
        }
            int a = n * per;
            cout << penentu << endl;
            cout << a << endl;

            if (penentu >= a)
            {
                cout << "Kelas dilanjutkan" << endl;
            }
            else
            {
                cout << "Kelas dihentikan" << endl;
            }
        }
}