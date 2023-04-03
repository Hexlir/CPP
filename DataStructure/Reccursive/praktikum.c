#include <stdio.h>
#include <stdlib.h>

int power(int var, int pangkat){
    if(pangkat == 0){
        return 1;
    }else{
        return var * power(var, pangkat-1);
    }
}

int main(){
    int var, pangkat;
    printf("Masukkan angka: ");
    scanf("%d", &var);
    printf("Masukkan pangkat: ");
    scanf("%d", &pangkat);
    printf("%d pangkat %d adalah %d", var, pangkat, power(var, pangkat));
    return 0;
}