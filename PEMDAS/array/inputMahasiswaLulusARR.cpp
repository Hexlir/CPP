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
}

int main()
{
    fastio();
    ll t;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> t;

    vector<int> lulus;

    for (ll i = 1; i <= t; i++){
        ll temp;
        cout << "Masukkan nilai absen ke-" << i << ": ";
        cin >> temp;
        
        if (temp > 50){
            lulus.pb(i);
        }
    }

    if (lulus.size() > 0){
        cout << "Nomer absen mahasiswa yang lulus: ";

        for (int i = 0; i < lulus.size(); i++){
            cout << lulus[i] << " ";
        }
    }

    else{
        cout << "Tidak ada mahasiswa yang lulus";
    }

    return 0;
}