#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

Node* createNode(int info) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int info) {
    Node* newNode = createNode(info);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

void displayList(Node* head) {
    Node* current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d ", current->info);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, info;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter info of node%d: ", i);
        scanf("%d", &info);
        insertNode(&head, info);
    }

    printf("Circular Linked List: ");
    displayList(head);

    return 0;
}
