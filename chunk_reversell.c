#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
 
    *head = newNode;
}
 
// Iterative function to reverse first `k` nodes of a linked list
struct Node* reverseK(struct Node** current, int k)
{
    struct Node* prev = NULL;
    int count = 0;
 
    // iterate through the list and move/insert each node
    // in front of the result list (like a push of the node)
    while (*current && count++ < k)
    {
        // tricky: note the next node
        struct Node* next = (*current)->next;
 
        // move the current node onto the result
        (*current)->next = prev;
 
        // update the previous pointer to the current node
        prev = *current;
 
        // move to the next node in the list
        *current = next;
    }
 
    // return last processed node
    return prev;
}
 
// Function to reverse every group of `k` nodes in a given linked list
struct Node *reverseInGroups(struct Node *head, int k)
{
    // base case
    if (head == NULL) {
        return NULL;
    }
 
    // start with the current node
    struct Node* current = head;
 
    // reverse next `k` nodes
    struct Node* prev = reverseK(&current, k);
 
    // recur for remaining nodes
    head->next = reverseInGroups(current, k);
 
    // it is important to return the previous node (to link every group of `k` nodes)
    return prev;
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }
 
    head = reverseInGroups(head, 3);
 
    printList(head);
 
    return 0;
}
