/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define MAX 3

void enqueue(int data);
void check(int data);
void dequeue();
void display();

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {

    if(rear >= MAX-1) {
        printf("\n\nQueue is full!\n\n");
        return;
    }
    if(rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = data;
        return;
    }
    check(data);
    rear++;
}

void check(int data) {
    int i, j;
    for(i = 0; i<=rear;i++) {
        if(data<=queue[i]) {
            for(j = rear+1; j>i;j--) {
                queue[j] = queue[j-1];
            }
            queue[i] = data;
            return;
        }
    }
    queue[i] = data;
}

void dequeue() {
    if(front == -1) {
        printf("\n\nQueue is empty!!\n\n");
        return;
    }
    int dequeued = queue[front];
    if(front == rear)
        front = rear= -1;
    else
        front++;
    printf("\n\n%d was dequeued\n\n", dequeued);
}

void display() {
    if(front == -1) {
        printf("\n\nQueue is empty!!\n\n");
        return;
    }
    int i = 0;
    printf("\n\nQueue contains : ");
    for(i = front;i<=rear;i++) {
        printf("%d  ", queue[i]);
    }
    printf("\n\n");
}

void main() {

    int choice, input;
    while(1) {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter -1 to quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice==-1)
            break;

        switch(choice) {
            case 1:
                printf("\n\nEnter element to be enqueued : ");
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
            printf("\n\nWrong Choice!!\n\n");
        }
    }
    printf("\n\n-----DONE-----\n\n");
}
