#include "bits/stdc++.h"  
using namespace std;

int main(){
    int waktu, jam, menit, detik;

    cin >> waktu;

    jam = waktu / 3600;
    menit = (waktu % 3600) / 60;
    detik = (waktu % 3600) % 60;

    cout << jam << endl << menit << endl << detik << endl;
}