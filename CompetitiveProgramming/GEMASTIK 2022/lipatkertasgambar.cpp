// Inneo gemar mewarnai pada selembar kertas gambar berbentuk persegi Panjang.Namun di waktu
//     luangnya,
// //     terkadang tanpa disadari dia juga sering melipat kertas gambar yang sudah diwarnainya.Dia selalu melipat kertas pada sisi yang lebih panjang, misalnya jika dia mempunyai kertas gambar berukuran 120 × 80, maka dia akan melipat sisi dengan panjang 120, sehingga ukuran kertasnya menjadi 60×80. Pada berikutnya dia kembali melipat kertas pada sisi dengan panjang 80, sehingga sekarang ukuran kertasnya menjadi 60 × 40. Jika diberikan sebuah kertas gambar dengan ukuran 𝑃 × 𝑄, tugas Anda adalah menentukan ukuran kertas setelah dilakukan pelipatan sebanyak 𝑀 kali.Jika panjang sisi yang akan dilipat adalah bilangan ganjil, maka hasil pelipatan adalah berupa pembulatan ke bawah.Misalnya jika ukuran panjang yang akan dilipat adalah 11, maka setelah lipatan ukuran tersebut menjadi 5.

// Format Masukan dan Keluaran
//         Baris pertama masukan adalah bilangan bulat 𝑁 yang menyatakan banyaknya kertas yang dimiliki
//             oleh Inneo.Kemudian 𝑁 baris berikutnya masing -
//     masing terdiri dari tiga buah bilangan positif 𝑃,
//     𝑄, dan 𝑀.Nilai dari 𝑃, 𝑄, 𝑀, dan 𝑁 adalah bilangan bulat serta masing - masing bernilai antara 1 sampai 10 000. Untuk setiap ukuran kertas yang diberikan, program Anda harus mengeluarkan ukuran kertas setelah dilakukan 𝑀 kali pelipatan dengan ketentuan ukuran yang lebih besar dicetak terlebih dahulu.

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
        ll p, q, m;
        cin >> p >> q >> m;
        ll temp = 0;
        if (p > q)
        {
            temp = p;
            p = q;
            q = temp;
        }
        for (ll j = 1; j <= m; j++)
        {
            if (p % 2 == 0)
            {
                p = p / 2;
            }
            else
            {
                p = p / 2;
            }
            if (q % 2 == 0)
            {
                q = q / 2;
            }
            else
            {
                q = q / 2;
            }
            if (p > q)
            {
                temp = p;
                p = q;
                q = temp;
            }
        }
        cout << q << " " << p << endl;
    }
    return 0;
}