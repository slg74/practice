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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    push(&list1, 5);
    push(&list1, 3);
    push(&list1, 1);

    push(&list2, 6);
    push(&list2, 4);
    push(&list2, 2);

    print_list(list1);
    print_list(list2);

    struct Node* merged = merge_lists(list1, list2); 

    print_list(merged); 

    return 0;
}