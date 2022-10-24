//rescursive insert and delete in bst

#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;

void Inorder(struct node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct node *Search(int key) {
    struct node *t=root;
    while(t!=NULL){
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

struct node * rinsert(struct node *p, int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }

    //if it is less than root's data, recursive call on lchild.
    if(key<p->data)
        p->lchild=rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=rinsert(p->rchild,key);
    return p;
}

int height(struct node *p) {
    int x,y;
    if(p==NULL)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

struct node * InPre(struct node *p) {
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}

struct node * InSucc(struct node *p) {
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

struct node * rdelete(struct node *p, int key)
{
    struct node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
        p->lchild=rdelete(p->lchild,key);
    else if(key>p->data)
        p->rchild=rdelete(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=rdelete(p->lchild,q->data);
        }
        else
        {
            q=Insuc(p->rchild);
            p->data=q->data;
            p->rchild=rdelete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    struct node *temp;
    root=rinsert(root,10);
    rinsert(root,5);
    rinsert(root,20);
    rinsert(root,8);
    rinsert(root,30);

    Inorder(root);
    printf("\n");

    temp=Search(20);
    if(temp!=NULL)
        printf("element %d is found\n",temp->data);
    else
        printf("element is not found\n");
    return 0;
}