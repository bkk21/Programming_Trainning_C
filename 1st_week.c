#include <stdio.h>

struct values
{
	int n1, n2;
	double x1, x2;
};

void print_values(struct values* s)
{
	printf("n1=%d, n2=%d, x1=%lf, x2=%lf\n", s->n1, s->n2, s->x1, s->x2);
}

void double_values(struct values* s)
{
	s->n1 *= 2;
	s->n2 *= 2;
	s->x1 *= 2;
	s->x2 *= 2;
}

int main()
{
	struct values s1;

	s1.n1 = 1;
	s1.n2 = 2;
	s1.x1 = 0.1;
	s1.x2 = 0.2;
	print_values(&s1);
	double_values(&s1);
	print_values(&s1);
	return 0;
}