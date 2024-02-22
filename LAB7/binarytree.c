#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = node -> right = NULL;
    return node;
}

//to insert new node
struct Node* insert(struct Node* root, int data)
{
    if(root == NULL)
        return newNode(data);
    if(data <= root-> data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
};

//in order traversal
void inorder(struct Node* temp)
{
    if(temp == NULL)
        return;
    inorder(temp -> left);
    printf("%d ",temp -> data);
    inorder(temp -> right);
}
//pre order
void preorder(struct Node* temp)
{
    if(temp == NULL)
        return;
    printf("%d ",temp -> data);
    preorder(temp -> left);
    preorder(temp -> right);
}

//postorder
void postorder(struct Node* temp)
{
    if(temp == NULL)
        return;
    preorder(temp -> left);
    preorder(temp -> right);
    printf("%d ",temp -> data);
}

void main()
{
    struct Node* root = NULL;
    int data,choice;

    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,15);
    root = insert(root,40);
    root = insert(root,30);
    root = insert(root,50);
    printf("\nthe inorder traversal is : \n");
    inorder(root);
    printf("\n");

    printf("\nthe preorder traversal is : \n");
    preorder(root);
    printf("\n");

    printf("\nthe postorder traversal is : \n");
    postorder(root);
    printf("\n");




   /* do{
        printf("enter your choice : \n1.Insert \n2.Inorder \n3.preorder \n4.postorder \n5.Exit \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("enter the value to be inserted : \n");
                scanf("%d",&data);
                root = insert(root,data);
                break;
            case 2: printf("inorder traversal : \n");
                    inorder(root);
                    printf("\n");
                    break;
            case 3: printf("preorder traversal : \n");
                    preorder(root);
                    printf("\n");
                    break;
            case 4: printf("postorder traversal : \n");
                    postorder(root);
                    printf("\n");
                    break;
            case 5: printf("exit\n");
                    break;
            default:printf("invalid choice");
        }
    }while(choice != 5);
*/
}







