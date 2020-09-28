#include <stdio.h>
#define MAX 3

void push(int x);
void pop();
void display();

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top==MAX-1)
        printf("\nStack Overflow\n\n");
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int x;
    if(top==-1)
        printf("\nStack is Empty\n\n");
    else
    {
        x = stack[top];
        printf("\nElement deleted from stack : %d\n\n", x);
        top--;
    }
}
void display()
{
    int i;
    if(top==-1)
        printf("\nStack is Empty\n\n");
    else
    {
        printf("\nThe elements  are : ");
        for(i=top;i>=0;i--)
            printf("%d  ", stack[i]);
        printf("\n\n");
    }
}
void main()
{
    int c, x;
    while(1)
    {
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter -1 to quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        if(c==-1)
            break;
        switch(c)
        {
            case 1:
                printf("\nEnter number to push : ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("\nInvalid Choice\n\n");
                break;
        }
    }
    return 0;
}
