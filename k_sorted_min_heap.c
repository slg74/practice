#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Min-heap structure
struct MinHeap {
    int size;
    struct ListNode **array;
};

// Function to create a new list node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to create a min heap of given size
struct MinHeap* createMinHeap(int size) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->array = (struct ListNode**)malloc(size * sizeof(struct ListNode*));
    return minHeap;
}

// Function to swap two nodes of min heap
void swapMinHeapNode(struct ListNode** a, struct ListNode** b) {
    struct ListNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to min heapify
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && 
        minHeap->array[left]->val < minHeap->array[smallest]->val)
        smallest = left;

    if (right < minHeap->size && 
        minHeap->array[right]->val < minHeap->array[smallest]->val)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to insert a node into min heap
void insertMinHeap(struct MinHeap* minHeap, struct ListNode* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->val < minHeap->array[(i - 1)/2]->val) {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }

    minHeap->array[i] = node;
}

// Function to extract minimum node from heap
struct ListNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size <= 0)
        return NULL;

    struct ListNode* root = minHeap->array[0];

    if (minHeap->size > 1) {
        minHeap->array[0] = minHeap->array[minHeap->size - 1];
        --minHeap->size;
        minHeapify(minHeap, 0);
    }
    else
        --minHeap->size;

    return root;
}

// Function to merge k sorted linked lists
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct MinHeap* minHeap = createMinHeap(listsSize);

    // Create the min heap with k heap nodes
    for (int i = 0; i < listsSize; ++i)
        if (lists[i] != NULL)
            insertMinHeap(minHeap, lists[i]);

    struct ListNode *dummy = newNode(0), *last = dummy;

    // Repeatedly extract the minimum
    while (minHeap->size != 0) {
        struct ListNode* curr = extractMin(minHeap);
        last->next = curr;
        last = last->next;

        if (curr->next != NULL)
            insertMinHeap(minHeap, curr->next);
    }

    return dummy->next;
}

// Utility function to print list
void printList(struct ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    int k = 3; // Number of linked lists
    struct ListNode* arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(4);
    arr[0]->next->next = newNode(5);

    arr[1] = newNode(1);
    arr[1]->next = newNode(3);
    arr[1]->next->next = newNode(4);

    arr[2] = newNode(2);
    arr[2]->next = newNode(6);

    struct ListNode* head = mergeKLists(arr, k);
    printf("Merged list:\n");
    printList(head);

    return 0;
}
