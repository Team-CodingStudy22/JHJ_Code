#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// root						root2
//		15						15
// 4          15			4		15
// 15        16 25    	15		   16   25
//											28

TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL };
TreeNode m4 = { 25, NULL, &m7 };
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;//p290 Quiz 02
int get_nonleaf_count(TreeNode* t)
{
	int count = 0;
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL)
			return 0;
		else
			count += 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
	}
	return count;
}

//p290 Quiz 03
int equal(TreeNode* t1, TreeNode* t2)
{
	return ((t1 == NULL && t2 == NULL) ||
		(t1 != NULL && t2 != NULL
			&& (t1->data == t2->data)
			&& equal(t1->left, t2->left)
			&& equal(t1->right, t2->right)));
}

//p319 #16
int get_oneleaf_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL) {
		if (node->left != NULL && node->right == NULL)
			return 1;
		else if (node->left == NULL && node->right != NULL)
			return 1;
		else
			count += get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
	}
	return count;
}

int get_twoleaf_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL || node->right == NULL)
			return 0;
		else
			count += 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
	}
	return count;
}

//p319 #17
int get_max(TreeNode* node)
{
	int max = -1;
	int root, left, right;

	if (node != NULL) {
		root = node->data;
		left = get_max(node->left);
		right = get_max(node->right);

		if (left > right)
			max = left;
		else
			max = right;

		if (root > max)
			max = root;
	}
	return max;
}

int get_min(TreeNode* node)
{
	int min = 1000000;
	int root, left, right;

	if (node != NULL) {
		root = node->data;
		left = get_min(node->left);
		right = get_min(node->right);

		if (left < right)
			min = left;
		else
			min = right;

		if (root < min)
			min = root;
	}
	return min;
}

//p319 #20
void node_increase(TreeNode* node)
{
	if (node == NULL)
		return NULL;
	else {
		node->data = node->data + 1;
		node_increase(node->left);
		node_increase(node->right);
	}
}

void preorder(TreeNode* node) // p274 코드 복사
{	if (node != NULL) {		printf("%d ", node->data);		preorder(node->left);		preorder(node->right);	}}TreeNode* copy(TreeNode* node){	if (node == NULL)		return NULL;	TreeNode* newTree;	newTree = (TreeNode*)malloc(sizeof(TreeNode));	newTree->left = copy(node->left);	newTree->right = copy(node->right);	newTree->data = node->data;	return newTree;}int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;
	printf("가)\n");
	printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));

	printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
	printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
	printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
	printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));
	printf("\n 나)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");
	printf("\n 다)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}