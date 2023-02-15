#include "iostream"
#include "stdio.h"

using namespace std;

int main(){
    int x;
    int *px;
    int **ppx;

    x = 175;
    px = &x;
    ppx = &px;
    cout << "Nilai x = " << x << endl;
    cout << "Nilai px = " << *px << endl;
    cout << "Nilai ppx = " << **ppx << endl;

    getchar();
}