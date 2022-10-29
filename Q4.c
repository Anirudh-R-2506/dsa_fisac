#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[50];
    int roll;
    int marks;
    struct node* next;
}node;

node* insertRecord(node* list, char *name, int roll, int marks){
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->roll = roll;
    temp->marks = marks;
    temp->next = NULL;
    if(list==NULL){
        list = temp;
    }
    else{
        node* ptr = list;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next = temp;
    }
    return list;
}

void display(node* list){
    node* ptr = list;
    while(ptr!=NULL){
        printf("%s %d %d",ptr->name,ptr->roll,ptr->marks);
        ptr=ptr->next;
        printf("\n");
    }
}

void swap(struct node *a, struct node *b) 
{ 
    char temp[50];
    int temp1;
    int temp2;
    strcpy(temp,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp);
    temp1=a->roll;
    a->roll=b->roll;
    b->roll=temp1;
    temp2=a->marks;
    a->marks=b->marks;
    b->marks=temp2;
} 

void sortByMarks(struct node *start) 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
    if (start == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->marks > ptr1->next->marks) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

void getSecondHighestMarks(node* list){
    node* ptr = list;
    int max = 0;
    int secondMax = 0;
    char name[50];
    int roll;
    while(ptr!=NULL){
        if(ptr->marks > max){
            secondMax = max;
            max = ptr->marks;
        }
        else if(ptr->marks > secondMax){
            secondMax = ptr->marks;
        }        
        ptr=ptr->next;
    }
    ptr = list;
    while(ptr!=NULL){
        if(ptr->marks == secondMax){
            strcpy(name,ptr->name);
            roll = ptr->roll;
            break;
        }
        ptr=ptr->next;
    }

    printf("Record with second highest marks: \n");
    printf("%s %d %d\n",name,roll,secondMax);
}

int main(){
    int n, i;
    char name[50];
    int roll;
    int marks;
    printf("Enter size of list : ");
    scanf("%d",&n);
    node* list = (node*)calloc(n,sizeof(node));
    list=NULL;
    printf("Enter student records: ");
    for(i=0;i<n;i++){
        printf("\nStudent %d\n",i+1);
        scanf("%s %d %d",name,&roll,&marks);
        list=insertRecord(list,name,roll,marks);
    }
    sortByMarks(list);
    getSecondHighestMarks(list);
}