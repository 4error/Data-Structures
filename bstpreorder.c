//generating bst from preorder
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;

void createPre(int pre[], int n)
{
    stack stk;
    struct node *t;
    int i=0;
    root=(struct node *)malloc(sizeof(struct node));
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    stk.push(root);
    while(i<n){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=pre[i++];
        t->lchild=t->rchild=NULL;
        if(pre[i]<stk.top()->data){
            stk.top()->lchild=t;
            stk.push(t);
        }
        else{
            while(!stk.isEmpty() && pre[i]>stk.top()->data)
                p=stk.pop();
            p->rchild=t;
            stk.push(t);
        }
    }
}