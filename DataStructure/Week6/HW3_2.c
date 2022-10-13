#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//노드 pre 뒤에 새로운 노드 삽입 
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

// pre가 가르키는 노드의 다음 노드를 삭제한다.
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link;
	free(removed);

	return head;
}

//맨 앞에 것 삭제
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("삭제할 항목이 없음");

	removed = head;
	head = removed->link;
	free(removed);

	return head;
}

//마지막꺼 삭제하기
ListNode* delete_last(ListNode* head)
{
	ListNode *temp = head;
	ListNode* prevTemp = head;
	ListNode *removed;

	if (head == NULL) error("삭제할 항목이 없음");
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

ListNode* reverse(ListNode* head) // 역순으로 만들기
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

//item 이 리스트에 있으면 1 을 아니면 0 을 반환 
int is_in_list(ListNode* head, element item)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		if (p->data == item)
			return 1;
	return 0;
}

//단순 연결 리스트에 존재하는 노드의 수를 반환
int get_length(ListNode* head)
{
	int count = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}

//단순연결리스트의 모든 데이터 값을 더한 합을 반환
int get_total(ListNode* head)
{
	int total = 0;
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		total += p->data;
	return total;
}

//pos 위치(0 이 첫 번째 노드)에 있는 노드의 data 를 반환
element get_entry(ListNode* head, int pos)
{
	ListNode* p;
	int i = 0;

	for (p = head; p != NULL; p = p->link, i++)
		if (i == pos)
			return p->data;

	return -1; // 없을 때 	
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

//pos 위치에 value 를 갖는 노드를 추가
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

// pos 위치의 노드를 삭제
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

	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->30->
	list1 = delete_first(list1);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다. 
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2를 출력
	printf("list2 = ");
	print_list(list2);

	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
	list2 = delete_last(list2);

	// list2를 출력
	printf("list2 = ");
	print_list(list2);

	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
	list3 = reverse(list2);

	//list3를 출력한다. 
	printf("list3 = ");
	print_list(list3);

	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다. 
	list1 = concat(list1, list3);

	//list1을 출력한다. 
	printf("list1 = ");
	print_list(list1);

	printf("\n");
	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자
	
	//list1 에 33이 있는지 확인
	int is_in_key = 33;
	if(is_in_list(list1, is_in_key))
		printf("list1에 %d이 있다.\n", is_in_key);
	else
		printf("list1에 %d이 없다.\n", is_in_key);

	//리스트 노드 수 반환
	printf("list1의 길이는 %d 이다.\n", get_length(list1));

	//모든 데이터 값을 더한 합 반환
	printf("list1의 모든 데이터 값의 합은 %d이다.\n", get_total(list1));

	//key 값 삭제
	int delete_key = 33;
	list1 = delete_by_key(list1, delete_key);
	//list1을 출력한다. 
	printf("데이터가 %d인 것을 삭제하면 list1 = ", delete_key);
	print_list(list1);

	//pos 위치에 value값 노드 추가
	int insert_value = 40;
	int insert_poskey = 2;
	list1 = insert_pos(list1, insert_poskey, insert_value);
	//list1을 출력한다.
	printf("%d를 %d자리에 추가하면 list1 = ", insert_value, insert_poskey);
	print_list(list1);

	//pos 위치 노드 삭제
	int delete_poskey = 1;
	list1 = delete_pos(list1, delete_poskey);
	//list1을 출력한다.
	printf("%d 자리 노드를 삭제하면 list1 = ", delete_poskey);
	print_list(list1);
}