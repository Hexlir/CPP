#include <bits/stdc++.h>
#define standar using namespace std

standar;

int main() {
    string a, b;
    cin>>a;
    cin>>b;
    for(int i=0; i < a.length(); i++) {
        string tmp = a;
        tmp.erase(i, 1);
        if(tmp == b) {
            cout<<"Tentu saja bisa!\n";
            return 0;
        }
    }
    cout<<"Wah, tidak bisa :(\n";
    return 0;
}