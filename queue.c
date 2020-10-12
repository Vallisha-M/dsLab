#include <stdio.h>
#define MAX 5

void display();
void enqueue(int x);
void dequeue();

int queue[MAX];
int rear = -1;
int front = -1;

void enqueue(int x)
{
    if(rear == MAX-1)
        printf("\n\nQueue is Full\n\n");
    else
    {
        if(front==-1)
            front = 0;
        queue[++rear] = x;
        printf("\n\n%d is put in queue\n\n",x);
    }
}

void dequeue()
{
    int x;
    if(rear==-1)
        printf("\n\nQueue is empty\n\n");
    else
    {
        x = queue[rear];
        rear--;
        printf("\n\n%d was removed from queue\n\n", x);
    }
}

void display()
{
    int i = 0;
    if(rear == -1)
        printf("\n\nQueue is empty\n\n");
    else
    {
        printf("Queue contains : ");
        for(i = front;i<=rear;i++)
        {
            printf("%d  ",queue[i]);
        }
        printf("\n\n\n");
    }
}
int main()
{
    int ele, ch = 0;

    while(1)
    {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter -1 to quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==-1)
            break;
        switch(ch)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\n\nInvalid Input\n\n");
            break;
        }
    }
    printf("\n\n\n----DONE----\n\n\n");
}
