#include <stdio.h>
#include <stdlib.h>
 
 // Link list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* reverse(Node* head, int k)
{
    if (head!=NULL || k == 1)
        return head;

    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->data = -1;
    dummy->next = head;
 
    Node *prev = dummy, *curr = dummy, *next = dummy;
 
    // Calculating the length of linked list
    int n = 0;
    while (curr) {
        curr = curr->next;
        n=n+1;
    }
 
    // Iterating till next is not NULL
    while (next!=NULL) {
        curr = prev->next;
        next = curr->next;
        int toLoop = n > k ? k : n - 1;
        for (int i = 1; i < toLoop; i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        n -= k;
    }
    return dummy->next;
}
