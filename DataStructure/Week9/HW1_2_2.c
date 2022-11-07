#include <stdio.h>
#include <malloc.h>
#define MAX_STRING 100

typedef struct {
	int num;
	char nums[MAX_STRING]; // 문자열도 있음
} element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

int is_full(LinkedStackType* s)
{
	return 0;
}

void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

void print_stack(LinkedStackType* s)
{
	StackNode* p = s->top;

	if (is_empty(s))
		printf("(empty)\n--\n");
	else {
		printf("[%d, %s] <- top\n", p->data.num, p->data.nums);
		for (p = s->top->link; p != NULL; p = p->link)
			printf("[%d, %s]\n", p->data.num, p->data.nums);
		printf("--\n");
	}
}

void main()
{
	LinkedStackType s;
	element e;

	init(&s);
	print_stack(&s);

	e.num = 10; 
	strcpy(e.nums, "ten");
	push(&s, e); 

	e.num = 20;
	strcpy(e.nums, "twenty");
	push(&s, e);
	print_stack(&s);

	e.num = 30;
	strcpy(e.nums, "thirty");
	push(&s, e);
	print_stack(&s);

	e.num = 40;
	strcpy(e.nums, "fourty");
	push(&s, e);
	print_stack(&s);

	pop(&s);
	print_stack(&s);

	e.num = 50;
	strcpy(e.nums, "fifty");
	push(&s, e);
	print_stack(&s);

	pop(&s);
	print_stack(&s);

	pop(&s);
	print_stack(&s);

	pop(&s);
	print_stack(&s);

	pop(&s);
	print_stack(&s);
	return 0;
}