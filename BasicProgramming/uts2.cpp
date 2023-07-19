#include "bits/stdc++.h"

using namespace std;

int main (){
    int k;

    cin >> k;

    while(k--){
        int n, batas, penentu = 0;
        float prsn;

        cin >> n >> prsn >> batas;

        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x>= batas){
                penentu++;
            }
        }
        int a = n*prsn;

        cout << penentu << endl;
        
        cout << a << endl;


        if(penentu>=a){
            cout << "Kelas dilanjutkan" << endl;
    }   else{
            cout << "Kelas dihentikan" << endl;
        }
    }
}