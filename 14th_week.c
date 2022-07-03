#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student 
{
	char name[10];
	int hakbun;
	int score;
};
int main(void)
{
    FILE* fp;
    fp = fopen("C:\\test\\score.dat", "rb");
    
    if (fp == NULL) 
    {
        fprintf(stderr, "출력할 파일이 없습니다.\n");
        return 1;
    }

    struct student s;
    while (fread(&s, sizeof(s), 1, fp) > 0)
    {
        printf("[%s, %d, %d]\n", s.name, s.hakbun, s.score);
    }

    fclose(fp);

    return 0;
}