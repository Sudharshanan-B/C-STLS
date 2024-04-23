#ifndef STACK
#define STACK

typedef unsigned long size_t;


typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

// Define the structure for the stack
typedef struct {
    StackNode* top_element;
    size_t data_size; // Size of the data type
    int size;
} stack;

stack* initialize_stack(size_t data_size);
int is_empty(void* var);
void push(void* var, void* data);
void pop(void* var);
void* top(void* var);
void destroy_stack(void* var);

#endif