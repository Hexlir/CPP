#include "iostream"
// #include "conio.h" --this lib for MS-DOS compiler
#include "stdio.h" // for linux based

using namespace std;

int main(){
    int x,y;
    int *px;

    x = 89;
    y = x;
    px  = &x;
    cout << "Nilai x = " << x << endl;
    cout << "Nilai y = " << y << endl;
    cout << "Alamat px = " << px << endl;
    cout << "Nilai px = " << *px << endl;
    // getch(); => For windows
    getchar(); // for linux
}