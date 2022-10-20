#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode { //노드타입
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) //수정해야함
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link; 

	if (head != head->link) { // 노드가 1개 일때를 방지
		do {
			printf("%d->", p->data);
			p = p->link;
		} while (p != head);
	}
	printf("%d->", p->data); //마지막 노드 출력	
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head; // 맨뒤가 null 이 되면 안되서 자기 자신을 가르킨다.
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
	}
	return head; //변경된 헤드 포인터를 반환한다.
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3)
	}
	return head; //변경된 헤드 포인터를 반환한다.
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
			return NULL;
	}
	else if (head == head->link) { //하나의 노드가 남았을때
		removed = head;
		head = NULL;
		//head->link = head // head가 null 이라서 안써도 되는 것 
		free(removed);
	}
	else {
		removed = head->link;
		head->link = removed->link;
		free(removed);
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* removed;
	ListNode* p = head;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}
	else if (head == head->link) { //하나의 노드가 남았을때
		removed = head;
		head = NULL;
		//head->link = head // head가 null 이라서 안써도 되는 것 
		free(removed);
	}
	else {
		removed = head;
		while (p->link != head) {
			p = p->link;
		}
		p->link = removed->link;
		head = p;
		free(removed);
	}

	return head;
}

ListNode* search(ListNode* head, element data)
{
	ListNode* p = head;
	while (p->link != head) {
		if (p->data == data) return p;
		p = p->link;
	}

	return NULL;
}

element get_size(ListNode* head)
{
	int size = 1;
	ListNode* p = head;
	
	while (p->link != head) {
		size++;
		p = p->link;
	}

	return size;
}

//원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);

	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	head = delete_first(head);
	print_list(head);

	//여기부터는 임의로 쓴 부분
	head = delete_last(head);
	print_list(head);
	printf("list의 길이는 %d\n", get_size(head));

	return 0;
}