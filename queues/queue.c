#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Function to create a new queue node
QueueNode* create_node(void* data, size_t data_size) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = malloc(data_size);
    if (new_node->data == NULL) {
        printf("Memory allocation failed.\n");
        free(new_node);
        exit(1);
    }
    memcpy(new_node->data, data, data_size);
    new_node->next = NULL;
    return new_node;
}

// Function to initialize a queue
queue* initialize_queue(size_t data_size) {
    queue* queue_var = (queue*)malloc(sizeof(queue));
    if (queue_var == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue_var->front_element = NULL;
    queue_var->rear_element = NULL;
    queue_var->size = 0;
    queue_var->data_size = data_size;
    return queue_var;
}

// Function to check if the queue is empty
int is_empty(void* var) {
    queue *queue_var = (queue *)(var);
    return (queue_var->size == 0);
}

int size(void *var) {
    queue *queue_var = (queue *)(var);
    return queue_var -> size;
}

// Function to push an element onto the queue
void push(void* var, void* data) {
    queue *queue_var = (queue *)(var);
    if(is_empty(queue_var)) {
        QueueNode* new_node = create_node(data, queue_var->data_size);
        queue_var->front_element = new_node;
        queue_var->rear_element = new_node;
        queue_var->size++;    
    }
    else {
        QueueNode* new_node = create_node(data, queue_var->data_size);
        queue_var->rear_element->next = new_node;
        queue_var->rear_element = new_node;
        queue_var->size++;    
    }
    
}

// Function to pop an element from the queue
void pop(void* var) {
    queue *queue_var = (queue *)(var);
    if (is_empty(queue_var)) {
        printf("queue underflow.\n");
        exit(1);
    }
    QueueNode* temp = queue_var->front_element;
    queue_var->front_element = temp->next;
    queue_var->size--;
    free(temp->data);
    free(temp);
}

// Function to get the top element of the queue without removing it
void* front(void* var) {
    queue *queue_var = (queue *)(var);
    if (is_empty(queue_var)) {
        printf("queue is empty.\n");
        exit(1);
    }
    void *peeked_data = malloc(queue_var -> data_size);
    // return (void *)queue -> top -> data;
    memcpy(peeked_data, queue_var->front_element->data, queue_var->data_size);
    return peeked_data;
}

// Function to free memory allocated for the queue
void destroy_queue(void* var) {
    queue *queue_var = (queue *)(var);
    while (!is_empty(queue_var)) {
        QueueNode* temp = queue_var->front_element;
        queue_var->front_element = temp->next;
        free(temp->data);
        free(temp);
    }
    free(queue_var);
}

int main() {
    // Example usage for integers
   // Example usage for integers
    queue* intQueue = (queue*)initialize_queue(sizeof(int));

    int intData1 = 10;
    int intData2 = 20;
    int intData3 = 30;
    push(intQueue, &intData1);
    push(intQueue, &intData2);
    push(intQueue, &intData3);

    printf("Integer Queue elements: ");
    int* element;
    while (!is_empty(intQueue)) {
        element = (int *)front(intQueue);
        printf("%d ", *element);
        pop(intQueue);
        free(element); // Free memory allocated for peeked data
    }
    printf("\n");

    destroy_queue(intQueue);

    // Example usage for strings
    queue* strQueue = (queue*)initialize_queue(sizeof(char*)); // Assuming max string length is 20

    char* strData1 = "Hello";
    char* strData2 = "World";
    char* strData3 = "Queue";
    push(strQueue, strData1);
    push(strQueue, strData2);
    push(strQueue, strData3);

    printf("String Queue elements: ");
    char* poppedStr; 
    while (!is_empty(strQueue)) {
        poppedStr = (char *)front(strQueue);
        printf("%s ", poppedStr);
        pop(strQueue);
        free(poppedStr); // Free memory allocated for peeked data
    }
    printf("\n");

    destroy_queue(strQueue);

    return 0;
    return 0;
}
