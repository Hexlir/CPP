#include "iostream"

#define endl '\n'

short t;
short n;
short a,b;

int main()
{
    scanf("%hd", &t);

    while (t--)
    {
        scanf("%hd", &n);

        short best_quality = 0;
        short best_quality_index = 0;

        if (n == 1)
        {
            scanf("%hd %hd", &a, &b);
            printf("1\n");
            continue;
        }

        for (short i = 0; i < n; i++)
        {
            scanf("%hd %hd", &a, &b);

            if (a <= 10)
            {
                if (b > best_quality)
                {
                    best_quality = b;
                    best_quality_index = i;
                }
            }
        }

        printf("%hd\n", best_quality_index + 1);
    }
}