#include <stdio.h>
#include <stdlib.h>

struct Node {
    char val;
    struct Node* next;
};

void print_list(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        printf("%c\n", cur->val);
        cur = cur->next;
    }
}

struct Node* reverse_list(struct Node* head) {
    struct Node* cur = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main() {
    struct Node* a = malloc(sizeof(struct Node));
    struct Node* b = malloc(sizeof(struct Node));
    struct Node* c = malloc(sizeof(struct Node));
    struct Node* d = malloc(sizeof(struct Node));

    a->val = 'A';
    b->val = 'B';
    c->val = 'C';
    d->val = 'D';

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    printf("Original list:\n"); 
    print_list(a);

    printf("Reversed list:\n"); 
    struct Node* reversed = reverse_list(a);
    print_list(reversed); 

    free(a); 
    free(b); 
    free(c); 
    free(d); 

    return 0;
}

