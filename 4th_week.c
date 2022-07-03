#include <stdio.h>
#include <stdlib.h>

void matrix_add(int** x, int** y, int** z, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			z[i][j] = x[i][j] + y[i][j];
	}
}int** create_matrix(int row, int col)
{
	int** arr;
	int i;
	arr = (int**)calloc(row, sizeof(int*));

	for (i = 0; i < row; i++)
	{
		arr[i] = (int*)calloc(col, sizeof(int));
	}
	return arr;
}

void free_matrix(int** arr, int row)
{
	for (int i = 0; i < row; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
int main()
{
	int** a, ** b, ** c;
	int m, n, i, j;

	printf("���� ��: ");
	scanf_s("%d", &m);

	printf("���� ��: ");
	scanf_s("%d", &n);

	a = create_matrix(m, n);
	b = create_matrix(m, n);
	c = create_matrix(m, n);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			a[i][j] = 1;
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			b[i][j] = 2;
	}

	matrix_add(a, b, c, m, n);

	for (i = 0; i < m; i++) 
	{
		for (j = 0; j < n; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}

	free_matrix(a, m);
	free_matrix(b, m);
	free_matrix(c, m);

	printf("����� �޸𸮸� ��� �ݳ��߽��ϴ�.\n");

	return 0;
}