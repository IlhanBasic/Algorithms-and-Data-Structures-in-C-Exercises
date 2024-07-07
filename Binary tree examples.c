#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node*left,*right;
}Node;

Node*newElement(int elem){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=elem;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void printInorder(Node*tree){
    if(tree){
        printInorder(tree->left);
        printf("%d ",tree->data);
        printInorder(tree->right);
    }
}

void printPostorder(Node*tree){
    if(tree){
        printPostorder(tree->left);
        printPostorder(tree->right);
        printf("%d ",tree->data);
    }
}

void printPreorder(Node*tree){
    if(tree){
        printf("%d ",tree->data);
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
}

void DeleteTree(Node*tree){
    if(tree){
        DeleteTree(tree->left);
        DeleteTree(tree->right);
        free(tree);
    }
}
void printListovi(Node*tree){
    if(tree){
        printListovi(tree->left);
        if(tree->left==NULL && tree->right==NULL)
        printf("%d ",tree->data);
        printListovi(tree->right);
    }
}
int SumaStabla(Node*tree){
    if(tree){
        int suma;
        suma=tree->data+SumaStabla(tree->left)+SumaStabla(tree->right);
        return suma;
    }
    else
    return 0;
}
int brElemenata(Node*tree){
    if(tree){
        int br;
        br=1+brElemenata(tree->left)+brElemenata(tree->right);
        return br;
    }
    else
    return 0;
}
bool Nadjen(Node*tree,int elem){
    if(tree){
        if(tree->data==elem)
        return true;
        else return Nadjen(tree->left,elem) || Nadjen(tree->right,elem);
    }
    return 
    false;
}
int Max(int elem1,int elem2){
    return (elem1>elem2)?elem1:elem2;
}
int brElemenataNivoN(Node*tree,int N){
    if(tree){
        if(N!=0){
            int nivo=brElemenataNivoN(tree->left,N-1)+brElemenataNivoN(tree->right,N-1);
            return nivo;
        }
        else
        return 1;
    }
    else
    return 0;
}
void IspisNivoa(Node* tree, int N) {
    if (tree) {
        if (N == 0) {
            printf("%d ", tree->data);
        } else {
            IspisNivoa(tree->left, N - 1);
            IspisNivoa(tree->right, N - 1);
        }
    }
}
int zbirNnivoa(Node* tree, int N) {
    if (tree) {
        int zbir = 0;
        if (N == 0) {
            return tree->data;
        } else {
            zbir = zbirNnivoa(tree->left, N - 1) + zbirNnivoa(tree->right, N - 1);
        }
        return zbir;
    }
    return 0;
}

int zbirL(Node*tree){
    if(tree){
        int suma;
        if(tree->left==NULL && tree->right ==NULL)
        suma=tree->data;
        else
        suma=zbirL(tree->left)+zbirL(tree->right);
        return suma;
    }
    else
    return 0;
}

int maxStabla(Node*tree){
    if(tree){
        int Max1=tree->data;
        if(Max1<maxStabla(tree->left))
        Max1=maxStabla(tree->left);
        if(Max1<maxStabla(tree->right))
        Max1=maxStabla(tree->right);
        return Max1;
    }
    return 0;
}

int maksimalnaDubinaStabla(Node*tree){
    if(tree){
        int levaStrana=maksimalnaDubinaStabla(tree->left);
        int desnaStrana=maksimalnaDubinaStabla(tree->right);
        if(levaStrana<desnaStrana)
        return 1+desnaStrana;
        else
        return 1+levaStrana;
    }
    return 0;
}

int main(){
    Node*root=newElement(1);
    root->left=newElement(2);
    root->right=newElement(3);
    root->left->left=newElement(4);
    printf("Preorder:");printPreorder(root);
    printf("\nPostorder:");printPostorder(root);
    printf("\nInorder:");printInorder(root);
    printf("\nListovi:");printListovi(root);
    printf("\nSuma stabla iznosi: %d",SumaStabla(root));
    printf("\nBroj elemnata stabla je %d",brElemenata(root));
    if(Nadjen(root,4))
    printf("\nElement je nadjen");
    else
    printf("\nelement ne postoji u stablu");
    printf("\nBroj elemenata na nivou 3 je  %d ",brElemenataNivoN(root,0));
    printf("\nIspis nivoa:");IspisNivoa(root,1);
    printf("\nZbir N-tog nivo je %d",zbirNnivoa(root,2));
    printf("\nZbir listova stabla: %d",zbirL(root));
    printf("\nMaksimalni element u binarnom stablu je %d ",maxStabla(root));
    return 0;
}
