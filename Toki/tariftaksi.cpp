#include "iostream"

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int A, B, L;
        cin >> A >> B >> L;

        if (L < 2000){
            cout << A << endl;
        }
        else{
            L -= 2000;
            cout << A + ( B * (L/100) ) << endl; 

        }
    }
}