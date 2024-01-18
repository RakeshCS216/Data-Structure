#include <stdio.h>
#include <stdlib.h>


// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete the first element in the linked list
void deleteFirst(struct Node** head) {
    if (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a specified element in the linked list
void deleteElement(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        // Element not found
        return;
    }

    if (prev == NULL) {

        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}
//Function to delete the last element from linked list
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {

        *head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
}

// Function to display the contents of the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    struct Node* head = NULL;


    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Initial Linked List: ");
    displayList(head);


    deleteFirst(&head);
    printf("\nAfter deleting the first element: ");
    displayList(head);


    deleteElement(&head, 2);
    printf("\nAfter deleting the specified element (2): ");
    displayList(head);


    deleteLast(&head);
    printf("\nAfter deleting the last element: ");
    displayList(head);

    return 0;
}
