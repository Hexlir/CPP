#include <cstdio>

__int128_t min(__int128_t a, __int128_t b){
    return (a < b) ? a : b;
}

int main(){
    long long M, A, B, l1, r1;
    scanf("%lld %lld %lld", &M, &A, &B);

    l1 = ((A + B == 2 * M) && (min(A, B) % 2 != 0)) ? 1 : 0;
    r1 = min(A, B);

    printf("%lld %lld\n", l1, r1);

    return 0;
}