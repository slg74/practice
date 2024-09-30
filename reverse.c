#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void reverse_list(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
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
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void remove_node(struct Node** head, int key) {
    struct Node** current = head;
    while (*current) {
        if ((*current)->data == key) {
            struct Node* temp = *current;
            *current = (*current)->next;
            free(temp);
            return;
        }
        current = &((*current)->next); 
    }
}

int main() {
    struct Node* head = NULL;

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    print_list(head);
    reverse_list(&head);
    print_list(head);

    remove_node(&head, 4);
    print_list(head);

    return 0;
}