// question - how would you implement malloc()? 
#include <unistd.h>
#include <string.h>

struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
    int magic;    // For debugging
};

#define META_SIZE sizeof(struct block_meta)

void *global_base = NULL;

struct block_meta *find_free_block(struct block_meta **last, size_t size) {
    struct block_meta *current = global_base;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

// request a chunk of memory from the OS using sbrk() or mmap()
struct block_meta *request_space(struct block_meta* last, size_t size) {
    struct block_meta *block;
    block = sbrk(0);
    void *request = sbrk(size + META_SIZE);
    if (request == (void*) -1) {
        return NULL; // sbrk failed.
    }
    
    if (last) { // NULL on first request.
        last->next = block;
    }
    block->size = size;
    block->next = NULL;
    block->free = 0;
    block->magic = 0x12345678;
    return block;
}

// maintain a linked list of free memory blocks
void *my_malloc(size_t size) {
    struct block_meta *block;
    
    if (size <= 0) {
        return NULL;
    }
    
    if (!global_base) { // First call.
        block = request_space(NULL, size);
        if (!block) {
            return NULL;
        }
        global_base = block;
    } else {
        struct block_meta *last = global_base;
        block = find_free_block(&last, size);
        if (!block) { // Failed to find free block.
            block = request_space(last, size);
            if (!block) {
                return NULL;
            }
        } else {      // Found free block
            block->free = 0;
            block->magic = 0x77777777;
        }
    }
    
    return(block+1);
}

void my_free(void *ptr) {
    if (!ptr) {
        return;
    }
    
    // TODO: consider merging blocks once splitting blocks is implemented.
    struct block_meta* block_ptr = (struct block_meta*)ptr - 1;
    if (block_ptr->magic != 0x77777777) {
        return;  // Invalid free
    }
    block_ptr->free = 1;
    block_ptr->magic = 0x55555555;
}


int main() {
    printf("Testing custom malloc implementation\n");

    // Allocate memory for an integer
    int *p = (int*)my_malloc(sizeof(int));
    if (p == NULL) {
        printf("Failed to allocate memory for int\n");
        return 1;
    }
    *p = 42;
    printf("Allocated int: %d\n", *p);

    // Allocate memory for a string
    char *str = (char*)my_malloc(20 * sizeof(char));
    if (str == NULL) {
        printf("Failed to allocate memory for string\n");
        return 1;
    }
    strcpy(str, "Hello, World!");
    printf("Allocated string: %s\n", str);

    // Free the allocated memory
    my_free(p);
    my_free(str);

    // Try to allocate a large chunk of memory
    void *large_chunk = my_malloc(1000000);
    if (large_chunk == NULL) {
        printf("Failed to allocate large chunk of memory\n");
    } else {
        printf("Successfully allocated large chunk of memory\n");
        my_free(large_chunk);
    }

    printf("Memory allocation test completed\n");
    return 0;
}

