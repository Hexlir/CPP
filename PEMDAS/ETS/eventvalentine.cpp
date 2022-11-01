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
    ll a,pa, harga, totala, totalpa;
    float d;
    cin >> a >> pa >> d >> harga;

    for (int i = 1; i >= 0; i++){
        //basecase
        if ((a >= harga) && (pa >= harga)){
            break;
        }
        //proses
        if (a < harga){
            a *= i;
            if(a >= harga){
                totala = i;
            }
        }
        if (pa < harga){
            pa *= i;
            if(pa >= harga){
                totalpa = i;
            }
        }
    }
    d *= harga;

    cout << totala << endl;
    cout << totalpa << endl;
    cout << d << endl;
    return 0;
}