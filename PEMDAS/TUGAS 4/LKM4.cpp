
#include <bits/stdc++.h>

using namespace std;

int main(){
    float a, b;
    cout << "Masukkan nilai a & b : ";
    cin >> a >> b;

    if (b == 0){
        cout << "Nilai b tidak boleh 0" << endl;
    } else {
        cout << "Nilai a / b adalah : " << a / b << endl;
    }
}