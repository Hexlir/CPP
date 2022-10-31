/*Gema dan Astik sangat suka sekali bermain angka. Dalam permainan ini Gema akan memberikan
dua bilangan bulat 𝐴 dan 𝐵 kepada Astik untuk kemudian mencari banyaknya bilangan bulat antara
2 sampai 𝐵 yang merupakan Bilangan Mandiri. Bilangan Mandiri dari (𝐴,𝐵) didefinisikan sebagai
bilangan bulat 𝑏𝑖
(2 ≤ 𝑏𝑖 ≤ 𝐵) yang bukan merupakan kelipatan dari salah satu atau lebih
bilangan bulat 𝑎𝑖
(2 ≤ 𝑎𝑖 ≤ 𝐴). Sebagai contoh, jika diketahui 𝐴 = 2 dan 𝐵 = 8, maka bilangan
bulat antara 2 sampai 8 yang merupakan kelipatan dari 2 adalah 2, 4, 6, dan 8. Sehingga yang
merupakan Bilangan Mandiri dari (2, 8) adalah 3, 5, dan 7 yang ada sebanyak 3.
Tugas Anda adalah membantu Astik dalam mencari Bilangan Mandiri dari rentang yang diberikan
oleh Gema

Baris pertama berisi sebuah bilangan bulat positif 𝑁 (1 ≤ 𝑁 ≤ 100) yang menunjukkan
banyaknya pasangan 𝐴 dan 𝐵 yang disebutkan oleh Gema. 𝑁 baris berikutnya masing-masing
berisi dua bilangan bulat 𝐴 dan 𝐵 yang dipisahkan oleh spasi dengan ketentuan 2 ≤ 𝐴 ≤ 130
dan 2 ≤ 𝐵 ≤ 1015
. Untuk setiap pasangan (𝐴,𝐵), keluarkan banyaknya Bilangan Mandiri.
*/

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
    ll t, a , b;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> a >> b;
        ll ans = 0;
        for (ll j = 2; j <= b; j++)
        {
            ll temp = 0;
            for (ll k = 2; k <= a; k++)
            {
                if (j % k == 0)
                {
                    temp = 1;
                    break;
                }
            }
            if (temp == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}