#include <stdio.h>
#include <stdlib.h>


struct Node {
    int key;
    struct Node* next;
};

struct Node* head;
struct Node* t;
struct Node* z;

void initialize_list() {
    head = (struct Node*)malloc(sizeof *head);
    z = (struct Node*)malloc(sizeof *z);
    head->next = z;
    z->next = z;
}

void delete_next(struct Node* t) {
    t->next = t->next->next;
}

struct Node* insert_after(int v, struct Node* t) {
    struct Node* x;
    x = (struct Node*)malloc(sizeof *x);
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

void reverse_list() {
    struct Node* prev = z;
    struct Node* cur = head->next;
    struct Node* next; 

    while (cur != z) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head->next = prev;
}

void print_list(const char* message) {
    printf("%s", message); 
    struct Node* current = head->next;
    while (current != z) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

void print_list_from_head(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf(" %d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_list_from_head(struct Node** head) {
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

void push(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = data;
    new_node->next = *head;
    *head = new_node;
}

int main() {
    initialize_list();

    struct Node* current = head;
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    print_list_from_head(head); 
    reverse_list_from_head(&head);
    print_list_from_head(head); 

    current = insert_after(1, current); 
    current = insert_after(2, current); 
    current = insert_after(3, current); 
    current = insert_after(4, current); 

    print_list("Original list: ");

    reverse_list(); 

    print_list("Reversed list: ");

    return EXIT_SUCCESS;
}
