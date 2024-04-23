#ifndef QUEUE
#define QUEUE

typedef unsigned long size_t;


typedef struct QueueNode {
    void* data;
    struct QueueNode* next;
} QueueNode;

// Define the structure for the stack
typedef struct {
    QueueNode* front_element;
    QueueNode* rear_element;
    size_t data_size; // Size of the data type
    int size;
} queue;

queue* initialize_queue(size_t data_size);
int is_empty(void* var);
void push(void* var, void* data);
void pop(void* var);
void* front(void* var);
void destroy_queue(void* var);

#endif