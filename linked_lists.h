#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct strNode
{
    char data[100];
    struct strNode* next;
}strNode;

typedef struct charNode
{
    char data;
    struct charNode* next;
}charNode;

typedef struct nameList
{
    char data[100];
    int occurence;
    struct nameList* next;
}nameList;

Node* insertItem(Node* head, int item)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data=item;
    ptr->next=NULL;

    Node* p = head;

    if(p==NULL)
        return ptr;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    return head;
}

strNode* insertStr(strNode* head, char item[])
{
    strNode* ptr = (strNode*)malloc(sizeof(strNode));
    strcpy(ptr->data, item);
    ptr->next=NULL;

    strNode* p = head;

    if(p==NULL)
        return ptr;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    return head;
}



void display(Node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayChar(strNode *ptr){
    while (ptr!=NULL)
    {
        printf("%s ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayList(nameList *ptr){
    while (ptr!=NULL)
    {
        printf("%s ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayListOcc(nameList *ptr){
    while (ptr!=NULL)
    {
        printf("%s->%d ",ptr->data, ptr->occurence);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayCh(charNode *ptr){
    while (ptr!=NULL)
    {
        printf("%c ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteNode(Node** head_ref, int key)
{
    Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
