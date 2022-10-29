#include<stdio.h>
#include<stdlib.h>
#include "linked_lists.h"


int main()
{
    int n,i,item;

    printf("Enter size of list : ");
    scanf("%d",&n);

    Node* list = (Node*)calloc(n,sizeof(Node));
    list=NULL;

    printf("Enter numbers : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list=insertItem(list,item);
    }

    printf("List is : ");
    display(list);

    Node* oddIndex = NULL;
    Node* evenIndex = NULL;

    for(i=0;i<n;i++)
    {
        item=list->data;
        if(i%2==0)
            evenIndex=insertItem(evenIndex,item);
        else
            oddIndex=insertItem(oddIndex,item);

        list=list->next;
    }

    printf("\nOdd index list is : ");
    display(oddIndex);
    printf("\nEven index list is : ");
    display(evenIndex);
}
