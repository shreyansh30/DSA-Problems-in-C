#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int insertionat0(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp -> data = val;
        temp -> next = head;
        head = temp;
        printf("Data inserted\n");
    }
    traverse(head,temp); 
}

int insertionatn(struct node* head,int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = val;
    temp -> next = NULL;
    if (head == NULL)
        head = temp;
    else {
        struct node* last = head;
        while (last -> next != NULL)
        {
            last = last->next;
        }
        last -> next = temp;
        
    }
    traverse(head,temp);
}



int traverse(struct node* head, struct node* temp) {
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

int nodeCount(struct node* head,struct node* temp) {
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        temp = temp -> next;
        count++;
    }
    return count;
}

int main() {
    
    printf("\n***MENU***\n");
    printf("1. Insert data at first \n2. Insert data at last\n3. Insert data at specific position\n4. Delete data at first \n5. Delete data at last\n6. Delete data at specific position\n7. Count number of nodes\n8. Traverse the list\n");
    
    int c=1,n;

    printf("Enter the number of values : ");
    scanf("%d",&n);

    struct node* head, *newnode, *temp;
    head = 0;
    while (c <= n) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&newnode -> data);
        newnode -> next = 0;
        if (head == 0)
            head = temp = newnode;
        else
            temp -> next = newnode;
            temp = newnode;
        c++;
    }

    int choice,val;
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter the data to be added : ");
        scanf("%d",&val);
        insertionat0(head,val);
        break;
    case 2:
        printf("Enter the data to be added : ");
        scanf("%d",&val);
        insertionatn(head,val);
        break;
    case 7:
        printf("\n Number of nodes present in list : %d ",nodeCount(head,temp));
        break;
    case 8:
        printf("Elements of lists are : \n");
        traverse(head,temp);
        break;
    }
    
      
}