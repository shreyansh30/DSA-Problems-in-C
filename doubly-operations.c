#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int info) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->info = info;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertNode(Node** head, int info, int pos) {
    Node* newNode = createNode(info);
    if (*head == NULL || pos == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        Node* current = *head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
            if (current == NULL) {
                printf("Position out of range\n");
                return;
            }
        }
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteNode(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    } else {
        Node* current = *head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
            if (current == NULL || current->next == NULL) {
                printf("Position out of range\n");
                return;
            }
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = current;
        }
        free(temp);
    }
}

void traverseList(Node* head) {
    Node* current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, info, pos;

    while (1) {
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &info);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insertNode(&head, info, pos);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteNode(&head, pos);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}