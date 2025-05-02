//Implement a Binary Tree using Linked List and develop functions to perform traversal, searching, insertion and deletion operations.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode{
    struct TreeNode* left;
    int data;
    struct TreeNode* right;
}tnode;
tnode* createNode(int element){
    tnode* node=(tnode*)malloc(sizeof(tnode));
    node->data=element;
    node->left=node->right=NULL;
    return node;
}
tnode* insert(tnode* root,int value){
    if(root==NULL)
    return createNode(value);
    else{
        tnode* queue[100];
        int front=0,rear=0;
        queue[rear++]=root;
        while(front!=rear){
            tnode* temp=queue[front++];
            if(temp->left==NULL){
            temp->left=createNode(value);
            break;
        }
        else if(temp->right==NULL){
            temp->right=createNode(value);
            break;
        }
        else{
            queue[rear++]=temp->left;
            queue[rear++]=temp->right;
        }
    }
    return root;
}
}
void preorder(tnode* root){
    if(root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(tnode* root){
    if(root==NULL) return;
    inorder(root->left);
}
void postorder(tnode* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void levelorder(tnode* root){
tnode* queue[100];
int front=0,rear=0;
queue[rear++]=root;
while(front!=rear){
    tnode* temp=queue[front++];
    printf("%d ", temp->data);
    if(temp->left!=NULL)
    queue[rear++]=temp->left;
    if(temp->right!=NULL)
    queue[rear++]=temp->right;
}
}
tnode* search(tnode* root,int target){
    tnode* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front!=rear){
        tnode* temp=queue[front++];
        if(temp->data==target)
        return temp;
        if(temp->left!=NULL)
        queue[rear++]=temp->left;
        if(temp->right!=NULL)
        queue[rear++]=temp->right;
    }
}
tnode* findDeepest(tnode* root){
    if(root==NULL) return NULL;
    else{
    tnode* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    tnode* temp;
    while(front!=rear){
        temp=queue[front++];
        printf("%d ", temp->data);
        if(temp->left!=NULL)
        queue[rear++]=temp->left;
        if(temp->right!=NULL)
        queue[rear++]=temp->right;
    }
    int i=(rear-2)/2;
    if(queue[i]->left==temp)
    queue[i]->left=NULL;
    else
    queue[i]->right=NULL;
    return temp;
    }
}
void deleteNode(tnode* root,int value){
    tnode* temp=search(root,value);
    if(temp==NULL)
    printf("Element not found!!!\n");
    else{
        tnode* last=findDeepest(root);
        temp->data=last->data;
        printf("Element Deleted!!!\n");
    }
}
int main(){
    int choice,val;
    tnode* root=NULL;
    while(1){
        printf("1. Insert\n");
        printf("2. Pre-order\n");
        printf("3. In-order\n");
        printf("4. Post-order\n");
        printf("5. Level order\n");
        printf("6. Search\n");
        printf("8. Delete\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter value: ");
                scanf("%d", &val);
                insert(root, val);
                break;
            case 2:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Level-order traversal: ");
                levelorder(root);
                printf("\n");
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Value %d found in the tree.\n", val);
                else
                    printf("Value %d not found in the tree.\n", val);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(root, val);
                printf("Value %d deleted from the tree.\n", val);
                break;
            case 8:
                exit(0);
                break;
            default:
            printf("Invalid choice!!!\n");
        }
        printf("\n");
    }
}
