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

    vector<string> lulus;

    for (ll i = 1; i <= t; i++){
        string temp;
        ll temp1;

        cout << endl;

        cout << "Masukkan nama mahasiswa absen ke-" << i << ": ";
        cin >> temp;
        
        cout << "Masukkan nilai mahasiswa " << temp << ": ";
        cin >> temp1;

        if (temp1 > 50){
            lulus.pb(temp);
        }
    }

    cout << endl;

    if (lulus.size() > 0){
        cout << "Nama mahasiswa yang lulus: ";

        for (int i = 0; i < lulus.size(); i++){
            cout << lulus[i] << " ";
        }
    }

    else{
        cout << "Tidak ada mahasiswa yang lulus";
    }
    return 0;
}