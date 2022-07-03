#include <stdio.h>

int main()
{
    double sum, fac;
    int i, j, k;

    printf("%2s %12s\n", "n", "e");
    printf("-- ------------\n");

    for(i = 0; i < 10; i++)
    {
        if( i == 0)
        {
            sum = 1;
        }
        else
        {
            sum = 0;
            for(j = 0; j<= i; j++)
            {
                if( j == 0)
                    fac = 1;
                else
                {
                    fac = fac * j;
                }
                sum += 1 / fac;
            }
        }
        printf("%2d %12.10f\n", i, sum);
    }
    return 0;
}