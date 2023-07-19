// BRIEF

// Lakukan percobaan untuk menginputkan string dari keyboard dengan menggunakan : 
// scanf(), gets() dan fgets(). 
// Analisislah dan berikan kesimpulan untuk setiap fungsi tsb!

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Menggunakan scanf()");
    printf("Masukkan string: ");
    scanf("%s", str);
    printf("%s", str);

    printf("Menggunakan gets()");
    printf("Masukkan string: ");
    fflush(stdin);
    gets(str);
    printf("%s", str);

    printf("Menggunakan fgets()");
    printf("Masukkan string: ");
    fgets(str, 100, stdin);
    printf("%s", str);

    return 0;
}