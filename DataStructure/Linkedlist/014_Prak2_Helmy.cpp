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

class DoubleLinkedlist{
    private:
        data *head;
        data *tail;
    public:
        DoubleLinkedlist(){
            head = NULL;
            tail = NULL;
        }

        void insertFront(string nama, string nim, string jurusan, string fakultas, string alamat){
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

        void insertBack(string nama, string nim, string jurusan, string fakultas, string alamat){
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
                newData->prev = tail;
                tail->next = newData;
                tail = newData;
            }
        }

        void insertAt(string nama, string nim, string jurusan, string fakultas, string alamat, int pos){
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
                data *temp = head;
                for(int i = 0; i < pos-1; i++){
                    temp = temp->next;
                }
                newData->next = temp->next;
                newData->prev = temp;
                temp->next->prev = newData;
                temp->next = newData;
            }
        }

        void deleteFront(){
            if(head == NULL){
                cout << "List Kosong" << endl;
            }else{
                data *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }

        void deleteBack(){
            if(head == NULL){
                cout << "List Kosong" << endl;
            }else{
                data *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }

        void deleteAt(int pos){
            if(head == NULL){
                cout << "List Kosong" << endl;
            }else{
                data *temp = head;
                for(int i = 0; i < pos-1; i++){
                    temp = temp->next;
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
        }

        void search(string nama){
            if(head == NULL){
                cout << "List Kosong" << endl;
            }else{
                data *temp = head;
                while(temp != NULL){
                    if(temp->nama == nama){
                        cout << "Nama : " << temp->nama << endl;
                        cout << "NIM : " << temp->nim << endl;
                        cout << "Jurusan : " << temp->jurusan << endl;
                        cout << "Fakultas : " << temp->fakultas << endl;
                        cout << "Alamat : " << temp->alamat << endl;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }

        void display(){
            if(head == NULL){
                cout << "List Kosong" << endl;
            }else{
                data *temp = head;
                cout << "Nama \t NIM \t Jurusan \t Fakultas \t Alamat" << endl;
                while(temp != NULL){
                    cout << temp->nama << "\t" << temp->nim << "\t" << temp->jurusan << "\t" << temp->fakultas << "\t" << temp->alamat << endl;
                    temp = temp->next;
                }
            }
        }
};

int main(){
    DoubleLinkedlist dll;
    int pilih;
    string nama, nim, jurusan, fakultas, alamat;
    int pos;
    do{
        cout << endl;
        cout << "1. Insert Front" << endl;
        cout << "2. Insert Back" << endl;
        cout << "3. Insert At" << endl;
        cout << "4. Delete Front" << endl;
        cout << "5. Delete Back" << endl;
        cout << "6. Delete At" << endl;
        cout << "7. Search" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch(pilih){
            case 1:
                cout << "Nama : ";
                cin >> nama;
                cout << "NIM : ";
                cin >> nim;
                cout << "Jurusan : ";
                cin >> jurusan;
                cout << "Fakultas : ";
                cin >> fakultas;
                cout << "Alamat : ";
                cin >> alamat;
                dll.insertFront(nama, nim, jurusan, fakultas, alamat);
                break;
            case 2:
                cout << "Nama : ";
                cin >> nama;
                cout << "NIM : ";
                cin >> nim;
                cout << "Jurusan : ";
                cin >> jurusan;
                cout << "Fakultas : ";
                cin >> fakultas;
                cout << "Alamat : ";
                cin >> alamat;
                dll.insertBack(nama, nim, jurusan, fakultas, alamat);
                break;
            case 3:
                cout << "Nama : ";
                cin >> nama;
                cout << "NIM : ";
                cin >> nim;
                cout << "Jurusan : ";
                cin >> jurusan;
                cout << "Fakultas : ";
                cin >> fakultas;
                cout << "Alamat : ";
                cin >> alamat;
                cout << "Posisi : ";
                cin >> pos;
                dll.insertAt(nama, nim, jurusan, fakultas, alamat, pos);
                break;
            case 4:
                dll.deleteFront();
                break;
            case 5:
                dll.deleteBack();
                break;
            case 6:
                cout << "Posisi : ";
                cin >> pos;
                dll.deleteAt(pos);
                break;
            case 7:
                cout << "Nama : ";
                cin >> nama;
                dll.search(nama);
                break;
            case 8:
                dll.display();
                break;
            case 9:
                cout << "Terima Kasih" << endl;
                break;
            default:
                cout << "Pilihan Tidak Ada" << endl;
                break;
        }
    }while(pilih != 9);
}