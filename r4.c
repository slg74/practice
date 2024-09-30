#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void reverse_list(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* cur = *head;
    struct Node* next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

int main() {
    struct Node* head = NULL;

    push(&head, 4);
    push(&head, 3); 
    push(&head, 2);
    push(&head, 1);

    printf("Forward:  ");
    print_list(head);

    reverse_list(&head);
    printf("Reversed: ");
    print_list(head); 

    return 0;
}