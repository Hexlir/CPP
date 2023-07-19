/*Deskripsi Masalah
Anda diberikan suatu bilangan bulat positif N. Anda diminta untuk membuat suatu bilangan bulat
berbeda yang merupakan anagram dari digit-digit N. Anagram dari suatu bilangan adalah
penyusunan ulang digit-digitnya untuk membentuk bilangan lain. Anagram yang Anda bentuk
boleh diawali dengan digit 0. Sebagai contoh, beberapa anagram dari 100444 adalah 404104,
044410, 004144, dan 104044. Tugas Anda adalah mencari nilai minimum dari selisih N dan
anagram dari N

Deskripsi Masalah
Anda diberikan suatu bilangan bulat positif N. Anda diminta untuk membuat suatu bilangan bulat
berbeda yang merupakan anagram dari digit-digit N. Anagram dari suatu bilangan adalah
penyusunan ulang digit-digitnya untuk membentuk bilangan lain. Anagram yang Anda bentuk
boleh diawali dengan digit 0. Sebagai contoh, beberapa anagram dari 100444 adalah 404104,
044410, 004144, dan 104044. Tugas Anda adalah mencari nilai minimum dari selisih N dan
anagram dari N.
Format Masukan dan Keluaran
Format masukan adalah sebagai berikut:
Satu baris berisi sebuah bilangan bulat N (10 ≤ 𝑁 ≤ 10
200.000). Dijamin bahwa N tidak diawali
dengan digit 0 dan terdapat setidaknya dua digit berbeda pada N.
Format keluaran adalah sebagai berikut:
Keluarkan satu baris berisi sebuah bilangan bulat yang menyatakan selisih minimum.

Contoh Masukan/Keluaran
Masukan Keluaran
10 9
313 18
Penjelasan Contoh Masukan/Keluaran
Untuk contoh masukan pertama, satu-satunya anagram dari 10 adalah 01, sehingga selisih
minimumnya adalah 9.
Untuk contoh masukan kedua, terdapat dua kemungkinan anagram berbeda dari 313, yaitu 133
dan 331. Dari kedua anagram tersebut, yang memberikan selisih yang lebih kecil adalah 331
dengan selisih 18.*/

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

    ll n;
    cin >> n;

    ll arr[10] = {0};
    ll temp = n;
    while (temp > 0)
    {
        arr[temp % 10]++;
        temp /= 10;
    }

    ll ans = 0;
    for (ll i = 0; i < 10; i++)
    {
        if (arr[i] > 0)
        {
            ans += (i * pow(10, arr[i] - 1));
        }
    }

    cout << n - ans << endl;
    return 0;
}