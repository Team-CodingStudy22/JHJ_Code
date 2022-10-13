#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//��� pre �ڿ� ���ο� ��� ���� 
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;

	return head;
}

ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (head == NULL)
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;

		temp->link = p;
	}
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link;
	free(removed);

	return head;
}

//�� �տ� �� ����
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("������ �׸��� ����");

	removed = head;
	head = removed->link;
	free(removed);

	return head;
}

//�������� �����ϱ�
ListNode* delete_last(ListNode* head)
{
	ListNode *temp = head;
	ListNode* prevTemp = head;
	ListNode *removed;

	if (head == NULL) error("������ �׸��� ����");
	if (temp->link == NULL) {
		removed = temp->link;
		temp->link = NULL;
		free(removed);

		return NULL;
	}
	else {
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}

		removed = temp;
		prevTemp->link = NULL;
		free(removed);
		return head;
	}
}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* search(ListNode* head, int x)
{
	ListNode* p;
	p = head;

	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

ListNode* concat(ListNode* head1, ListNode* head2)
{
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode* head) // �������� �����
{
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

//item �� ����Ʈ�� ������ 1 �� �ƴϸ� 0 �� ��ȯ 
int is_in_list(ListNode* head, element item)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		if (p->data == item)
			return 1;
	return 0;
}

//�ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ��ȯ
int get_length(ListNode* head)
{
	int count = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}

//�ܼ����Ḯ��Ʈ�� ��� ������ ���� ���� ���� ��ȯ
int get_total(ListNode* head)
{
	int total = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		total += p->data;
	return total;
}

//pos ��ġ(0 �� ù ��° ���)�� �ִ� ����� data �� ��ȯ
element get_entry(ListNode* head, int pos)
{
	ListNode* p;
	int i = 0;

	for (p = head; p != NULL; p = p->link, i++)
		if (i == pos)
			return p->data;

	return -1; // ���� �� 	
}

ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* p = head;
	ListNode* removed;

	if (head == NULL)
		return NULL;
	else if (head->data == key) {
		removed = head;
		head = head->link;
		free(removed);
	}
	else {
		while (p->link != NULL) {
			if (p->link->data == key) {
				removed = p->link;
				p->link = p->link->link;
				free(removed);
				break;
			}
			p = p->link;
		}
	}

	return head;
}

//pos ��ġ�� value �� ���� ��带 �߰�
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	element key = get_entry(head, pos);

	p->data = value;
	p->link = NULL;

	if (head == NULL)
		head = p;
	else if(pos == 0) {
		p->link = head->link;
		head->link = p;
	}
	else {
		while (temp->link != NULL) {
			if (temp->link->data == key) {
				p->link = temp->link;
				temp->link = p;
				break;
			}
			temp = temp->link;
		}
	}

	return head;
}

// pos ��ġ�� ��带 ����
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* temp = head;
	element key = get_entry(head, pos);
	ListNode* removed;

	if (head == NULL)
		return NULL;
	else if (pos == 0) {
		removed = head;
		head = head->link;
		free(removed);
	}
	else {
		while (temp->link != NULL) {
			if (temp->link->data == key) {
				removed = temp->link;
				temp->link = temp->link->link;
				free(removed);
				break;
			}
			temp = temp->link;
		}
	}
	
	return head;
}

int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3;

	//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->30->
	list1 = delete_first(list1);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�. 
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2�� ���
	printf("list2 = ");
	print_list(list2);

	// list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33->
	list2 = delete_last(list2);

	// list2�� ���
	printf("list2 = ");
	print_list(list2);

	//list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����.
	list3 = reverse(list2);

	//list3�� ����Ѵ�. 
	printf("list3 = ");
	print_list(list3);

	// list1 = 20->30->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�. 
	list1 = concat(list1, list3);

	//list1�� ����Ѵ�. 
	printf("list1 = ");
	print_list(list1);

	printf("\n");
	//(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ����
	
	//list1 �� 33�� �ִ��� Ȯ��
	int is_in_key = 33;
	if(is_in_list(list1, is_in_key))
		printf("list1�� %d�� �ִ�.\n", is_in_key);
	else
		printf("list1�� %d�� ����.\n", is_in_key);

	//����Ʈ ��� �� ��ȯ
	printf("list1�� ���̴� %d �̴�.\n", get_length(list1));

	//��� ������ ���� ���� �� ��ȯ
	printf("list1�� ��� ������ ���� ���� %d�̴�.\n", get_total(list1));

	//key �� ����
	int delete_key = 33;
	list1 = delete_by_key(list1, delete_key);
	//list1�� ����Ѵ�. 
	printf("�����Ͱ� %d�� ���� �����ϸ� list1 = ", delete_key);
	print_list(list1);

	//pos ��ġ�� value�� ��� �߰�
	int insert_value = 40;
	int insert_poskey = 2;
	list1 = insert_pos(list1, insert_poskey, insert_value);
	//list1�� ����Ѵ�.
	printf("%d�� %d�ڸ��� �߰��ϸ� list1 = ", insert_value, insert_poskey);
	print_list(list1);

	//pos ��ġ ��� ����
	int delete_poskey = 1;
	list1 = delete_pos(list1, delete_poskey);
	//list1�� ����Ѵ�.
	printf("%d �ڸ� ��带 �����ϸ� list1 = ", delete_poskey);
	print_list(list1);
}