#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linked_lists.h"

int isPalin(char str[])
{
    int i,j,flag=1;
    for(i=0,j=strlen(str)-1;i<=j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            flag=0;
            break;
        }
    }
    return flag;
}
void main()
{
    int n,i;
    char s[50],temp[50];

    printf("Enter size of list : ");
    scanf("%d",&n);

    strNode* list=NULL;

    printf("Enter words : ");
    for(i=0;i<n;i++)
    {
        scanf(" %s",s);
        list=insertStr(list,s);
    }

    printf("\nList is : ");
    displayChar(list);

    strNode* palindromeList=NULL;
    strNode* notApalindromeList=NULL;

    for(i=0;i<n;i++)
    {
        strcpy(temp,list->data);
        if(isPalin(temp))
            palindromeList=insertStr(palindromeList,temp);
        else
            notApalindromeList=insertStr(notApalindromeList,temp);

        list=list->next;
    }

    printf("\nPalindrome List : ");
    displayChar(palindromeList);

    printf("\nNon Palindrome List : ");
    displayChar(notApalindromeList);
}
