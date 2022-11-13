// Deskripsi Masalah
//     Suatu hari,
//     Tono berlibur ke daerah ngalam.Pada saat itu ia mendengar
//             kata -
//         kata yang setengah asing dan saat didengarkan lebih jelas ternyata katakata yang diucapkan oleh warga ngalam adalah bahasa Indonesia yang dibalik
//             seperti bakso menjadi osbak.Tono sedikit kesusahan untuk berbicara dengan
//                 warga ngalam karena harus membalik kata terlebih dahulu dengan syarat ‘ng’
//                     dan ‘dh’ merupakan satu karakter,
//     jadi bantulah tono untuk menjadikan bahasa
//         Indonesia biasa menjadi bahasa ngalam.Format Masukan
//             Sebuah kalimat.Batasan Masukan
//                 Panjang dari kalimat kurang dari 10.000 Format keluaran
//                     Bahasa ngalam
//                         Contoh Masukan 1 Kabupaten malang
//                             Contoh Keluaran 1 netapubaK ngalam
//                                 Penjelasan Keluaran 1 Membalik tiap kata lalu di outputkan dalam bentuk kalimat

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
    string s, temp;
    getline(cin,s);
    ll n=s.length();
    stringstream ss(s);
    vector<string> words;

    while (getline(ss, tmp, ' '))
    {
        words.push_back(tmp);
    }

    for (int i = 0; i < words.size(); i++)
    {
        reverse(words[i].begin(), words[i].end());

        if (words[i][0] == 'n' && words[i][1] == 'g')
        {
            words[i][0] = 'g';
            words[i][1] = 'n';
        }
        else if (words[i][0] == 'd' && words[i][1] == 'h')
        {
            words[i][0] = 'h';
            words[i][1] = 'd';
        }
        else{
        cout << words[i] << " ";
        }
    }
    // for(ll i=n;i >= 0;i--){
    //     if ((a[i] == 'g' || a[i] == 'G') && (a[i - 1] == 'n' || a[i - 1] == 'N')){
    //         cout << "ng";
    //     }
    //     else {
    //         cout << a[i];
    //     }
    // }

    cout << endl;

    return 0;
}