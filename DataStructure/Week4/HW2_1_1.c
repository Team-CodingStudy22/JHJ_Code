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
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
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
	printf("미팅 주선 프로그램입니다.\n");

	printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
	scanf("%c", &key);

	while (key != 'q') {
		switch (key) {
		case 'i' :
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);

			printf("성별을 입력<m or f>: ");
			scanf(" %c", &newPerson.gender);

			if (newPerson.gender == 'm') {
				if (is_empty(&womanQ) && is_full(&manQ)) {
					printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
				}
				else if (is_empty(&womanQ)) {
					printf("아직 대상자가 없습니다. 기다려주십시요.\n");
					enqueue(&manQ, newPerson);
				}
				else {
					element woman = dequeue(&womanQ);
					printf("커플이 탄생했습니다! %s과 %s\n", newPerson.name, woman.name);
				}
			}
			else {
				if (is_empty(&manQ) && is_full(&womanQ)) {
					printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
				}
				else if (is_empty(&manQ)) {
					printf("아직 대상자가 없습니다. 기다려주십시요.\n");
					enqueue(&womanQ, newPerson);
				}
				else {
					element man = dequeue(&manQ);
					printf("커플이 탄생했습니다! %s과 %s\n", newPerson.name, man.name);
				}
			}

			break;

		case 'c' :
			printf("남성 대기자 %d명: ", get_count(&manQ));
			print_queue(&manQ);
			printf("여성 대기자 %d명: ", get_count(&womanQ));
			print_queue(&womanQ);
			break;
		}
		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
		scanf(" %c", &key);
	}
}

