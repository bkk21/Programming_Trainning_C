#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card
{
	int face; //숫자
	int suit; //무늬
};
typedef struct card CARD;

void init_deck(CARD arr[]);
void shuffle_deck(CARD arr[]);
void print_card(CARD* c);
void print_deck(CARD arr[]);
void sort(CARD arr[]);

int main()
{
	CARD deck[52];

	init_deck(deck);

	shuffle_deck(deck);
	print_deck(deck);
	printf("\n");

	sort(deck);
	print_deck(deck);
	printf("\n");

	return 0;
}

void init_deck(CARD arr[])
{
	int i, face, suit;

	i = 0;
	for (suit = 0; suit < 4; suit++)
	{
		for (face = 1; face <= 13; face++)
		{
			arr[i].suit = suit;
			arr[i].face = face;
			i++;
		}
	}
}

void shuffle_deck(CARD arr[])
{
	int first, second;
	CARD s;
	srand(time(NULL));
	for (first = 0; first < 52; first++)
	{
		second = rand() % 52;
		s = arr[first];
		arr[first] = arr[second];
		arr[second] = s;
	}

}

void print_card(CARD* c)
{
	static char* faces[] = { "", "A", "2", "3", "4","5", "6", "7", "8", "9", "10","J", "Q", "K" };
	static char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	printf("%s-%s \t", faces[c->face], suits[c->suit]);
}

void print_deck(CARD arr[])
{
	/* 한 벌의 카드를 출력하시오.
	   print_card() 함수를 이용하시오.*/

	int i;
	for (i = 0; i < 52; i++)
	{
		print_card(&arr[i]);
		if (i % 4 == 3)
			printf("\n");
	}
}

void sort(CARD arr[])
{
	/* 첫번째 기준 : 숫자
	A, 2, 3, 4, …,J, Q, K
	두번째 기준(숫자가 동일핛 때): 무늬
	Hearts, Diamonds, Clubs, Spades */

	int i = 0;
	int j, index, count;
	CARD temp;

	for (i = 0; i < 51; i++)
	{
		index = i;
		for (j = i + 1; j < 52; j++)
		{
			if (arr[index].face > arr[j].face)
				index = j;
			else if (arr[index].face == arr[j].face)
				if (arr[index].suit > arr[j].suit)
					index = j;
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

}
