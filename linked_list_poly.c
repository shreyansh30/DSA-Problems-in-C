#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int c;
    int e;
    struct Node *next;
};
struct Node *createNode(int c, int e)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->c = c;
    newNode->e = e;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node **head, int c, int e)
{
    struct Node *newNode = createNode(c, e);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void displayPoly(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->c, temp->e);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
struct Node *addPolys(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    struct Node *temp2 = poly2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->e > temp2->e)
        {
            insertNode(&result, temp1->c, temp1->e);
            temp1 = temp1->next;
        }
        else if (temp1->e < temp2->e)
        {
            insertNode(&result, temp2->c, temp2->e);
            temp2 = temp2->next;
        }
        else
        {
            int sumCoef = temp1->c + temp2->c;
            insertNode(&result, sumCoef, temp1->e);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        insertNode(&result, temp1->c, temp1->e);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        insertNode(&result, temp2->c, temp2->e);
        temp2 = temp2->next;
    }
    return result;
}
int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    int n, coef, exp;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms (coefficient and exponent):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coef, &exp);
        insertNode(&poly1, coef, exp);
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms (coefficient and exponent):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coef, &exp);
        insertNode(&poly2, coef, exp);
    }
    printf("\nFirst Polynomial: ");
    displayPoly(poly1);
    printf("Second Polynomial: ");
    displayPoly(poly2);
    struct Node *sum = addPolys(poly1, poly2);
    printf("\nSum of Polynomials: ");
    displayPoly(sum);
    return 0;
}
