#include <stdio.h>

int main()
{
    int a[5][5] = { 0 };
    int b[5][5];

    int i, j;
    int k = 1;
    int l = 1;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < l; j++)
        {
            a[i][j] = k;
            k++;
        }
        l++;
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%2d ", a[i][j]);
        printf("\n");
    }

    printf("---------------\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 4; j >= 0; j--)
        {
            if (a[4 - j][i] != 0)
                b[i][j] = a[4 - j][i];
            else
                b[i][j] = 0;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%2d ", b[i][j]);
        printf("\n");
    }

    return 0;
}