
#include <stdio.h>


typedef struct node {
int val;
struct node* next;
}node;

node* head = NULL;

void push(int value) {

    node* ptr = (node*) malloc((sizeof(node)));
    ptr -> val = value;
    ptr->next = head;
    head = ptr;
    printf("\n\nPushed\n\n");
}

int pop() {

    if(head == NULL)
        return -1;
    else{
        node* tmp = head->next;
        free(head);
        head = tmp;
        return 0;
    }
}

void display() {

    if(head == NULL) {
        printf("\n\nStack is Empty\n\n");
        return;
    }
    printf("\n\nStack contains : ");
    node* ptr = head;
    while(ptr !=NULL) {
        printf("%d  ", ptr->val);
        ptr = ptr -> next;
    }
    printf("\n\n");
}
int main() {

    int value, status, choice;
    while(1) {

        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter -1 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == -1)
            break;
        switch(choice) {
        case 1:
            printf("Enter value to push : ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            status = pop();
            if(status == 0)
                printf("\n\nPopped\n\n");
            else
                printf("\n\nStack Underflow\n\n");
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


