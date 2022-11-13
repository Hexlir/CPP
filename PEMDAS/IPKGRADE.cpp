//
// Created by el on 04/10/2022.
//
#include "bits/stdc++.h"

using namespace std;

int main(){
    float IPK;

    cout << "Masukkan IPK anda : ";
    cin >> IPK;

    if (IPK >= 3.5 && IPK <= 4){
        cout << "Sempurna" << endl;
    }

    else if (IPK >= 3.0 && IPK < 3.5){
        cout << "Sangat Baik" << endl;
    }

    else if (IPK >= 2.0 && IPK < 3.0){
        cout << "Baik" << endl;
    }

    else if (IPK >= 1.0 && IPK < 2.0){
        cout << "Mengulang" << endl;
    }

    else if (IPK >= 0 && IPK < 1.0){
        cout << "Tidak Lulus" << endl;
    }

    else {
        cout << "IPK tidak valid" << endl;
    }

}