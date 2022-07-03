#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

typedef struct person { // ����ó�� ����ü�� ǥ���Ѵ�.
    char name[SIZE]; // �̸�
    char address[SIZE]; // �ּ�
    char mobilephone[SIZE]; // �޴���
    char desc[SIZE]; // Ư¡
} PERSON;
void menu();
PERSON get_record();
void print_record(PERSON data);
void add_record(FILE* fp);
void search_record(FILE* fp);
void update_record(FILE* fp);
void delete_record(FILE* fp);
void print_all_records(FILE* fp);
int main(void)
{
    FILE* fp;
    int select;
    if ((fp = fopen("address.dat", "wb+")) == NULL) {
        fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�.");
        return 1;
    }
    while (1) {
        menu(); // �޴��� ǥ���Ѵ�
        printf("��ȣ�� �Է��Ͻÿ�: "); // ����ڷκ��� ������ �޴´�
        scanf("%d", &select);
        while (getchar() != '\n'); // ���� ������ ǥ���Է¹����� ������ �о� ��
        switch (select) {
        case 1: add_record(fp); break; // �����͸� �߰��Ѵ�
        case 2: update_record(fp); break; // �����͸� �����Ѵ�
        case 3: search_record(fp); break; // �����͸� Ž���Ѵ�
        case 4: delete_record(fp); break; // �����͸� �����Ѵ�
        case 5: print_all_records(fp); break; // ��� �����͸� ����Ѵ�
        case 6: fclose(fp); return 0; // ����
        }
    }
}
void menu()
{
    printf("\n");
    printf("====================\n");
    printf(" 1. �߰�\n");
    printf(" 2. ����\n");
    printf(" 3. �˻�\n");
    printf(" 4. ����\n");
    printf(" 5. ��ü���\n");
    printf(" 6. ����\n");
    printf("====================\n");
}
PERSON get_record()
{
    PERSON data;
    printf("�̸�: "); gets(data.name); // �̸��� �Է¹޴´�
    printf("�ּ�: "); gets(data.address); // �ּҸ� �Է¹޴´�
    printf("�޴���: "); gets(data.mobilephone); // �޴��� ��ȣ�� �Է¹޴´�
    printf("Ư¡: "); gets(data.desc); // Ư¡�� �Է� �޴´�
    return data;
}
void print_record(PERSON data)
{
    printf("\n");
    printf("<�̸�> %s\n", data.name);
    printf("<�ּ�> %s\n", data.address);
    printf("<�޴���> %s\n", data.mobilephone);
    printf("<Ư¡> %s\n", data.desc);

}
void add_record(FILE* fp)
{
    PERSON data;
    data = get_record(); // ����ڷκ��� �����͸� �޾Ƽ� ����ü�� ����
    fseek(fp, 0, SEEK_END); // ������ ������ ����
    fwrite(&data, sizeof(data), 1, fp); // ����ü �����͸� ���Ͽ� ����
}

void search_record(FILE* fp)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET); // ������ ó������ ����
    printf("\n�˻��� ����� �̸�: ");
    gets(name); // �̸��� �Է� �޴´�

    while (!feof(fp))
    { // ������ ������ �ݺ��Ѵ�
        fread(&data, sizeof(data), 1, fp);
        if (strcmp(data.name, name) == 0) { // �̸��� ���Ѵ�
            print_record(data);
            break;
        }
    }
}
void update_record(FILE* fp)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET); // ������ ó������ ����
    printf("\n�����͸� ������ ����� �̸�: ");
    gets(name); // �̸��� �Է� �޴´�

    while (!feof(fp))
    { // ������ ������ �ݺ��Ѵ�
        fread(&data, sizeof(data), 1, fp);

        if (strcmp(data.name, name) == 0)
        { // �̸��� ���Ѵ�
            print_record(data);
            printf("\n���ο� �����͸� �Է��ϼ���.\n");
            data = get_record();
            fseek(fp, -1 * sizeof(data), SEEK_CUR);
            fwrite(&data, sizeof(data), 1, fp);
            break;
        }
    }
}
void delete_record(FILE* fp)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET); // ������ ó������ ����
    printf("\n������ ����� �̸�: ");
    gets(name); // �̸��� �Է� �޴´�

    fseek(fp, 0, SEEK_SET);
    while (!feof(fp))
    { // ������ ������ �ݺ��Ѵ�
        fread(&data, sizeof(data), 1, fp);

        if (strcmp(data.name, name) == 0)
        { // �̸��� ���Ѵ�
            print_record(data);
            fseek(fp, -1 * sizeof(data), SEEK_CUR);
            strcpy(data.name, " ");
            fwrite(&data, sizeof(data), 1, fp);
            printf("\n�� ����ó�� �����մϴ�.\n");
            break;
        }
    }
}
void print_all_records(FILE* fp)
{
    char name[SIZE];
    PERSON data;

    fseek(fp, 0, SEEK_SET);
    while (!feof(fp))
    {
        fread(&data, sizeof(data), 1, fp);

        if (strcmp(data.name, " ") == 0)
            continue;

        else if (feof(fp))
            break;

        print_record(data);

    }
}