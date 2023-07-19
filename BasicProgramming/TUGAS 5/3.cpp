#include "bits/stdc++.h"

using namespace std;

int main(){

    int power,hasil = 1;

    cout << "Masukkan nilai pangkat : ";
    cin >> power;

    while (power < 0){
        cout << "Nilai pangkat tidak boleh negatif" << endl;
        cout << "Masukkan nilai pangkat : ";
        cin >> power;
    }
    
    for (int i = 1; i <= power; i++){
        hasil *= 2;
    }

    cout << "Hasil dari 2 pangkat " << power << " adalah : " << hasil << endl;
    
}