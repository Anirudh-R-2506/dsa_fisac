#include<stdio.h>
#include<stdlib.h>
#include "linked_lists.h"

void rotate(Node** head_ref, int k)
{
    Node* current = *head_ref;
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;
    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;
    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}
void main()
{
    int n,i,k,item;

    printf("Enter size : ");
    scanf("%d",&n);

    Node* list=NULL;
    Node* list2=NULL;

    printf("Enter elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list=insertItem(list,item);
        list2=insertItem(list2,item);
    }
    printf("\nNmber of times to rotate <=%d : ",n);
    scanf("%d",&k);
    rotate(&list, n-k);
    printf("Right Rotate: \n");
    display(list);
    printf("\n");
    rotate(&list2, k);
    printf("\nLeft Rotate: \n");
    display(list2);
    printf("\n");

}
