// Task :
// Buat program untuk menghitung nilai akhir sejumlah mahasiswa berdasar input :
// nilai Partisipasi, nilai tugas, nilai UTS, nilai UAS.
// Perhitungan nilai akhir =
// (nilai Partisipasi x 20% +  nilai tugas x 30% + nilai UTS x 20% + nilai UAS x 30%) /100.

#include "bits/stdc++.h"
#include "iomanip"

using namespace std;

void clearscreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// create a red warning output
class Warning{
    public:
        string what(){
            return "\033[1;31mInput Salah!\033[0m";
        }
};

struct dataMhs{
    string nama;
    int nim;
    int partisipasi;
    int tugas;
    int uts;
    int uas;
    int nilaiAkhir;
};

vector<dataMhs> dataMahasiswa;

bool isNumber(string s){
    for(int i = 0; i < s.length(); i++){
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}

bool isEmpty(string s){
    if(s == ""){
        return true;
    }
    return false;
}

bool isInRange(int n, int min, int max){
    if(n >= min && n <= max){
        return true;
    }
    return false;
}

bool isNimThere(int nim){
    for(int i = 0; i < dataMahasiswa.size(); i++){
        if(dataMahasiswa[i].nim == nim){
            return true;
        }
    }
    return false;
}

void getInputWithSpace(string &s){
    cin.ignore();
    getline(cin, s);
}

void inputData(){
    dataMhs data;
    string temp;

    cout << "Masukkan Nama : ";
    getInputWithSpace(temp);
    while(isEmpty(temp) || !isInRange(temp.length(), 3, 14)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan Nama : ";
        cin >> temp;
    }
    data.nama = temp;

    cout << "Masukkan NIM : ";
    cin >> temp;
    while(isEmpty(temp) || !isNumber(temp) || !isInRange(stoi(temp), 1000, 9999) || isNimThere(stoi(temp))){
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

    cout << "Data Berhasil Ditambahkan" << endl;
    cout << "Tekan Enter Untuk Melanjutkan...";
    cin.ignore();
    cin.get();
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
}


void mergeByNilaiAkhirDesc(vector<dataMhs> &dataMahasiswa, int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<dataMhs> L, R;
    for(i = 0; i < n1; i++){
        L.push_back(dataMahasiswa[left + i]);
    }
    for(j = 0; j < n2; j++){
        R.push_back(dataMahasiswa[mid + 1 + j]);
    }

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        if(L[i].nilaiAkhir >= R[j].nilaiAkhir){
            dataMahasiswa[k] = L[i];
            i++;
        }else{
            dataMahasiswa[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        dataMahasiswa[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        dataMahasiswa[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortByNilaiAkhirDesc(vector<dataMhs> &dataMahasiswa, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSortByNilaiAkhirDesc(dataMahasiswa, left, mid);
        mergeSortByNilaiAkhirDesc(dataMahasiswa, mid + 1, right);

        mergeByNilaiAkhirDesc(dataMahasiswa, left, mid, right);
    }
}

void deleteByNim(vector<dataMhs> &dataMahasiswa){
    string temp;
    cout << "Masukkan NIM : ";
    cin >> temp;
    while(isEmpty(temp) || !isNumber(temp) || !isInRange(stoi(temp), 1000, 9999)){
        Warning w;
        cout << w.what() << endl;
        cout << "Masukkan NIM : ";
        cin >> temp;
    }
    int nim = stoi(temp);
    if(!isNimThere(nim)){
        Warning w;
        cout << "NIM tidak ditemukan" << endl;
        return;
    }
    for(int i = 0; i < dataMahasiswa.size(); i++){
        if(dataMahasiswa[i].nim == nim){
            dataMahasiswa.erase(dataMahasiswa.begin() + i);
        }
    }
}

int mainMenu(){
    cout << "+" << setfill('-') << setw(50) << "+" << endl;
    cout << "|" << setw(10) << " " << "Program Input Nilai Mahasiswa" << setw(10) << " " << "|" << endl;
    cout << "+" << setfill('-') << setw(50) << "+" << endl;
    cout << "|" << setfill(' ') << setw(50) << "|" << endl;
    cout << "|" << setfill(' ') << " 1. Input Data Mahasiswa" << setw(26) << "|" << endl;
    cout << "|" << setfill(' ') << " 2. Tampilkan Data Mahasiswa" << setw(22) << "|" << endl;
    cout << "|" << setfill(' ') << " 3. Delete Data Mahasiswa" << setw(25) << "|" << endl;
    cout << "|" << setfill(' ') << " 4. Exit" << setw(42) << "|" << endl;
    cout << "+" << setfill('-') << setw(50) << "+" << endl;
    cout << "Pilih Menu : ";
    int menu;
    cin >> menu;
    return menu;
}

int main(){
    int menu;
    do{
        clearscreen();
        menu = mainMenu();
        switch(menu){
            case 1:
                clearscreen();
                inputData();
                break;
            case 2:
                clearscreen();
                mergeSortByNilaiAkhirDesc(dataMahasiswa, 0, dataMahasiswa.size() - 1);
                tableData(dataMahasiswa);
                cout << "Tekan Enter Untuk Kembali Ke Menu Utama" << endl;
                cin.get();
                cin.get();
                break;
            case 3:
                clearscreen();
                tableData(dataMahasiswa);
                deleteByNim(dataMahasiswa);
                cout << "Tekan Enter Untuk Kembali Ke Menu Utama" << endl;
                cin.get();
                cin.get();
                break;
            case 4:
                clearscreen();
                cout << "Terima Kasih Telah Menggunakan Program Ini" << endl;
                break;
            default:
                clearscreen();
                cout << "Menu Tidak Tersedia" << endl;
                break;
        }
    }while(menu != 4);
    return 0;
}