#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge_lists(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    struct Node* head = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            head->next = list1;
            list1 = list1->next;
        } else {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }
    if (list1) head->next = list1;
    if (list2) head->next = list2;

    return dummy.next;
}

void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof (struct Node));
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

void remove_item(struct Node** head, int key) {
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

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    push(&list1, 6);
    push(&list1, 4);
    push(&list1, 2);
    print_list(list1);

    push(&list2, 5);
    push(&list2, 3);
    push(&list2, 1);
    print_list(list2);

    struct Node* merged = merge_lists(list1, list2); 
    print_list(merged);
    remove_item(&merged, 5); 
    print_list(merged); 

    return 0;
}