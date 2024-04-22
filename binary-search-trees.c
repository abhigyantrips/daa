#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};
typedef struct node Node;

Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->data = data;
	newNode->right = NULL;

	return newNode;
}

Node *minNode(Node *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->left != NULL)
	{
		return minNode(root->left);
	}
	return root;
}

void insertNode(Node **root, int data)
{
	if (*root == NULL)
	{
		Node *newNode = createNode(data);
		*root = newNode;
		return;
	}

	if (data > (*root)->data)
		insertNode(&(*root)->right, data);
	else if (data < (*root)->data)
		insertNode(&(*root)->left, data);
}

void deleteNode(Node **root, int data)
{
	if (*root == NULL)
		return;

	if (data < (*root)->data)
		deleteNode(&(*root)->left, data);
	else if (data > (*root)->data)
		deleteNode(&(*root)->right, data);
	else
	{
		if ((*root)->left == NULL && (*root)->right == NULL)
		{
			// if there are no children
			*root = NULL;
			return;
		}
		else if ((*root)->left == NULL || (*root)->right == NULL)
		{
			// if there's only one child, return the other in place of root
			Node *temp;
			if ((*root)->left == NULL)
				temp = (*root)->right;
			else
				temp = (*root)->left;

			*root = temp;
			return;
		}
		else
		{
			// if both children, take minimum of right side to replace root
			Node *temp = minNode((*root)->right);
			(*root)->data = temp->data;
			deleteNode(&(*root)->right, temp->data);
		}
	}
}

void preorder(Node *root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(Node *root)
{
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

void main()
{
	Node *root = NULL;

	insertNode(&root, 3);
	insertNode(&root, 5);
	insertNode(&root, 7);
	insertNode(&root, 9);
	insertNode(&root, 4);

	printf("\n--- PREORDER ---\n");
	preorder(root);
	printf("\n--- INORDER ---\n");
	inorder(root);
	printf("\n--- POSTORDER ---\n");
	postorder(root);

	deleteNode(&root, 7);
	printf("\n--- AFTER DELETION ---\n");
	inorder(root);
}