#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "linked_lists.h"

int isVowel(char c) {
    switch(toupper(c)){
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return 1;
        default:
            return 0;
    }
}
charNode* create(char name[])
{
    int i;
    charNode* list=NULL;
    for(i=0;i<strlen(name);i++)
    {
        char item=name[i];

        charNode* ptr = (charNode*)malloc(sizeof(charNode));
        ptr->data=item;
        ptr->next=NULL;

        charNode* p = list;
        if(p==NULL)
            list=ptr;
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }

            p->next=ptr;
        }

    }
    return list;
}
void allVowels(charNode* head)
{
    charNode* ptr = head;

    while (ptr != NULL) {
        if (isVowel(ptr->data))
            ptr = ptr->next;
        else
            break;
    }
 
    charNode* prev = ptr;
    head = ptr;
 
    ptr = ptr->next;
 
    while (ptr != NULL) {

        if (isVowel(ptr->data)) {
            ptr = ptr->next;
            while (ptr != NULL) {
                if (isVowel(ptr->data)) {
                    ptr = ptr->next;
                }
                else
                    break;
            }
            if (ptr == NULL) {
                prev->next = NULL;
                break;
            }
            else {
                prev->next = ptr;
            }
        }
        prev = prev->next;
        ptr = ptr->next;
    }
    printf("Character list after removing vowels is : ");
    displayCh(head);
}
void main()
{
    char name[50];
    int i;

    printf("Enter a name : ");
    scanf("%s", name);

    charNode* list=NULL;
    list=create(name);

    printf("Character list is : ");
    displayCh(list);
    allVowels(list);
}
