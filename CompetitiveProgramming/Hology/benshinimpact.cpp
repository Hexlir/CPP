// Deskripsi Masalah
//     Benshin Impact merupakan game RPG yang populer di kalangan Gen Z.Noverdi pun ikut bermain game ini.Seperti game RPG pada umumnya,
//     di game ini memiliki sebuah monster yang bernama slime.Setiap a
//         menit,
//     sebuah slime akan melahirkan b slime lainnya.Slime yang baru
//         lahir haruslah menunggu c menit sebelum menjadi dewasa dan dapat
//             melahirkan slime lainnya.Dikarenakan Noverdi merupakan pemain yang
//                 tangguh dan menyukai tantangan,
//     maka ia akan menunggu selama d
//         menit agar slime yang ada menjadi banyak.Berapa banyak slime yang
//             akan dilawan Noverdi.Dimana di menit 1 terdapat e slime.

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
    ll a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;

    ll ans = 0;
    ll x = 0;
    ll y = 0;
    ll z = 0;

    for (int i = 1; i <= a; i++)
    {
        if (i % c == 0)
        {
            x += b;
        }
        if (i % d == 0)
        {
            y += x;
        }
        if (i % e == 0)
        {
            z += y;
        }
    }

    cout << z << endl;

    return 0;
}