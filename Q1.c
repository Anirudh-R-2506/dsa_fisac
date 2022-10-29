#include<stdio.h>
#include<stdlib.h>
#include "linked_lists.h"

void MoveNode(Node** destRef, Node** sourceRef)
{
    Node* newNode = *sourceRef;
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

Node* SortedMerge(Node* a, Node* b)
{
    Node temp;
    Node* l2 = &temp;
    temp.next = NULL;
    while (1) {
        if (a == NULL) {
            l2->next = b;
            break;
        }
        else if (b == NULL) {
            l2->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(l2->next), &a);
        else
            MoveNode(&(l2->next), &b);
 
        l2 = l2->next;
    }
    return (temp.next);
}
 

void main()
{
    int m,n,i,item;

    printf("Enter size of first list : ");
    scanf("%d",&m);

    printf("Enter size of second list : ");
    scanf("%d",&n);

    Node* list1=NULL;
    Node* list2=NULL;

    printf("Enter elements of first list in ascending order : \n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&item);
        list1=insertItem(list1,item);
    }

    printf("Enter elements of second list in ascending order : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list2=insertItem(list2,item);
    }

    printf("List 1 is : ");
    display(list1);

    printf("\nList 2 is : ");
    display(list2);

    printf("\nMerged list is : ");
    list1 = SortedMerge(list1, list2);
    display(list1);
}
