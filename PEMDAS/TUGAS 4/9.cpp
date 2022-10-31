
#include "bits/stdc++.h"

using namespace std;

string database[3][2] = {
        {"admin", "admin"},
        {"user", "user"},
        {"guest", "guest"}
};



int main(){
    string username, password;

    cout << "Masukkan username :  ";
    cin >> username;

    cout << "Masukkan password :  ";
    cin >> password;

    for (int i = 0; i < 3; ++i) {
        if (username == database[i][0] && password == database[i][1]){
            cout << "Login Berhasil" << endl;
            return 0;
        }
    }

    cout << "Login Gagal" << endl;
}