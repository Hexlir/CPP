#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int nilai;

    cin >> nilai;

    if(nilai <= 100 && nilai >= 0){
        cout << "YA" << endl;
        return 0;
    }
    cout << "TIDAK" << endl;
}
