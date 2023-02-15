#include "stdio.h"

int main(){
    char nama[] = "aliong";
    char *p;

    // cara 1 >> langsung menunjuk nama array.
    p = nama;
    while (*p != NULL)
    {
        printf("%c",*p);
        p++;
    }
    printf("\n");

    // cara 2 >> secara eksplisit menunjuk ke elemen pertama array.
    p= &nama[0];
    while (*p != NULL)
    {
        printf("%c",*p);
        p++;
    }
    printf("\n");
    return 0;
}