#include <stdio.h>

struct student
{
	char name[8];
	int hakbun;
	float grade;
};

struct student s1 = { "ȫ�浿", 2020006, 3.2 };
struct student s2 = { "�Ӳ���", 2020004, 2.7 };
struct student s3 = { "�̼���", 2020002, 4.3 };
struct student s4 = { "������", 2020001, 3.3 };
struct student s5 = { "������", 2020003, 3.8 };
struct student s6 = { "�輱��", 2020005, 1.5 };

struct student* student[6] = { &s1, &s2, &s3, &s4, &s5, &s6 };

struct student* search(int hakbun)
{
	struct result;
	for (int i = 0; i < 6; i++)
	{
		if (hakbun == student[i]->hakbun)
			return student[i];
	}
	return NULL;
}

void sort()
{
	int i, j, index;

	for (i = 0; i < 5; i++)
	{
		index = i;
		for (j = i + 1; j < 6; j++)
		{
			if (student[index]->hakbun > student[j]->hakbun)
				index = j;
		}
		char* temp;
		temp = student[i];
		student[i] = student[index];
		student[index] = temp;

	}
}

int main()
{
	struct student* p;

	p = search(2020003);
	if (p == NULL)
		printf("Ž�� ����\n\n");
	else
		printf("Ž�� ����: %s %d %f\n\n", p->name, p->hakbun, p->grade);

	sort();

	for (int i = 0; i < 6; i++)
		printf("%s %d %f\n", student[i]->name, student[i]->hakbun, student[i]->grade);

	return 0;
}
