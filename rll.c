#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head);

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf(" %d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = malloc(sizeof(struct ListNode)); 
    head->next->val = 2; 
    head->next->next = malloc(sizeof(struct ListNode)); 
    head->next->next->val = 3; 
    head->next->next->next = malloc(sizeof(struct ListNode)); 
    head->next->next->next->val = 4; 
    head->next->next->next->next = NULL;

    printf("Original list: ");
    printList(head); 

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head); 

    // free malloc'd memory
    struct ListNode* current = head;
    while (current) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}