#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
	FILE* fp;

	if ((fp = fopen("C:\\test\\numbers.txt", "a")) == NULL)
	{
		fprintf(stderr, "Cannot open file\n");
		exit(1);
	}

	srand(time(NULL));
	int n = rand() % 100 + 1;
	fprintf(fp, "%d의 제곱근은 %f입니다.\n", n, sqrt(n));
	fclose(fp);

	return 0;
}