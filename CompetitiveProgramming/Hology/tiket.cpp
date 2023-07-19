// Deskripsi Masalah
//         Dalam rangka memperingati hari kemerdekaan Republik Indonesia yang ke -
//     77,
//     diadakan sebuah festival yang terdiri dari banyak acara dan juga lomba.Untuk
//         memasuki festival ini diperlukan sebuah tiket yang sedikit unik,
//     tiket yang
//         menjadi prioritas dilihat dari angka satuannya terlebih dahulu baru diikuti
//             dengan besaran angkanya.Terlihat bahwa penjaga festival sedikit kebingungan,
//     sehingga sebagai anak yang baik hati bantulah penjaga tiket untuk mengurutkan
//         siapa yang boleh masuk terlebih dahulu.Format Masukan
//             Baris pertama berisi sebuah bilangan bulat N.N baris berikutnya berisi nama,
//     harga tiket(L), dan no tiket(M)
// yang
//     dipisahkan oleh spasi.Batasan Masukan
// • (0 ≤ 𝑁 ≤ 20000)
// • (0 ≤ 𝐿 ≤ 1000)
// • (0 ≤ 𝑀 ≤ 106)
//         Format keluaran
//     N baris yang setiap barisnya berisi nama pemilik tiket berdasarkan prioritas
//     disertai dengan harga tiket dikali angka satuan no tiket.

// Contoh Masukan 5 Tini 120, 76 188 Wini 245 4 Boli 986 8 bobi 897 78 biti 777, 8 1111 Contoh Keluaran 1. biti : 777.8 2. Wini : 980.0 3. Boli : 7888.0 4. bobi : 7176.0 5. Tini : 966.08

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
    cin >> t;

    for(ll i=0;i<t;i++){
        string nama;
        ll harga,no;
        cin>>nama>>harga>>no;
        ll satuan = no%10;
        ll hasil = harga*satuan;
        cout<<i+1<<". "<<nama<<" : "<<hasil<<endl;
    }
    
    return 0;
}