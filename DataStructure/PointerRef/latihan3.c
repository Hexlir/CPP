#include "stdio.h"

int main(int argc, char const *argv[])
{
    int a = 41, b = 53, t;
    int *p, *q;
    p = &a;
    q = &b;
    printf("nilai yang ditunjuk p = %d di alamat %p \n", *p, p);
    printf("nilai yang ditunjuk q = %d di alamat %p \n", *q, q);

    t = *p;
    *p = *q;
    *q = t;

    return 0;
}