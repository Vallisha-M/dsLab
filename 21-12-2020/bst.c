#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST* left;
    struct BST* right;
}node;

node* create(int data) {
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

void insert(node* root, node* temp) {
    if(temp->data<root->data) {
        if(root->left!=NULL)
            insert(root->left, temp);
        else
            root->left = temp;
    }
    else {
        if(root->right!=NULL)
            insert(root->right, temp);
        else
            root->right = temp;
    }
}

void inorder(node* root) {
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(node* root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void main() {
    int choice, data;
    node *root = NULL;
    while(1) {
        printf("Enter 1 to add\n");
        printf("Enter 2 for inorder\n");
        printf("Enter 3 for preorder\n");
        printf("Enter 4 for postorder\n");
        printf("Enter -1 for quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == -1) {
            break;
        }
        switch(choice) {
            case 1:
                printf("Enter number to add : ");
                scanf("%d", &data);
                if(root == NULL) {
                    root = create(data);
                }
                else {
                    insert(root, create(data));
                }
                break;
            case 2:
                if(root == NULL) {
                    printf("\nTree is Empty\n");
                }
                else {
                    printf("\nTree contains : ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root == NULL) {
                    printf("\nTree is Empty\n");
                }
                else {
                    printf("\nTree contains : ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root == NULL) {
                    printf("\nTree is Empty\n");
                }
                else {
                    printf("\nTree contains : ");
                    postorder(root);
                    printf("\n");
                }
                break;
            default:
                printf("\nWrong Input\n");
                break;
        }
    }
    printf("\n-----DONE-----\n");
}