#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[10];
	char phone[20];
	char email[40];
	struct node* next;
};

struct node* head = NULL;

void print_list(struct node* h)
{
	struct node* q;
	for(q=h; q; q=q->next)
	{
		printf("-->%s ", q->name);
	}
	printf("\n");
}

void add_head(char* name, char* phone, char* email)
{
	struct node* p;
	
	p = (struct node*)malloc(sizeof(struct node));
	strcpy(p->name, name);
	strcpy(p->phone, phone);
	strcpy(p->email, email);
	p->next = head;
	head = p;
}
int main(void)
{
	add_head("È«±æµ¿", "010-1111-1111", "gdhong@kku.ac.kr");
	print_list(head);

	add_head("ÀÓ²©Á¤", "010-2222-2222", "kkjlim@naver.com");
	print_list(head);

	add_head("ÀÌ¼ø½Å", "010-3333-3333", "sslee@gamil.com");
	print_list(head);

	add_head("±èÀ¯½Å", "010-4444-4444", "yskim@daum.net");
	print_list(head);

	return 0;
}