#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Function to create a new stack node
StackNode* create_node(void* data, size_t data_size) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
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

// Function to initialize a stack
stack* initialize_stack(size_t data_size) {
    stack* stack_var = (stack*)malloc(sizeof(stack));
    if (stack_var == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack_var->top_element = NULL;
    stack_var->data_size = data_size;
    return stack_var;
}

// Function to check if the stack is empty
int is_empty(void* var) {
    stack *stack_var = (stack *)(var);
    return stack_var->top_element == NULL;
}

// Function to push an element onto the stack
void push(void* var, void* data) {
    stack *stack_var = (stack *)(var);
    StackNode* new_node = create_node(data, stack_var->data_size);
    new_node->next = stack_var->top_element;
    stack_var->top_element = new_node;
}

// Function to pop an element from the stack
void pop(void* var) {
    stack *stack_var = (stack *)(var);
    if (is_empty(stack_var)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    StackNode* temp = stack_var->top_element;
    stack_var->top_element = temp->next;
    free(temp->data);
    free(temp);
}

// Function to get the top element of the stack without removing it
void* top(void* var) {
    stack *stack_var = (stack *)(var);
    if (is_empty(stack_var)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    void *peeked_data = malloc(stack_var -> data_size);
    // return (void *)stack -> top -> data;
    memcpy(peeked_data, stack_var->top_element->data, stack_var->data_size);
    return peeked_data;
}

// Function to free memory allocated for the stack
void destroy_stack(void* var) {
    stack *stack_var = (stack *)(var);
    while (!is_empty(stack_var)) {
        StackNode* temp = stack_var->top_element;
        stack_var->top_element = temp->next;
        free(temp->data);
        free(temp);
    }
    free(stack_var);
}

int main() {
    // Example usage for integers
   
    return 0;
}
