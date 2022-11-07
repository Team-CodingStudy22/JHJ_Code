#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	char name[100]; // 이름 -> 배열로 
	char gender; // 성별 
} element; // element 타입 ! 

typedef struct QueueNode { 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { 
	QueueNode* front, * rear;
} LinkedQueueType;

void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}

int is_full(LinkedQueueType* q) 
{
	return 0;
}

void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("메모리를 할당할 수 없습니다");
	else {
		temp->data = item; 
		temp->link = NULL; 
		if (is_empty(q)) { 
			q->front = temp;
			q->rear = temp;
		}
		else { 
			q->rear->link = temp; 
			q->rear = temp;
		}
	}
}

element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) 
		printf("큐가 비어 있읍니다");
	else {
		item = temp->data; 
		q->front = q->front->link; 
		if (q->front == NULL) 
			q->rear = NULL;
		free(temp);
		return item; 
	}
}

void print_queue(LinkedQueueType* q)
{
	QueueNode* p;

	if (!is_empty(q)) {
		for (p = q->front; p != NULL; p = p->link)
			printf("%s ", p->data.name);
	}
	printf("\n");
}

int get_count(LinkedQueueType* q)
{
	QueueNode* p;
	int count = 0;

	if (is_empty(q))
		return 0;
	else {
		for (p = q->front; p != NULL; p = p->link)
			count++;
		return count;
	}
}

void check(LinkedQueueType* q, LinkedQueueType* p, element item) 
{
	if (is_full(q)) 
		printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
	else { 
		if (is_empty(p)) { 
			printf("아직 대상자가 없습니다. 기다려주십시요.\n"); 
			enqueue(q, item); 
		}
		else { 
			enqueue(q, item); 
			printf("커플이 탄생했습니다! %s과 %s\n", dequeue(q).name, dequeue(p).name); 
		}
	}
}

void main()
{
	LinkedQueueType manQ;
	LinkedQueueType womanQ;
	element newPerson;
	char key;
 
	init(&manQ);
	init(&womanQ);
	printf("미팅 주선 프로그램입니다.\n");
	
	do {
		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
		scanf(" %c", &key); 

		switch (key) {
		case 'i': 
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);
			
			printf("성별을 입력<m or f>: ");
			scanf(" %c", &newPerson.gender); 
			
			if (newPerson.gender == 'm') 
				check(&manQ, &womanQ, newPerson); 
			else
				check(&womanQ, &manQ, newPerson); 
			break;

		case 'c':
			printf("남성 대기자 %d명 ", get_count(&manQ));
			print_queue(&manQ);
			printf("여성 대기자 %d명 ", get_count(&womanQ));
			print_queue(&womanQ);
			break;
		}
	} while (key != 'q');
}