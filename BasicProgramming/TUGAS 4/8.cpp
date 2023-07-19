
#include "bits/stdc++.h"

using namespace std;

int main(){
    float nilaiTugas, nilaiUTS, nilaiUAS, nilaiPartisipasi, nilaiAkhir;

    cout << "Masukkan nilai tugas dengan satuan puluhan : ";
    cin >> nilaiTugas;

    cout << "Masukkan nilai UTS dengan satuan puluhan : ";
    cin >> nilaiUTS;

    cout << "Masukkan nilai UAS dengan satuan puluhan : ";
    cin >> nilaiUAS;

    cout << "Masukkan nilai partisipasi dengan satuan puluhan : ";
    cin >> nilaiPartisipasi;

    nilaiAkhir = (nilaiTugas * 0.2) + (nilaiUTS * 0.3) + (nilaiUAS * 0.4) + (nilaiPartisipasi * 0.1);

    if (nilaiAkhir >= 90 && nilaiAkhir <= 100){
        cout << "Nilai Akhir : " << nilaiAkhir << endl;
        cout << "Grade : A" << endl;
    }

    else if (nilaiAkhir >= 80 && nilaiAkhir < 90){
        cout << "Nilai Akhir : " << nilaiAkhir << endl;
        cout << "Grade : B" << endl;
    }

    else if (nilaiAkhir >= 70 && nilaiAkhir < 80){
        cout << "Nilai Akhir : " << nilaiAkhir << endl;
        cout << "Grade : C" << endl;
    }

    else if (nilaiAkhir >= 60 && nilaiAkhir < 70){
        cout << "Nilai Akhir : " << nilaiAkhir << endl;
        cout << "Grade : D" << endl;
    }

    else if (nilaiAkhir >= 0 && nilaiAkhir < 60){
        cout << "Nilai Akhir : " << nilaiAkhir << endl;
        cout << "Grade : F" << endl;
    }

    else {
        cout << "Nilai tidak valid" << endl;
    }
}