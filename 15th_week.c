#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

typedef struct person { // 연락처를 구조체로 표현한다.
    char name[SIZE]; // 이름
    char address[SIZE]; // 주소
    char mobilephone[SIZE]; // 휴대폰
    char desc[SIZE]; // 특징
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
        fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.");
        return 1;
    }
    while (1) {
        menu(); // 메뉴를 표시한다
        printf("번호를 입력하시오: "); // 사용자로부터 정수를 받는다
        scanf("%d", &select);
        while (getchar() != '\n'); // 행의 끝까지 표준입력버퍼의 내용을 읽어 옴
        switch (select) {
        case 1: add_record(fp); break; // 데이터를 추가한다
        case 2: update_record(fp); break; // 데이터를 수정한다
        case 3: search_record(fp); break; // 데이터를 탐색한다
        case 4: delete_record(fp); break; // 데이터를 삭제한다
        case 5: print_all_records(fp); break; // 모든 데이터를 출력한다
        case 6: fclose(fp); return 0; // 종료
        }
    }
}
void menu()
{
    printf("\n");
    printf("====================\n");
    printf(" 1. 추가\n");
    printf(" 2. 수정\n");
    printf(" 3. 검색\n");
    printf(" 4. 삭제\n");
    printf(" 5. 전체출력\n");
    printf(" 6. 종료\n");
    printf("====================\n");
}
PERSON get_record()
{
    PERSON data;
    printf("이름: "); gets(data.name); // 이름을 입력받는다
    printf("주소: "); gets(data.address); // 주소를 입력받는다
    printf("휴대폰: "); gets(data.mobilephone); // 휴대폰 번호를 입력받는다
    printf("특징: "); gets(data.desc); // 특징을 입력 받는다
    return data;
}
void print_record(PERSON data)
{
    printf("\n");
    printf("<이름> %s\n", data.name);
    printf("<주소> %s\n", data.address);
    printf("<휴대폰> %s\n", data.mobilephone);
    printf("<특징> %s\n", data.desc);

}
void add_record(FILE* fp)
{
    PERSON data;
    data = get_record(); // 사용자로부터 데이터를 받아서 구조체에 저장
    fseek(fp, 0, SEEK_END); // 파일의 끝으로 간다
    fwrite(&data, sizeof(data), 1, fp); // 구조체 데이터를 파일에 쓴다
}

void search_record(FILE* fp)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET); // 파일의 처음으로 간다
    printf("\n검색할 사람의 이름: ");
    gets(name); // 이름을 입력 받는다

    while (!feof(fp))
    { // 파일의 끝까지 반복한다
        fread(&data, sizeof(data), 1, fp);
        if (strcmp(data.name, name) == 0) { // 이름을 비교한다
            print_record(data);
            break;
        }
    }
}
void update_record(FILE* fp)
{
    char name[SIZE];
    PERSON data;
    fseek(fp, 0, SEEK_SET); // 파일의 처음으로 간다
    printf("\n데이터를 수정할 사람의 이름: ");
    gets(name); // 이름을 입력 받는다

    while (!feof(fp))
    { // 파일의 끝까지 반복한다
        fread(&data, sizeof(data), 1, fp);

        if (strcmp(data.name, name) == 0)
        { // 이름을 비교한다
            print_record(data);
            printf("\n새로운 데이터를 입력하세요.\n");
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
    fseek(fp, 0, SEEK_SET); // 파일의 처음으로 간다
    printf("\n삭제할 사람의 이름: ");
    gets(name); // 이름을 입력 받는다

    fseek(fp, 0, SEEK_SET);
    while (!feof(fp))
    { // 파일의 끝까지 반복한다
        fread(&data, sizeof(data), 1, fp);

        if (strcmp(data.name, name) == 0)
        { // 이름을 비교한다
            print_record(data);
            fseek(fp, -1 * sizeof(data), SEEK_CUR);
            strcpy(data.name, " ");
            fwrite(&data, sizeof(data), 1, fp);
            printf("\n위 연락처를 삭제합니다.\n");
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