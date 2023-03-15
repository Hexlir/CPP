#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct dataKtp {
    char nama[50];
    char alamat[50];
    char golongandarah[2];
    dataKtp *next, *prev;
};
dataKtp *awal=NULL,*akhir=NULL,*bantu,*baru,*hapus;

void inputDatadepan(){
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama\t\t: ";
    cin >> baru->nama;
    cout << "Alamat\t\t: ";
    cin >> baru->alamat;
    cout << "Golongan darah  : ";
    cin >> baru->golongandarah;
    if (awal == NULL){
        awal = akhir = baru;
    }
    else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
    system ("cls");
}

void inputDatabelakang(){
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama\t\t: ";
    cin >> baru->nama;
    cout << "Alamat\t\t: ";
    cin >> baru->alamat;
    cout << "Golongan darah  : ";
    cin >> baru->golongandarah;
    if (awal == NULL){
        awal = akhir = baru;
    }
    else {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }
    system ("cls");
}

void inputDataPosisi(int posisi){
    int i;
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama\t\t: ";
    cin >> baru->nama;
    cout << "Alamat\t\t: ";
    cin >> baru->alamat;
    cout << "Golongan darah  : ";
    cin >> baru->golongandarah;
    if (awal == NULL){
        awal = akhir = baru;
    }
    else {
        bantu = awal;
        for (i=1; i<posisi-1; i++){
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        baru->prev = bantu;
        bantu->next = baru;
        baru->next->prev = baru;
    }
    system ("cls");
}

void hapusDatadepan(){
    if(awal->next == NULL){
        awal=akhir=NULL;
        cout << "Data sudah kosong";
    }else{
        hapus = awal;
        awal = awal->next;
        awal->prev = NULL;
        delete hapus;
    }
}

void hapusDatabelakang(){
    if(awal->next == NULL){
        awal=akhir=NULL;
        cout << "Data sudah kosong";
    }else{
        hapus = akhir;
        akhir = akhir->prev;
        akhir->next = NULL;
        delete hapus;
    }
}

void hapusDataPosisi(int posisi){
    int i;
    if(awal->next == NULL){
        awal=akhir=NULL;
        cout << "Data sudah kosong";
    }else{
        bantu = awal;
        for (i=1; i<posisi-1; i++){
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        hapus->next->prev = bantu;
        delete hapus;
    }
}

void outputData (){
    bantu=awal;
    while (bantu != NULL){
        cout << "Nama\t\t: "<<bantu->nama<<endl;
        cout << "Alamat\t\t: "<<bantu->alamat<<endl;
        cout << "Golongan darah  : "<<bantu->golongandarah<<endl;
        bantu = bantu->next;
    }
}

int main()
{
    int pilih, posisi;
    do{
        cout << "1. Input data depan" << endl;
        cout << "2. Input data belakang" << endl;
        cout << "3. Input data posisi" << endl;
        cout << "4. Hapus data depan" << endl;
        cout << "5. Hapus data belakang" << endl;
        cout << "6. Hapus data posisi" << endl;
        cout << "7. Tampilkan data" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih){
            case 1:
                inputDatadepan();
                break;
            case 2:
                inputDatabelakang();
                break;
            case 3:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                inputDataPosisi(posisi);
                break;
            case 4:
                hapusDatadepan();
                break;
            case 5:
                hapusDatabelakang();
                break;
            case 6:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                hapusDataPosisi(posisi);
                break;
            case 7:
                outputData();
                break;
            case 8:
                cout << "Terima kasih";
                break;
            default:
                cout << "Pilihan tidak ada";
                break;
        }
        cout << endl;
        system("pause");
        system("cls");
    }while(pilih != 8);
    return 0;
}