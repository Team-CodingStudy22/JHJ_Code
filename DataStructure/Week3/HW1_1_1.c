#include <stdio.h>
#define MAX_STACK_SIZE 3

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
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

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "<empty>\n--\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

void stack_print(StackType* s)
{
	int i;

	printf("%d  <- top\n", s->data[s->top]);

	for (i = s->top - 1; i >= 0; i--)
		printf("%d\n", s->data[i]);
}

void main()
{
	StackType s;

	init(&s);
	if (is_empty(&s))
		printf("<empty>\n--\n");
	
	push(&s, 10);
	stack_print(&s);
	printf("--\n");

	push(&s, 20);
	stack_print(&s); 
	printf("--\n");

	push(&s, 30);
	stack_print(&s);
	printf("--\n");

	push(&s, 40);
	stack_print(&s);
	printf("--\n");

	pop(&s);
	stack_print(&s);
	printf("--\n");

	push(&s, 50);
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