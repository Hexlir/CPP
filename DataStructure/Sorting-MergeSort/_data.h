#pragma once

#include "bits/stdc++.h"
#include "betterIO.h"
#include "iomanip"

using namespace std;


void inputData(vector<dataMhs> &dataMahasiswa){
    dataMhs data;
    string temp;

    cout << "Masukkan Nama : ";
    getInputWithSpace(temp);
    while(isEmpty(temp)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan Nama : ";
        cin >> temp;
    }
    data.nama = temp;

    cout << "Masukkan NIM : ";
    cin >> temp;
    while(isEmpty(temp) || !isNumber(temp) || !isInRange(stoi(temp), 1000, 9999)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan NIM : ";
        cin >> temp;
    }
    data.nim = stoi(temp);

    cout << "Masukkan Nilai Partisipasi : ";
    cin >> temp;
    while(isEmpty(temp) || !isNumber(temp) || !isInRange(stoi(temp), 0, 100)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan Nilai Partisipasi : ";
        cin >> temp;
    }
    data.partisipasi = stoi(temp);

    cout << "Masukkan Nilai Tugas : ";
    cin >> temp;
    while(isEmpty(temp) || !isNumber(temp) || !isInRange(stoi(temp), 0, 100)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan Nilai Tugas : ";
        cin >> temp;
    }
    data.tugas = stoi(temp);

    cout << "Masukkan Nilai UTS : ";
    cin >> temp;
    while(isEmpty(temp) || !isNumber(temp) || !isInRange(stoi(temp), 0, 100)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan Nilai UTS : ";
        cin >> temp;
    }
    data.uts = stoi(temp);

    cout << "Masukkan Nilai UAS : ";
    cin >> temp;
    while(isEmpty(temp) || !isNumber(temp) || !isInRange(stoi(temp), 0, 100)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan Nilai UAS : ";
        cin >> temp;
    }
    data.uas = stoi(temp);

    data.nilaiAkhir = (data.partisipasi * 20 / 100) + (data.tugas * 30 / 100) + (data.uts * 20 / 100) + (data.uas * 30 / 100);
    dataMahasiswa.push_back(data);
}

void tableData(vector<dataMhs> dataMahasiswa){
    cout << "+" << setfill('-') << setw(115) << "+" << endl;
    cout << "|" << setfill(' ') << setw(5) << "No" << setw(5) << "|" << setw(13) << "Nama" << setw(10) << "|" << setw(7) << "NIM" << setw(5) << "|" << setw(15) << "Partisipasi" << setw(5) << "|" << setw(8) << "Tugas" << setw(4) << "|" << setw(6) << "UTS" << setw(5) << "|" << setw(6) << "UAS" << setw(5) << "|" << setw(14) << "Nilai Akhir" << setw(2) << "|" << endl;
    cout << "+" << setfill('-') << setw(115) << "+" << endl;
    for(int i = 0; i < dataMahasiswa.size(); i++){
        cout << "|" << setfill(' ') << setw(5) << i + 1 << setw(5) << "|" << setw(13) 
        << dataMahasiswa[i].nama << setw(10) << "|" << setw(7) << dataMahasiswa[i].nim << setw(5) << "|" << setw(15) 
        << dataMahasiswa[i].partisipasi << setw(5) << "|" << setw(8) << dataMahasiswa[i].tugas << setw(4) << "|" << setw(6) 
        << dataMahasiswa[i].uts << setw(5) << "|" << setw(6) << dataMahasiswa[i].uas << setw(5) << "|" << setw(14) 
        << dataMahasiswa[i].nilaiAkhir << setw(2) << "|" << endl;
    }
    cout << "+" << setfill('-') << setw(115) << "+" << endl;
    cout << "Tekan Enter Untuk Kembali Ke Menu Utama" << endl;
    cin.get();
    cin.get();
}


void mergesortByNilaiAkhir(vector<dataMhs> &dataMahasiswa, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergesortByNilaiAkhir(dataMahasiswa, left, mid);
        mergesortByNilaiAkhir(dataMahasiswa, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int k = 0;
        vector<dataMhs> temp;
        while(i <= mid && j <= right){
            if(dataMahasiswa[i].nilaiAkhir < dataMahasiswa[j].nilaiAkhir){
                temp.push_back(dataMahasiswa[i]);
                i++;
            }else{
                temp.push_back(dataMahasiswa[j]);
                j++;
            }
            k++;
        }
        while(i <= mid){
            temp.push_back(dataMahasiswa[i]);
            i++;
            k++;
        }
        while(j <= right){
            temp.push_back(dataMahasiswa[j]);
            j++;
            k++;
        }
        for(int i = left; i <= right; i++){
            dataMahasiswa[i] = temp[i - left];
        }
    }
}

void mergesortByNim(vector<dataMhs> &dataMahasiswa, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergesortByNim(dataMahasiswa, left, mid);
        mergesortByNim(dataMahasiswa, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int k = 0;
        vector<dataMhs> temp;
        while(i <= mid && j <= right){
            if(dataMahasiswa[i].nim < dataMahasiswa[j].nim){
                temp.push_back(dataMahasiswa[i]);
                i++;
            }else{
                temp.push_back(dataMahasiswa[j]);
                j++;
            }
            k++;
        }
        while(i <= mid){
            temp.push_back(dataMahasiswa[i]);
            i++;
            k++;
        }
        while(j <= right){
            temp.push_back(dataMahasiswa[j]);
            j++;
            k++;
        }
        for(int i = left; i <= right; i++){
            dataMahasiswa[i] = temp[i - left];
        }
    }
}

void mergesortByNama(vector<dataMhs> &dataMahasiswa, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergesortByNama(dataMahasiswa, left, mid);
        mergesortByNama(dataMahasiswa, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int k = 0;
        vector<dataMhs> temp;
        while(i <= mid && j <= right){
            if(dataMahasiswa[i].nama < dataMahasiswa[j].nama){
                temp.push_back(dataMahasiswa[i]);
                i++;
            }else{
                temp.push_back(dataMahasiswa[j]);
                j++;
            }
            k++;
        }
        while(i <= mid){
            temp.push_back(dataMahasiswa[i]);
            i++;
            k++;
        }
        while(j <= right){
            temp.push_back(dataMahasiswa[j]);
            j++;
            k++;
        }
        for(int i = left; i <= right; i++){
            dataMahasiswa[i] = temp[i - left];
        }
    }
}

int mainMenu(){
    cout << "+" << setfill('-') << setw(50) << "+" << endl;
    cout << "|" << setw(10) << " " << "Program Input Nilai Mahasiswa" << setw(10) << " " << "|" << endl;
    cout << "+" << setfill('-') << setw(50) << "+" << endl;
    cout << "|" << setfill(' ') << setw(50) << "|" << endl;
    cout << "|" << setfill(' ') << " 1. Input Nilai Mahasiswa" << setw(25) << "|" << endl;
    cout << "|" << setfill(' ') << " 2. Lihat Nilai Mahasiswa" << setw(25) << "|" << endl;
    cout << "|" << setfill(' ') << " 3. Keluar" << setw(40) << "|" << endl;
    cout << "+" << setfill('-') << setw(50) << "+" << endl;
    cout << "Pilih Menu : ";
    int menu;
    cin >> menu;
    return menu;
}