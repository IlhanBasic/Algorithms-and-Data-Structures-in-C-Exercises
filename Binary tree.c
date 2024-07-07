#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node*right,*left;
}Node;

Node*Create(int elem){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=elem;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void print_inorder(Node*tree){
    if(tree){
        print_inorder(tree->left);
        printf("%d ",tree->data);
        print_inorder(tree->right);
    }
}
void print_postorder(Node*tree){
    if(tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ",tree->data);
    }
}
void print_preorder(Node*tree){
    if(tree){
        printf("%d ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}
void Delete(Node*tree){
    if(tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        free(tree);
    }   
}
void Listovi(Node*tree){
    if(tree){
        Listovi(tree->left);
        if(tree->left==NULL && tree->right==NULL)
        printf("%d ",tree->data);
        Listovi(tree->right);
    }
}
int SumaStabla(Node*tree){
    int suma;
    if(tree){
        suma=tree->data+SumaStabla(tree->left)+SumaStabla(tree->right);
    }
    else suma=0;
    return suma;
}
int brElemenata(Node*tree){
    int br;
    if(tree){
        br=1+brElemenata(tree->left)+brElemenata(tree->right);
    }
    else br=0;
    return br;
}
bool Postoji(Node*tree,int e){
    if(tree){
        if(tree->data==e)
        return true;
        Postoji(tree->left,e) || Postoji(tree->right,e);
    }
    else
    return false;
}
int maxDubina(Node*tree){
    int dubina=0;
    if(tree){
        int dubinaL=maxDubina(tree->left);
        int dubinaR=maxDubina(tree->right);
        if(dubinaL<dubinaR)
        return 1+dubinaR;
        else
        return 1+dubinaL;
    }
    else
    return dubina;
}
int brElemenataN(Node*tree,int n){
    int br;
    if(tree){
        if(n){
            br=brElemenataN(tree->left,n-1)+brElemenataN(tree->right,n-1);
        }
        else
        br=1;
    }
    else
    br=0;
    return br;
}
void printN(Node*tree,int n){
    if(tree==NULL)
    return;
    if(n==0)
    printf("%d ",tree->data);
    else{
        printN(tree->left,n-1);
        printN(tree->right,n-1);
    }
}
int SumaN(Node*tree,int n){
    int suma;
    if(tree){
      if(n){
        suma=SumaN(tree->left,n-1)+SumaN(tree->right,n-1);  
      }  
      else
      suma=tree->data;
    }
    else
    suma=0;
    return suma;
}
int ZbirListova(Node*tree){
    int suma;
    if(tree==NULL){
        suma=0;
    }
    else{
        if(tree->left==NULL && tree->right==NULL)
        suma=tree->data;
        else
        suma=ZbirListova(tree->left)+ZbirListova(tree->right);
    }
    return suma;
}
int Max(Node*tree){
    if(tree){
        int Max1=tree->data;
        if(tree->left){
            if(Max1<Max(tree->left))
            Max1=Max(tree->left);
        }
        if(tree->right){
            if(Max1<Max(tree->right))
            Max1=Max(tree->right);
        }
        return Max1;
    }
    else
    return 0;
    
}
int main(){
    Node*root=Create(1);
    root->left=Create(2);
    root->left->left=Create(3);
    root->left->right=Create(4);
    root->right=Create(5);
    root->right->left=Create(6);
    printf("\nprint_postorder: ");
    print_postorder(root);
    printf("\nprint_preorder: ");
    print_preorder(root);
    printf("\nprint_inorder: ");
    print_inorder(root);
    printf("\n%d",ZbirListova(root));
    return 0;
}
