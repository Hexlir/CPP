#include "iostream"

using namespace std;

int pow(int var, int pangkat){
    if(pangkat == 0) return 1;
    else return var * pow(var, pangkat-1);
}

int main(){
    int var, pangkat;
    printf("Masukkan bilangan : ");
    scanf("%d", &var);
    printf("Masukkan pangkat : ");
    scanf("%d", &pangkat);
    int hasil = pow(var, pangkat);
    printf("%d\n",hasil);
    return 0;
}