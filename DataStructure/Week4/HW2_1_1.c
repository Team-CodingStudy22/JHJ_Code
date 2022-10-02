#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
	char name[100];
	char gender;
} element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(QueueType* q)
{
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%s ", q->queue[i].name);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

int get_count(QueueType* q) 
{
	int count = 0;
	int i;
	if (is_empty(q))
		count = 0;
	else {
		count = q->rear % MAX_QUEUE_SIZE - q->front % MAX_QUEUE_SIZE;
	}

	return count;
}

void main()
{
	QueueType manQ;
	QueueType womanQ;
	element newPerson;
	char key;

	init(&manQ);
	printf("���� �ּ� ���α׷��Դϴ�.\n");

	printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
	scanf("%c", &key);

	while (key != 'q') {
		switch (key) {
		case 'i' :
			printf("�̸��� �Է�: ");
			scanf("%s", newPerson.name);

			printf("������ �Է�<m or f>: ");
			scanf(" %c", &newPerson.gender);

			if (newPerson.gender == 'm') {
				if (is_empty(&womanQ) && is_full(&manQ)) {
					printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
				}
				else if (is_empty(&womanQ)) {
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
					enqueue(&manQ, newPerson);
				}
				else {
					element woman = dequeue(&womanQ);
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", newPerson.name, woman.name);
				}
			}
			else {
				if (is_empty(&manQ) && is_full(&womanQ)) {
					printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
				}
				else if (is_empty(&manQ)) {
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
					enqueue(&womanQ, newPerson);
				}
				else {
					element man = dequeue(&manQ);
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", newPerson.name, man.name);
				}
			}

			break;

		case 'c' :
			printf("���� ����� %d��: ", get_count(&manQ));
			print_queue(&manQ);
			printf("���� ����� %d��: ", get_count(&womanQ));
			print_queue(&womanQ);
			break;
		}
		printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
		scanf(" %c", &key);
	}
}

