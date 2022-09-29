#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*first;

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void createLL(int a[], int  n)
{
    struct node *p, *temp;
    //creating first node
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    temp=first;

    for(int i=1; i<n; i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=a[i];
        p->next=NULL;
        temp->next=p;
        temp=p;
    }
  
}

int main()
{
    int a[] = {1, 4, 5, 6};
    createLL(a, 4);
    display(first);
    return 0;
}