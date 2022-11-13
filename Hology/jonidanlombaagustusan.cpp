// Deskripsi Masalah
//     Di pagi hari yang cerah,
//     Joni Yespapa bersiap untuk mengikuti lomba agustusan
//             di desanya.Ketika Joni hendak keluar rumah tiba -
//         tiba dia menemukan kardus
//             di depan pintu rumahnya yang berisi 𝑛 integer 𝑎1,
//     𝑎2, … 𝑎𝑛dan sebuah
//                 integer 𝑘.Joni baru ingat itu adalah tugas dari Professor Drake untuk mencari
//                     nilai maksimal dari 𝑖.𝑗 − 𝑘.(𝑎𝑖 | 𝑎𝑗) dari semua pasangan(𝑖, 𝑗) dimana 1 ≤ 𝑖 < 𝑗 ≤ 𝑛.Disini,
//     tanda | adalah operator bitwise OR.Supaya Joni bisa tetap
//             bisa mengikuti lomba agustusan,
//     dia harus segera menyelesaikan tugas dari
//     Professor yang deadlinennya harusnya selesai semalam.Bantu dia agar bisa
//     tetep bergabung dengan keseruan lomba agustusan !
// Format Masukan
// Baris pertama adalah t — jumlah test case.
// Baris pertama dari setiap test case berisi 2 integer 𝑛 dan 𝑘.
// Baris kedua dari setiap test case berisi 𝑛 integer a1, a2, … , an.
// Batasan Masukan
// • (1 ≤ 𝑡 ≤ 10000)
// • (2 ≤ 𝑛 ≤ 105
// )
// • (1 ≤ 𝑘 ≤ 𝑚𝑖𝑛(𝑛, 100))
// • (0 ≤ 𝑎𝑖 ≤ 𝑛)
// Format keluaran
// Setiap test case, print satu integer — nilai maksimal yang mungkin dari i ⋅ j −
// k ⋅ (ai
// |aj

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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        ll maks = 0;
        for (ll j = 0; j < n; j++)
        {
            for (ll l = j + 1; l < n; l++)
            {
                maks = max(maks, (j + 1) * (l + 1) - k * (a[j] | a[l]));

                cout << i << " " << j << " " << k << " " << a[j] << " " << a[l] << " " << maks << endl;
            }
        }
        cout << maks << endl;
    }

    return 0;
}