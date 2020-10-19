#include <stdio.h>
#define size 4

void enqueue(int);
void dequeue();
void display();

int front=-1, rear=-1;
int queue[size];

void enqueue(int input)
{
    if((front==0&&rear==size-1)||(rear==front-1))
        printf("\n\Queue is full\n\n");
    else
    {
        if(front==-1&&rear==-1)
            front = rear = 0;
        else if(rear==size-1)
            rear = 0;
        else
            rear++;
        queue[rear] = input;
    }
    printf("\n\n");
}

void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("\n\nQueue is empty\n\n");
        return;
    }
    int output = queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front = (front+1)%size;
    printf("\n\n%d was dequeued\n\n", output);

}

void display()
{

    if(front==-1&&rear==-1)
    {
        printf("\n\nQueue is empty\n\n");
        return;
    }
    int i = 0;
    printf("\n\nQueue contains : ");
    if(front<=rear)
    {
        for(i = front; i<=rear; i++)
            printf("%d", queue[i]);
    }
    else
    {
        for(i = front; i<= rear; i = (i+1)%size)
            printf("%d", queue[i]);
    }
    printf("\n\n");
}
int main()
{
    int choice, input;
    while(1)
    {
        choice = 0;
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter -1 to quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice==-1)
            break;
        switch(choice)
        {
            case 1:
                printf("\n\nEnter the element to be enqueued : ");
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
                break;
        }
    }
    printf("\n\n-----DONE----\n\n");
    return 0;
}
