#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int val;
struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int input) {

    node* ptr = (node*) malloc((sizeof(node)));
    ptr->next = NULL;
    ptr -> val = input;
    if(front==NULL&&rear==NULL)
    {
        front = rear = ptr;
    }
    else{
        ptr ->next = front;
        front = ptr;
    }
    printf("\n\nEnqueued\n\n");
}
void dequeue() {

    if(front == NULL && rear == NULL){
        printf("\n\nQueue is empty\n\n");
        return;
    }
    if(front -> next == NULL)
    {
        free(front);
        front = rear = NULL;
        printf("\n\nDequeued\n\n");
        return;
    }
    node* ptr = front;
    while((ptr->next)->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr -> next = NULL;
    printf("\n\nDequeued\n\n");
}
void display() {

    if(front==NULL&&rear==NULL){
        printf("\n\nQueue is empty\n\n");
        return;
    }
    printf("Queue contains : ");
    node* ptr = front;
    do
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    } while(ptr!=NULL);
    printf("\n\n");
}
int main() {
    int choice, input;
    while(1) {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter -1 to quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == -1)
            break;
        switch(choice) {
        case 1:
            printf("Enter value to enqueue : ");
            scanf("%d", &input);
            enqueue(input);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\n\nWrong Input\n\n");
        }
    }
    return 0;
}