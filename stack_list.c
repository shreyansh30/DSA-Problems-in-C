#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* top = NULL;

int push(int value)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = top;
    top = newnode;
}

int pop()
{
    struct node* temp = top;
    if (top == NULL)
    {
        printf("Underflow! Stack is empty\n");
    }
    else {
        printf("Data %d is deleted!",top->data);
        top = top->next;
        free(temp);
    }
}

int peek()
{
    if (top == NULL)
    {
        printf("Underflow!Stack is empty");
    }
    else
    {
        printf("%d\n",top->data);
    }
}

int isFull()
{
    if (top==NULL)
    {
        printf("FALSE\n");
    }
    else printf("TRUE\n");
    
}

int isEmpty()
{
    if (top==NULL)
    {
        printf("TRUE\n");
    }
    else printf("FALSE\n");  
}

int display()
{
    struct node* temp = top;
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        while(temp != NULL) 
        {
        printf("%d ",temp->data);
        temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice,data;
    
    printf("MENU\n");
    printf("1. Push elements in stack\n");
    printf("2. Pop elements in stack\n");
    printf("3. Peek in stack\n");
    printf("4. Diplay elements of stack\n");
    printf("5. IsEmpty?\n");
    printf("6. IsFull?\n");
    printf("7. Exit\n");
    printf("--> ");
    scanf("%d",&choice);
    
    while (choice != 7)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the value to push in stack : ");
            scanf("%d",&data);
            push(data);
            printf("--> ");
            scanf("\n%d",&choice);
            break;
        case 2:
            pop();
            printf("--> ");
            scanf("\n%d",&choice);
            break;
        case 3:
            peek();
            printf("--> ");
            scanf("\n%d",&choice);
            break;
        case 4:
            display();
            printf("--> ");
            scanf("\n%d",&choice);
            break;
        case 5:
            isEmpty();
            printf("--> ");
            scanf("\n%d",&choice);
            break;
        case 6:
            isFull();
            printf("--> ");
            scanf("\n%d",&choice);
            break;
        default:
            break;
        }    
    }
}

