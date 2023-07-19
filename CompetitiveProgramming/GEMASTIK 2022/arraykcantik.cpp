/*Sebuah array dikatakan K-cantik apabila setiap anggotanya muncul setidaknya K kali di dalam
array tersebut. Sebagai contoh, array [2, 0, 4, 0, 4, 2, 2] merupakan array 2-cantik, karena setiap
anggotanya muncul setidaknya dua kali (0 dan 4 muncul dua kali, dan 2 muncul tiga kali). Namun,
array tersebut bukan array 3-cantik, karena 0 dan 4 muncul kurang dari tiga kali.
Anda diberikan sebuah array A dengan panjang N. Anda dapat melakukan satu jenis operasi:
mengubah salah satu anggota menjadi bilangan bulat apapun (dengan kata lain, membuat 𝐴[𝑖] =
𝑥 untuk 1 ≤ 𝑖 ≤ 𝑁 dan x berupa bilangan bulat yang Anda pilih). Anda dapat melakukan operasi
ini berkali-kali. Tugas Anda adalah mencari tahu banyaknya operasi minimum untuk membuat
array A menjadi array K-cantik, untuk setiap 1 ≤ 𝐾 ≤ 𝑁.
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
    ll n;
    cin >> n;

    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    return 0;
}