// BRIEF

// Buatlah program yang mendeklarasikan sekaligus menginisialisasi sebuah array kata1[], 
// kemudian copy-lah isi array kata1[] tsb ke dalam array kata2[], 
// selanjutnya tampilkan isi kedua array tsb ke layar!

#include "bits/stdc++.h"

using namespace std;

int main(){
    cout << "PROGRAM COPY ARRAY" << endl;
    cout << "==================" << endl;

    char kata1[] = "Muklis suka makan bakso";
    char kata2[100];

    strcpy(kata2, kata1);

    cout << "Kata 1 : " << kata1 << endl;
    cout << "Kata 2 : " << kata2 << endl;
    cout << "==================" << endl;

    return 0;
}

