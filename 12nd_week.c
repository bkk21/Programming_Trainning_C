#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[10];
    int hakbun;
    int score;
};

struct student arr[3];

int main()
{
    FILE* fp;
    fp = fopen("C:\\test\\score.txt", "r");

    if (fp == NULL)
    {
        printf("파일 열기 실패\n");
        return 0;
    }

    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%s %d %d\n", arr[i].name, &arr[i].hakbun, &arr[i].score);
    }

    fclose(fp);

    for (int i = 0; i < 3; i++)
    {
        printf("%-8s %8d %3d\n", arr[i].name, arr[i].hakbun, arr[i].score);
    }

    return 0;
}