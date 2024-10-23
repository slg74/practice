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

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    struct Node* head = NULL;

    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 

    print_list(head);
    reverse_list(&head); 
    print_list(head);

    return EXIT_SUCCESS;
}