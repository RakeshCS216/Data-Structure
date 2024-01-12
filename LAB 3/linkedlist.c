#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void insert(struct Node **head, int data)
{
    struct Node *newnode = (struct Node *)malloc (sizeof(struct Node));

    newnode ->
    data = data;
    newnode ->
    next= *head;

    *head = newnode;
}

void display (struct Node *node)
{
  printf ("\nLinked List: ");
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf("\n");
}

void main()
{
    struct Node *head = NULL;
    insert(&head, 95);
    insert(&head, 85);
    insert(&head, 65);
    insert(&head, 45);
    insert(&head, 25);
    display(head);
}

