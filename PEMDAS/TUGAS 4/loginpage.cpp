#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

class User {
    private:
        string username;
        string password;
    public:
        User(string username, string password) {
            this->username = username;
            this->password = password;
        }

        string getUsername() {
            return this->username;
        }

        string getPassword() {
            return this->password;
        }

        void setUsername(string username) {
            this->username = username;
        }

        void setPassword(string password) {
            this->password = password;
        }
};


class LoginPage {
    private:
        vector<User> users;
        string username;
        string password;
    public:
        LoginPage() {
            this->username = "";
            this->password = "";
        }

        void login() {
            cout << "Masukkan username : ";
            cin >> this->username;
            cout << "Masukkan password : ";
            cin >> this->password;

            for (int i = 0; i < this->users.size(); ++i) {
                if (this->username == this->users[i].getUsername() && this->password == this->users[i].getPassword()) {
                    cout << "Login Berhasil!!" << endl;
                    return;
                }
            }

            cout << "Login Gagal" << endl;
        }

        void registerUser() {
            cout << "Masukkan username : ";
            cin >> this->username;
            cout << "Masukkan password : ";
            cin >> this->password;

            User user(this->username, this->password);
            this->users.push_back(user);
        }

        void save() {
            ofstream file;
            file.open("users.txt");

            for (int i = 0; i < this->users.size(); ++i) {
                file << this->users[i].getUsername() << endl;
                file << this->users[i].getPassword() << endl;
            }

            file.close();
        }

        void load() {
            ifstream file;
            file.open("users.txt");

            string line;
            while (getline(file, line)) {
                this->username = line;
                getline(file, line);
                this->password = line;

                User user(this->username, this->password);
                this->users.push_back(user);
            }

            file.close();
        }
};

int main() {
    LoginPage loginPage;
    loginPage.load();

    int choice;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "Masukkan pilihan : ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        loginPage.login();
    } else if (choice == 2) {
        system("cls");
        loginPage.registerUser();
    }

    loginPage.save();
}

