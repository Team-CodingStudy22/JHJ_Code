#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING 100

typedef struct {
	int num;
	char nums[MAX_STRING];
} element;

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
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

void stack_print(StackType* s)
{
	int i;

	if (is_empty(s))
		printf("<empty>\n--\n");
	else {
		printf("[%d, %s] <- top\n", s->data[s->top].num, s->data[s->top].nums);
		for (i = s->top - 1; i >= 0; i--)
			printf("[%d, %s]\n", s->data[i].num, s->data[i].nums);
		printf("--\n");
	}
}

void main()
{
	StackType s;
	element e;

	init(&s);
	stack_print(&s);

	e.num = 10;
	strcpy(e.nums, "ten");
	push(&s, e);
	stack_print(&s);
	

	e.num = 20;
	strcpy(e.nums, "twenty");
	push(&s, e);
	stack_print(&s);

	e.num = 30;
	strcpy(e.nums, "thirty");
	push(&s, e);
	stack_print(&s);

	e.num = 40;
	strcpy(e.nums, "fourty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	e.num = 50;
	strcpy(e.nums, "fifty");
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

}
