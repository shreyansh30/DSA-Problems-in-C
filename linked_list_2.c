#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertionat0(struct node **head, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = val;
    temp->next = *head;
    *head = temp;
    printf("Data inserted at the beginning.\n");
}
void insertionatn(struct node **head, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }
    printf("Data inserted at the end.\n");
}
void traverse(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int nodeCount(struct node *head)
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void searchElement(struct node *head, int val)
{
    struct node *temp = head;
    int found = 0;
    int position = 0;
    while (temp != NULL)
    {
        position++;
        if (temp->data == val)
        {
            printf("Element %d found at position %d\n", val, position);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("Element %d not found in the list.\n", val);
    }
}
void sortList(struct node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    struct node *i;
    struct node *j;
    int temp;
    for (i = *head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}
void reverseList(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List has been reversed.\n");
}
int main()
{
    printf("\n***MENU***\n");
printf("1. Insert data at first\n2. Insert data at last\n3. Search for an element\n4. Sort the list in ascending order\n5. Reverse the list\n6.Count number of nodes\n7. Traverse the list\n");
int n;
printf("Enter the number of values: ");
scanf("%d", &n);
struct node* head = NULL;
struct node* newnode;
struct node* temp;
for (int c = 1; c <= n; c++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
}
int choice, val;
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
    case 1:
        printf("Enter the data to be added: ");
        scanf("%d", &val);
        insertionat0(&head, val);
        traverse(head);
        break;
    case 2:
        printf("Enter the data to be added: ");
        scanf("%d", &val);
        insertionatn(&head, val);
        traverse(head);
        break;
    case 3:
        printf("Enter the element to search: ");
        scanf("%d", &val);
        searchElement(head, val);
        break;
    case 4:
        sortList(&head);
        traverse(head);
        break;
    case 5:
        reverseList(&head);
        traverse(head);
        break;
    case 6:
        printf("\nNumber of nodes present in list: %d\n",
               nodeCount(head));
        break;
    case 7:
        printf("Elements of the list are:\n");
        traverse(head);
        break;
    default:
        printf("Invalid choice.\n");
        break;
}
return 0;
}
