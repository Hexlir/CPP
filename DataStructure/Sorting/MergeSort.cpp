// Buat program untuk menghitung nilai akhir sejumlah mahasiswa berdasar input :
// nilai Partisipasi, nilai tugas, nilai UTS, nilai UAS.
// Perhitungan nilai akhir =
// (nilai Partisipasi x 20% +  nilai tugas x 30% + nilai UTS x 20% + nilai UAS x 30%) /100.

#include "iostream"
#include "iomanip"
#include "string"
#include "vector"

#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

using namespace std;

struct data_mahasiswa {
    string nama;
    int nilai_partisipasi;
    int nilai_tugas;
    int nilai_uts;
    int nilai_uas;
    float nilai_akhir;
};

string input() {
    string temp;
    getline(cin, temp);
    return temp;
}

// create a merge sort by nilai akhir

void merge(vector<data_mahasiswa> &data, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<data_mahasiswa> L(n1), R(n2);

    for (i = 0; i < n1; i++) {
        L[i] = data[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = data[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i].nilai_akhir <= R[j].nilai_akhir) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<data_mahasiswa> &data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

int main(){
    int n;
    vector<data_mahasiswa> data;

    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        data_mahasiswa temp;
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << " : ";
        cin >> temp.nama;
        cout << "Masukkan nilai partisipasi : ";
        cin >> temp.nilai_partisipasi;
        cout << "Masukkan nilai tugas : ";
        cin >> temp.nilai_tugas;
        cout << "Masukkan nilai UTS : ";
        cin >> temp.nilai_uts;
        cout << "Masukkan nilai UAS : ";
        cin >> temp.nilai_uas;
        temp.nilai_akhir = (temp.nilai_partisipasi * 20 / 100) + (temp.nilai_tugas * 30 / 100) + (temp.nilai_uts * 20 / 100) + (temp.nilai_uas * 30 / 100);
        data.pb(temp);
    }

    mergeSort(data, 0, n - 1);

    cout << "Hasil pengurutan nilai akhir : " << endl;
    cout << "Nama\t\tNilai Akhir" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i].nama << "\t\t" << data[i].nilai_akhir << endl;
    }

    return 0;
}