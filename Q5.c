#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "linked_lists.h"
int main()
{
    int n,i,item;

    struct Node* list = NULL;

    int choice; 

    do
    {
        printf("1. Create a new linked list and display\n");
        printf("2. Delete elements equal to square of entered element\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter size of list : ");
            scanf("%d",&n);
            printf("Enter elements: \n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&item);
                list=insertItem(list,item);
            }
            printf("Entered list is : \n");
            display(list);
        }
        else if(choice==2)
        {
            if (list == NULL){
                printf("List empty\n");
                continue;
            }
            
            printf("Enter key: ");
            scanf("%d",&item);
            item*=item;
            deleteNode(&list, item);
        }
        else if(choice==3)
        {
            if (list == NULL){
                printf("List empty\n");
                continue;
            }
            printf("New list is : \n");
            display(list);
        }
    }while(choice!=4);

}
