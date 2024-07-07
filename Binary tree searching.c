#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    /* return the (unchanged) node pointer */
    return node;
}

struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;
    
    if (root->key < key)
       return search(root->right, key);
 
    return search(root->left, key);
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
if (root == NULL) return root;
 
if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
struct node* temp = minValueNode(root->right);
 
root->key = temp->key;
 
root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
	
	printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
  
    return 0;
}
//////////////////////moj nacin
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node*right,*left;
}Node;

void Inorder(Node*root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d\n",root->data);
        Inorder(root->right);
    }
}
Node*newNode(int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->data=elem;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
Node*Insert(Node*root,int elem){
    if(root==NULL)return newNode(elem);
    if(elem<root->data)
    root->left=Insert(root->left,elem);
    if(elem>root->data)
    root->right=Insert(root->right,elem);
    return root;
}
Node*search(Node*root,int elem){
    if(root==NULL || root->data==elem)
    return root;
    if(elem<root->data)
    return search(root->left,elem);
    if(elem>root->data)
    return search(root->right,elem);
}
Node*minValue(Node*root){
    if(root==NULL)
    return root;
    Node*q=root->left;
    while(q->left){
        q=q->left;
    }
    return q;
}
Node*maxValue(Node*root){
    if(root==NULL)
    return root;
    Node*q=root->right;
    while(q->right){
        q=q->right;
    }
    return q;
}
Node*deleteNode(Node*root,int elem){
    if(root==NULL)return root;
    if(root->data<elem){
        root->right=deleteNode(root->right,elem);
    }
    else if(root->data>elem){
        root->left=deleteNode(root->left,elem);
    }
    else{
        if(root->left==NULL){
            Node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node*temp=root->left;
            free(root);
            return temp;
        }
        else{
            Node*temp=minValue(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
int main(){
    Node*root=NULL;
    root=Insert(root,5);
    Insert(root,1);
    Insert(root,2);
    Insert(root,3);
    Insert(root,6);
    deleteNode(root,2);
    Inorder(root);
    return 0;
}
