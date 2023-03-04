#include "bits/stdc++.h"

using namespace std;

int main(){
    // First Problem :
    // Struct with NIM, nama, gender, alamat.
    struct Mhs{
        short NIM;
        string nama;
        char gender;
        string alamat;
    }
    // Second Problem;
    // Struct with NamaMatkul, nilaiTugas, nilaiUTS, nilaiUAS.
    struct Matkul{
        string NamaMatkul;
        short nilaiTugas;
        short nilaiUTS;
        short nilaiUAS;
    }
    // Third Problem;
    // Create a struct that have identitiy of problem number 1, and 'nilai' from problem number 2.
    struct Summary{
        Mhs Data;
        Matkul Matakuliah;
    }

    // access the summary
    Summary summary;
    summary.Data.NIM = 123;
    summary.Data.nama = "John Doe";
    summary.Data
}