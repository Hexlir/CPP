// D. Sel Hitam
// Batas waktu per tes4 detik
// Batas memori per pengujian256 megabyte
// Masukkaninput standar
// Output standar output
// Anda bermain dengan strip yang sangat panjang yang terdiri dari 1018
//  Sel putih, diberi nomor dari kiri ke kanan sebagai 0
// , 1
// , 2
//  dan sebagainya. Anda mengontrol pointer khusus yang awalnya dalam sel 0
// . Juga, Anda memiliki tombol "Shift" yang dapat Anda tekan dan tahan.

// Dalam satu gerakan, Anda dapat melakukan salah satu dari tiga tindakan:

// Memindahkan penunjuk ke kanan (dari sel x
//  ke sel x+1
// );
// tekan dan tahan tombol "Shift";
// lepaskan tombol "Shift": saat Anda melepaskan "Shift", semua sel yang dikunjungi saat "Shift" ditekan berwarna hitam.
// (Tentu saja, Anda tidak dapat menekan Shift jika Anda sudah menahannya. Demikian pula, Anda tidak dapat melepaskan Shift jika Anda belum menekannya.)
// Tujuan Anda adalah mewarnai setidaknya k
//  sel, tetapi ada batasan: Anda diberikan n
//  Segmen [lsaya,rsaya]
//  — Anda dapat mewarnai sel hanya di dalam segmen ini, yaitu Anda dapat mewarnai sel x
//  jika dan hanya jika lsaya≤x≤rsaya
//  untuk beberapa saya
// .

// Berapa jumlah minimum gerakan yang perlu Anda lakukan untuk mewarnai setidaknya k
//  sel hitam?

// Masukan
// Baris pertama berisi bilangan bulat tunggal t
//  (1≤t≤104
// ) — jumlah kasus uji.

// Baris pertama dari setiap kasus uji berisi dua bilangan bulat n
//  dan k
//  (1≤n≤2⋅105
// ; 1≤K≤109
// ) — jumlah segmen dan jumlah sel hitam yang diinginkan, masing-masing.

// Baris kedua berisi n
//  Bilangan bulat l1,l2,... ,ln
//  (1≤l1<l2<⋯<ln≤109
// ), dimana lsaya
//  adalah batas kiri saya
// -segmen ke.

// Baris ketiga berisi n
//  Bilangan bulat r1,r2,... ,rn
//  (1≤rsaya≤109
// ; lsaya≤rsaya<li+1−1
// ), dimana rsaya
//  adalah batas kanan saya
// -segmen ke.

// Kendala tambahan pada input:

// setiap sel milik paling banyak satu segmen;
// Jumlah dari n
//  tidak melebihi 2⋅105
// .
// Hasil
// Untuk setiap kasus uji, cetak setidaknya jumlah minimum gerakan untuk diwarnai k
//  sel hitam, atau −1
//  jika tidak mungkin.

// Contoh
// masukanMenyalin
// 4
// 2 3
// 1 3
// 1 4
// 4 20
// 10 13 16 19
// 11 14 17 20
// 2 3
// 1 3
// 1 10
// 2 4
// 99 999999999
// 100 1000000000
// hasilMenyalin
// 8
// -1
// 7
// 1000000004
// Nota
// Dalam kasus uji pertama, salah satu urutan operasi optimal adalah sebagai berikut:

// Berpindah ke kanan: penunjuk berpindah ke dalam sel 1
// ;
// Tekan Shift;
// Shift Rilis: sel 1
//  berwarna hitam;
// Berpindah ke kanan: penunjuk berpindah ke dalam sel 2
// ;
// Berpindah ke kanan: penunjuk berpindah ke dalam sel 3
// ;
// Tekan Shift;
// Berpindah ke kanan: penunjuk berpindah ke dalam sel 4
// ;
// Release Shift: sel 3
//  dan 4
//  berwarna hitam.
// Kami telah mewarnai 3
//  sel dalam 8
//  Bergerak.
// Dalam kasus uji kedua, kita bisa mewarnai paling banyak 8
//  sel, sementara kita membutuhkan 20
//  sel untuk diwarnai.

// Dalam kasus uji ketiga, salah satu urutan operasi optimal adalah sebagai berikut:

// Berpindah ke kanan: penunjuk berpindah ke dalam sel 1
// ;
// Berpindah ke kanan: penunjuk berpindah ke dalam sel 2
// ;
// Berpindah ke kanan: penunjuk berpindah ke dalam sel 3
// ;
// Tekan Shift;
// Berpindah ke kanan: penunjuk berpindah ke dalam sel 4
// ;
// Berpindah ke kanan: penunjuk berpindah ke dalam sel 5
// ;
// Release Shift: sel 3
// , 4
//  dan 5
//  berwarna hitam.
// Kami telah mewarnai 3
//  sel dalam 7
//  Bergerak.


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
        solve();
    }

    return 0;
}