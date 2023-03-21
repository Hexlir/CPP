#include "iostream"

using namespace std;

int main(){
    string n;
    cin >> n;

    // Check are n has 0 there
    for (int i = 0; i < n.length(); i++){
        if (n[i] == '0'){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}