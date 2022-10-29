#include<stdio.h>
#include<stdlib.h>
#include "linked_lists.h"
void main()
{
    int n,i,item;

    printf("Enter n : ");
    scanf("%d",&n);

    Node* list = (Node*)calloc(n,sizeof(Node));
    Node* first = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));

    first=list;
    list->data=0;
    second->data=1;
    second->next=NULL;
    list->next=second;
    
    for(i=2;i<n;i++)
    {
        item = (first->data) + (second->data);
        list=insertItem(list,item);
        first=first->next;
        second=second->next;
    }

    printf("Fibonacci Series : \n");
    display(list);
}
