#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node Node;

Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

Node *insert(Node **head, int data, int position)
{
	if (position <= 0)
	{
		printf("\nERROR | Invalid position.");
		return NULL;
	}

	Node *newNode = createNode(data);
	Node *current = *head;

	if (position == 1 || current == NULL)
	{
		// if the list is empty or to insert at front
		newNode->next = *head;
		if (*head != NULL)
			(*head)->prev = newNode;
		*head = newNode;
	}
	else
	{
		// insert at position
		for (int i = 1; i < position - 1 && current->next != NULL; i++)
			// while i is less than position and next is not null
			current = current->next;

		newNode->next = current->next;
		if (current->next != NULL)
			current->next->prev = newNode;

		current->next = newNode;
		newNode->prev = current;
	}
}

void delete(Node **head, int position)
{
	if (*head == NULL || position <= 0)
	{
		printf("\nERROR | Invalid position.");
		return;
	}

	Node *current = *head;

	if (position == 1)
	{
		// delete at front
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
	}
	else
	{
		// delete at position
		for (int i = 1; i < position + 1 && current->next != NULL; i++)
			current = current->next;

		if (current == NULL)
		{
			printf("\nERROR | Invalid position.");
			return;
		}

		if (current->prev != NULL)
			current->prev->next = current->next;
		else
			*head = current->next;

		if (current->next != NULL)
			current->next->prev = current->prev;

		free(current);
	}
}

void traverse(Node *head)
{
	printf("\n--- LINKED LIST ---\n");
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void main()
{
	Node *head = NULL;

	insert(&head, 1, 1);
	insert(&head, 2, 2);
	insert(&head, 3, 3);

	traverse(head);

	delete (&head, 2);
	delete (&head, 1);

	traverse(head);
}