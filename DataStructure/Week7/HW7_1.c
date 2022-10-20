#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode { //���Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) //�����ؾ���
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link; 

	if (head != head->link) { // ��尡 1�� �϶��� ����
		do {
			printf("%d->", p->data);
			p = p->link;
		} while (p != head);
	}
	printf("%d->", p->data); //������ ��� ���	
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head; // �ǵڰ� null �� �Ǹ� �ȵǼ� �ڱ� �ڽ��� ����Ų��.
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
	}
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
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
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
			return NULL;
	}
	else if (head == head->link) { //�ϳ��� ��尡 ��������
		removed = head;
		head = NULL;
		//head->link = head // head�� null �̶� �Ƚᵵ �Ǵ� �� 
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
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	else if (head == head->link) { //�ϳ��� ��尡 ��������
		removed = head;
		head = NULL;
		//head->link = head // head�� null �̶� �Ƚᵵ �Ǵ� �� 
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

//���� ���� ����Ʈ �׽�Ʈ ���α׷�
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

	//������ʹ� ���Ƿ� �� �κ�
	head = delete_last(head);
	print_list(head);
	printf("list�� ���̴� %d\n", get_size(head));

	return 0;
}