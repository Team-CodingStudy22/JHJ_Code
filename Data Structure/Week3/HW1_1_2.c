#include <stdio.h>
#define MAX_STACK_SIZE 3

typedef int element;
typedef char* element2;

typedef struct {
	element data[MAX_STACK_SIZE];
	element2 data_name[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top <= 0);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item, element2 *items)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		(s->top)++;
		s->data[s->top] = item;
		s->data_name[s->top] = items;
	}
}

StackType* pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "<empty>\n--\n");
		exit(1);
	}
	else {
		StackType* s1 = s;
		(s->top)--;
		return s1;
	}
}

StackType* peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s;
}

void stack_print(StackType* s)
{
	int i;

	printf("[%d, %s] <- top\n", s->data[s->top], s->data_name[s->top]);

	for (i = s->top - 1; i >= 0; i--)
		printf("[%d, %s]\n", s->data[i], s->data_name[i]);
}

void main()
{
	StackType s;

	init(&s);
	if (is_empty(&s))
		printf("<empty>\n--\n");

	push(&s, 10, "ten");
	stack_print(&s);
	printf("--\n");

	push(&s, 20, "twenty");
	stack_print(&s);
	printf("--\n");

	push(&s, 30, "thirty");
	stack_print(&s);
	printf("--\n");

	push(&s, 40, "fourty");
	stack_print(&s);
	printf("--\n");

	pop(&s);
	stack_print(&s);
	printf("--\n");

	push(&s, 50, "fifty");
	stack_print(&s);
	printf("--\n");

	pop(&s);
	stack_print(&s);
	printf("--\n");

	pop(&s);
	stack_print(&s);
	printf("--\n");

	pop(&s);

	return 0;
}