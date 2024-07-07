#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int Info;
    struct Node*Next;
}Node;

//ILHAN BASIC BROJ INDEKSA:036048

Node*Front=NULL,*Rear=NULL;

void Create(int x){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->Info=x;
    if(Rear==NULL){
        Front=newNode;
        Rear=newNode;
    }
    else{
        Rear->Next=newNode;
        Rear=newNode;
    }
    Rear->Next=Front;
}
void Display(Node*Front){
    Node*p=Front;
    if(Front==NULL){
        return;
    }
    while(p!=Rear){
        printf("%d\n",p->Info);
        p=p->Next;
    }
}
void InsertBefore(Node*Front,int pos,int x){
    Node*newNode=(Node*)malloc (sizeof(Node));
    Node*current=Front,*p=Front;
    newNode->Info=x;
    while(pos!=1){
        current=current->Next;
        pos--;
    }
    newNode->Next=current->Next;
    current->Next=newNode;
    newNode->Info=current->Info;
    current->Info=newNode->Info;
}
void Inverse(Node*Front,Node*Rear){
    Node *p=Front,*q=NULL,*r=NULL;
    if(Front==NULL){
        return;
    }
    while(p!=Rear){
        r=q;
        q=p;
        p=p->Next;
        q->Next=r;
    }

}
int NumOfODD(Node*Front,Node*Rear){
    int br=0;
    if(Front==NULL){
        return 0;
    }
    Node*p=Front;
    while(p!=Rear){
        if(p->Info%2==0){
            br++;
        }
        p=p->Next;
    }
    return br;
}
int MinList(Node*Front,Node*Rear){
    if(Front==NULL){
        return 0;
    }
    int Min=Front->Info;
    Node*p=Front->Next;
    while(p!=Rear){
        if(p->Info<Min){
            Min=p->Info;
        }
        p=p->Next;
    }
    return Min;
}
int SumList(){
    if(Front==NULL){
        return 0;
    }
    Node*p=Front;
    int Suma=0;
    while(p!=Rear){
        Suma+=p->Info;
        p=p->Next;
    }
    return Suma;
}
void DeleteAfter(Node*Front,int pos){
    int Last=0,br=0;
    if(Front==NULL){
        return;
    }
    Node*p=Front,*current=Front,*temp;
    if(pos==1){
        Front=Front->Next;
        free(Front);
        Front=Front->Next;
        printf("List is empty.");
    }
    if(pos<1 || pos==br){
            printf("Invalid input.");
    }
    while(pos!=1){
        current=current->Next;
        pos--;
    }
    while(p!=Rear){
        if(p->Info==current->Info){
            temp=(Node*)malloc(sizeof(Node));
            temp=current->Next;
            current->Next=temp->Next;
            temp=NULL;
            free(temp);
        }
        p=p->Next;
    }
}
int main(){
    Create(6);
    Create(67);
    Create(56);
    Create(68);
    Create(16);
    //Display(Front);
    //InsertBefore(Front,4,999);
    //Inverse(Front,Rear);
    //printf("Broj parnih elemenata u listi je %d\n",NumOfODD(Front,Rear));
    //printf("Minimalni element liste je %d\n",MinList(Front,Rear));
    //printf("Suma liste je %d\n",SumList(Front,Rear));
    DeleteAfter(Front,2);
    Display(Front);
    printf("%d\n",Rear->Info);
    return 0;
}
