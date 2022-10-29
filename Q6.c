#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "linked_lists.h"
int power(int a, int b){
    int res=a;
    while(--b > 0){
        res*=a;
    }
    return res;
}
void main()
{
    int n,i,item;

    printf("Enter size : ");
    scanf("%d",&n);
    Node* list = (Node*)calloc(n,sizeof(Node));
    list=NULL;
    printf("Enter numbers : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list=insertItem(list,item);
    }
    printf("\nEntered list : ");
    display(list);

    Node* odd=NULL;
    Node* even=NULL;

    for(i=0;i<n;i++)
    {
        item=list->data;
        if(item%2==0)
            even=insertItem(even,power(item,3));
        else
            odd=insertItem(odd,power(item,3));

        list=list->next;
    }

    printf("\nOdd list : \n");
    display(odd);
    printf("\nEven list : \n");
    display(even);
}
