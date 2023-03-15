// Tugas Praktikum :

// Buat program Stack yang diimplementasikan menggunakan linkedlist untuk memasukkan, 
// menghapus dan membaca data mahasiswa. field dari data mahasiswa bebas.


#include "bits/stdc++.h"

using namespace std;

struct data{
    string nama;
    string nim;
    string jurusan;
    string fakultas;
    string alamat;
    data *next;
    data *prev;
};

class Stack{
    private:
        data *head;
        data *tail;
    public:
        Stack(){
            head = NULL;
            tail = NULL;
        }

        void push(string nama, string nim, string jurusan, string fakultas, string alamat){
            data *newData = new data;
            newData->nama = nama;
            newData->nim = nim;
            newData->jurusan = jurusan;
            newData->fakultas = fakultas;
            newData->alamat = alamat;
            newData->next = NULL;
            newData->prev = NULL;
            if(head == NULL){
                head = newData;
                tail = newData;
            }else{
                newData->next = head;
                head->prev = newData;
                head = newData;
            }
        }

        void pop(){
            if(head == NULL){
                cout << "Stack is empty" << endl;
            }else{
                data *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }

        void print(){
            if(head == NULL){
                cout << "Stack is empty" << endl;
            }else{
                data *temp = head;
                while(temp != NULL){
                    cout << "Nama : " << temp->nama << endl;
                    cout << "NIM : " << temp->nim << endl;
                    cout << "Jurusan : " << temp->jurusan << endl;
                    cout << "Fakultas : " << temp->fakultas << endl;
                    cout << "Alamat : " << temp->alamat << endl;
                    cout << endl;
                    temp = temp->next;
                }
            }
        }
};

int main(){
    Stack stack;
    int pilihan;

    string nama, nim, jurusan, fakultas, alamat;
    do{
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                cout << endl;
                cout << "Nama : ";
                getline(cin>>ws, nama);

                cout << "NIM : ";
                getline(cin>>ws, nim);

                cout << "Jurusan : ";
                getline(cin>>ws, jurusan);

                cout << "Fakultas : ";
                getline(cin>>ws, fakultas);

                cout << "Alamat : ";
                getline(cin>>ws, alamat);

                cout << endl;
                stack.push(nama, nim, jurusan, fakultas, alamat);
                break;
            case 2:
                cout << endl;
                stack.pop();
                break;
            case 3:
                cout << endl;
                stack.print();
                break;
            case 4:
                cout << endl;
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << endl;
                cout << "Pilihan tidak ada" << endl;
                break;
        }
    }while(pilihan != 4);
    return 0;
}