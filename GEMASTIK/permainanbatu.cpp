/*Terdapat N buah petak, dinomori dari 1 sampai N, dari kiri ke kanan. Awalnya, terdapat M buah
batu pada masing-masing petak dari petak 1 sampai petak K.
Dua pemain akan bermain dengan batu-batu tersebut secara bergiliran. Pada gilirannya, pemain
akan mengambil sebuah batu dari petak mana pun, kemudian pindah batu tersebut ke petak mana
pun di kanannya. Yang tidak bisa melakukan gerakan pada gilirannya (semua batu berada di petak
N) dinyatakan kalah, dan pemain lawannya dinyatakan menang. Apabila keduanya bermain
optimal, siapa yang menang?

Satu baris berisi tiga buah bilangan bulat N (1 ≤ 𝑁 ≤ 10
12), K (1 ≤ 𝐾 < 𝑁), dan M
(1 ≤ 𝑀 ≤ 10
12).
Format keluaran adalah sebagai berikut:
Keluarkan satu baris yang berisi “Pertama” (tanpa tanda kutip) apabila pemain yang melakukan
gerakan pertama kali menang, atau “Kedua” (tanpa tanda kutip) apabila sebaliknya*/

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
    ll n, k, m;
    cin >> n >> k >> m;
    if (n % 2 == 0)
    {
        if (m % 2 == 0)
        {
            cout << "Pertama" << endl;
        }
        else
        {
            cout << "Kedua" << endl;
        }
    }
    else
    {
        if (m % 2 == 0)
        {
            cout << "Kedua" << endl;
        }
        else
        {
            cout << "Pertama" << endl;
        }
    }

    return 0;
}