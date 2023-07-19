#include "iostream"

using namespace std;

int main(){
    int penilaian = 0;
    short min;
    for(short i=0;i<3;i++){
        short temp;
        cin >> temp;
        penilaian += temp;
        if(temp <= 50){
            min++;
        }
    }
    if(penilaian >= 200 && min == 0){
        cout << "Lolos" << endl;
        return 0;
    }
    cout << "Tidak Lolos" << endl;
    return 0;
}