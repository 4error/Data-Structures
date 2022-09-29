#include<stdio.h>
#include<stdlib.h>

struct rect {
    int length;
    int breadth;
};

int main(int argc, char const *argv[])
{
    struct rect *p;
    p = (struct rect *)malloc(sizeof(struct rect));
    p->length = 10;
    p->breadth = 5;
    printf("%d %d", p->length, p->breadth);
}

