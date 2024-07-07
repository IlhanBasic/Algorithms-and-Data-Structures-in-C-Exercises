#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//ILHAN BASIC BROJ INDEXA:036048

typedef struct Node {
    int Data;
    struct Node* Next;
}Node;

Node *First=NULL,*Last=NULL,*Temp=NULL;

//KREIRANJE LISTE
void Create(int element){
    Temp=(Node*)malloc(sizeof(Node));
    Temp->Data=element;
    Temp->Next=NULL;
    if(First==NULL){
        First=Temp;
        Last=Temp;
    }
    else{
        Last->Next=Temp;
        Last=Temp;
    }
}

//ISPISIVANJE LISTE
void Display(Node *First){
    Node*p=First;
    while(p!=NULL){
        printf("%d\n",p->Data);
        p=p->Next;
    }
}

//DODAVANJE ELEMENTA NA POCETAK LISTE
void InsertAtTheFront(Node**First,int Value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->Data=Value;
    if(First==NULL){
        newNode=*First;
    }
    newNode->Next=*First;
    *First=newNode;
}

//DODAVANJE ELEMENTA NA KRAJ LISTE
void InsertAtTheEnd (Node**First, int newValue){
    Node* newNode = (Node*)malloc (sizeof(Node));
    newNode->Data=newValue;
    newNode->Next=NULL;
    if(*First==NULL){
        *First=newNode;
    }
    Node*Last=*First;
    while(Last->Next!=NULL){
        Last=Last->Next;
    }
    Last->Next=newNode;
}

//INSERT AFTER SA POZICIJOM
void InsertAfter_Position(Node*First,int Position,int element){
    Node*Prev=First,*Current=First;
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->Data=element;
        while(Position!=1){
            Prev=Current;
            Current=Current->Next;
            Position--;
        }
        newNode->Next=Current->Next;
        Current->Next=newNode;
}
//INSERT BEFORE SA POZICIJOM
void InsertBefore_Position(Node*First,int Position,int element){
    Node*Prev=First,*Current=First;
    Node*newNode=(Node*)malloc(sizeof(Node));
    while(Position!=1){
            Prev=Current;
            Current=Current->Next;
            Position--;
        }
    newNode->Data=Current->Data;
    newNode->Next=Current->Next;
    Current->Next=newNode;
    Current->Data=element;
}
//DELETE AFTER SA POZICIJOM
void DeleteAfter_Position(Node*First,int Position){
    Node*Prev=First,*Current=First;
    Node*temp=(Node*)malloc(sizeof(Node));
    while(Position!=1){
            Prev=Current;
            Current=Current->Next;
            Position--;
        }
        temp=Current->Next;
        Current->Next=temp->Next;
        free(temp);
        temp=NULL;
}
//BRISANJE PRVOG ELEMENTA
void DeleteAtTheFront(Node**First){
    Node *pomocna=*First;
    *First=pomocna->Next;
    free(pomocna);
    pomocna=NULL;
}

//BRISANJE PO POZICIJI
void Delete_by_position(Node*First,int Position){
    Node* Current=First;
    Node* Prev=First;
    if(First==NULL){
        printf("List is already empty.");
    }
    else if(Position==1){
        First=Current->Next;
        free(Current);
        Current=NULL;
    }
    else{
        while(Position!=1){
            Prev=Current;
            Current=Current->Next;
            Position--;
        }
        Prev->Next=Current->Next;
        free(Current);
        Current=NULL;
    }
}

//BRISANJE PO VREDNOSTI
void Delete_by_Value(Node*First,Node*Last,int Value){
    Node*p=First,*q=NULL;
    while(p!=NULL){
        if(p->Data==Value)
        break;
        else{
            q=p;
            p=p->Next;
        }
    }
    if(p==First && First==Last){
        First=Last=NULL;
        free(p);
        p=NULL;
    }
    else if(p==Last){
        q->Next=NULL;
        free(p);
        p=NULL;
        Last=q;
    }
    else{
        q->Next=p->Next;
        free(p);
        p=NULL;
    }
}

//INVERTOVANJE LISTE
Node *Invertuj(Node*First){
    Node*p,*q,*r;
    p=First;
    q=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->Next;
        q->Next=r;
    }
    First=q;
    return First;
}

//SPAJANJE DVE LISTE U JEDNU
Node *Concat(Node*List1,Node*List2){
    if(List1==NULL)return List2;
    else if(List2==NULL)return List1;
        Node*p=List1;
        while(p->Next!=NULL){
            p=p->Next;
        }
        p->Next=List2;
        return List1;
}

//POSLE SVAKOG NEPARNOG ELEMENTA PISE 0, A POSLE PARNOG 1
Node* InsertElement(Node* First){
    Node*p=First;
    while(p!=NULL){
        Node*temp=(Node*)malloc(sizeof(Node));
        if(p->Data%2==0){
            temp->Data=1;
            temp->Next=p->Next;
            p->Next=temp;
            p=temp->Next;
        }
        else{
            temp->Data=0;
            temp->Next=p->Next;
            p->Next=temp;
            p=temp->Next;
        }
    }
}

//REKURZIVNA FUNKCIJA ZA ZAMENU ELEMENATA
int ZameniRekurzivno(Node* First,int el1,int el2){
    if(First==NULL)
    return 0;
    Node*p=First;
    if(p->Data==el1){
        p->Data=el2;
    }
    else
    return ZameniRekurzivno(p->Next,el1,el2);
}

//REKURZIVNA FUNKCIJA ZA TRAZENJE MAKSIMALNOG ELEMENTA LISTE
int maxOdListe(Node *First) {
     if(First->Next == NULL)
          return First->Data;
     int prethodniMax = maxOdListe(First->Next);
     if(First->Data > prethodniMax)
          return First->Data;
     else
          return prethodniMax;
}
int main (){
    int n;
    //RUCNO KREIRANJE CVOROVA  LISTI
    /*
    Node * First = (struct Node*)malloc (sizeof(struct Node));
    Node * Second = (struct Node*)malloc (sizeof(struct Node));
    Node * Third = (struct Node*)malloc (sizeof(struct Node));
    
    First->Data = 1; First->Next=Second;
    Second->Data = 2; Second->Next=Third;
    Third->Data=3;Third->Next=NULL;
    
     Node * List1 = (struct Node*)malloc (sizeof(struct Node));
    Node * List12 = (struct Node*)malloc (sizeof(struct Node));
    Node * List123 = (struct Node*)malloc (sizeof(struct Node));

    Node * List2 = (struct Node*)malloc (sizeof(struct Node));
    Node * List22 = (struct Node*)malloc (sizeof(struct Node));
    Node * List23 = (struct Node*)malloc (sizeof(struct Node));
    
    Node * List3 = (struct Node*)malloc (sizeof(struct Node));
    Node * List32 = (struct Node*)malloc (sizeof(struct Node));
    Node * List33 = (struct Node*)malloc (sizeof(struct Node));

    List1->Data = 1; List1->Next=List12;
    List12->Data = 2; List12->Next=List123;
    List123->Data = 3; List123->Next=NULL;

    List2->Data = 1; List2->Next=List22;
    List22->Data = 2; List22->Next=List23;
    List23->Data = 3; List23->Next=NULL;
    
    List3->Data = 9; List2->Next=List22;
    List32->Data = 8; List22->Next=List23;
    List33->Data = 7; List23->Next=NULL;
    */
    
    //TESTIRANJE FUNKCIJA
    
    //Create(10);
    //Display(First);
    //InsertAtTheFront(&First,1000);
    //InsertAtTheEnd(&First,1000);
    //InsertAfter_Position(First,2,500);
    //InsertBefore_Position(First,2,600);
    //DeleteAtTheFront(First);
    //Delete_by_position(First,2);
    //Delete_by_Value(First,Last,500);
    //DeleteAfter_Position(First,4);
    //Invertuj(First);
    //Concat(List1,List2);
    //InsertElement(First);
    //ZameniRekurzivno(First,2,7);
    //maxOdListe(First);
   
    return 0;
}