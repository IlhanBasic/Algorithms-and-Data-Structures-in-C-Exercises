#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int Data;
    struct Node* Next;
    struct Node* Prev;
}Node;

Node*Head,*newNODE;

//DODAJ NOVI CVOR
Node*GetNewNode(int x){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->Data=x;
    newNode->Next=NULL;
    newNode->Prev=NULL;
    return newNode;
}

//ISPISI LISTU
void Display(){
    Node*p=newNODE;
    while(p!=NULL){
        printf("%d\n",p->Data);
        p=p->Next;
    }
}

void Display2(){
    Node*p=newNODE;
    while(p!=NULL){
        printf("%d\n",p->Data);
        p=p->Next;
    }
}


//UMETNI NA KRAJ
void InsertAtTheTail(int x){
    Node*temp=GetNewNode(x);
    Node*p=Head;
    if(Head==NULL){
        Head=temp;
        return;
    }
    while(p->Next!=NULL){
        p=p->Next;
    }
    p->Next=temp;
    temp->Prev=p;
}

//INSERTAFTER
void InsertAfterPosition(Node*Head,int position,int x){
    Node*temp=GetNewNode(x);
    Node*current=Head;
    if(Head==NULL){
        return;
    }
    while(position!=1){
        current=current->Next;
        position--;
    }
    current->Next->Prev=temp;
    temp->Next=current->Next;
    current->Next=temp;
    temp->Prev=current;
}

//INSERTBEFORE
void InsertBeforePositon(Node*Head,int position,int x){
    Node*temp=GetNewNode(x);
    Node*current=Head;
     if(Head==NULL){
        return;
    }
    while(position!=1){
        current=current->Next;
        position--;
    }
    current->Prev->Next=temp;
    temp->Prev=current->Prev;
    current->Prev=temp;
    temp->Next=current;

}

//DELETEAFTER
void DeleteAfter(Node*Head,int position){
    Node*current=Head;
    Node*temp=GetNewNode(current->Next->Data);
    if(Head==NULL){
        printf("List is already empty.");
    }
    if(position==1){
        printf("Delete After option isn't possible.");
    }
    while(position!=1){
        current=current->Next;
        position--;
    }
    temp=current->Next;
    current->Next=temp->Next;
    temp->Next->Prev=current;
    free(temp);
    temp=NULL;

}

//DELETEBEFORE
void DeleteBefore(Node*Head,int position){
    Node*current=Head;
    Node*temp=GetNewNode(current->Next->Data);
    if(Head==NULL){
        printf("List is already empty.");
    }
    if(position==1){
        printf("Delete Before option isn't possible.");
    }
    while(position!=1){
        current=current->Next;
        position--;
    }
    temp=current->Prev;
    current->Prev=temp->Prev;
    temp->Prev->Next=current;
    free(temp);
    temp=NULL;

}

//DELETE BY VALUE
void DeleteByValue(Node** Head, int Value) {
if (*Head == NULL) {
return;
}
if ((*Head)->Data == Value && (*Head)->Next == NULL) {
free(*Head);
Head = NULL;
return;
}
Node p = *Head;
while (p != NULL) {
if (p->Data == Value) {
if (p == *Head) {
*Head = p->Next;
}
if (p->Prev != NULL) {
p->Prev->Next = p->Next;
}
if (p->Next != NULL) {
p->Next->Prev = p->Prev;
}
free(p);
return;
}
p = p->Next;
}
}

//INVERZIJA
void Inversion(Node*Head){
    if(Head==NULL){
        return;
    }
    if(Head->Next==NULL){
        return;
    }
    Node*p=Head;
    while(p->Next!=NULL){
        p=p->Next;
    }
    while(p->Prev!=NULL){
        printf("%d\n",p->Data);
        p=p->Prev;
    }
    printf("%d\n",p->Data);
}



//PRETRAZITI LISTU
bool Search(Node*Head,int x){
    if(Head->Next==NULL || Head==NULL){
        return false;
    }
    else if(Head->Data==x) {
        return true;
    }
    else if(Head->Data!=x){
        return Search(Head->Next,x);
    }
}


//SUMA MINIMALNOG I MAKSIMALNOG ELEMENTA LISTE
int MinMaxSuma(Node*First){
    if(Head==NULL){
        return 0;
    }
    if(Head->Next==NULL){
        return Head->Data;
    }
    Node*p=First;
    int Suma=0;
    int min=First->Data;
    int max=First->Data;
    while(p!=NULL){
        if(p->Data>max){
            max=p->Data;
        }
        if(p->Data<min){
            min=p->Data;
        }
        p=p->Next;
    }
    Suma=min+max;
    return Suma;
}

//PREBROJAVA ELEMENTE LISTE
int brElemenata(Node*Head,int x){
    int br=0;
    if(Head==NULL){
        return 0;
    }
    if(Head->Next==NULL && Head->Data<x){
        br++;
    }
    Node*p=Head;
    while(p!=NULL){
        if(x<p->Data){
            br++;
        }
        p=p->Next;
    }
    return br;
}


//REKURZIVNA FUNKCIJA ZA ZAMENU ELEMENATA
void Zameni2(Node* Head,int el1,int el2){
    if(Head==NULL)
    return;
    Node*p=Head;
    if(p->Data==el1){
        p->Data=el2;
    }
    else
    return Zameni2(p->Next,el1,el2);
}

//PRONALAZI SREDNJI ELEMENT
void Srednji(Node*First){
    int br=0;
    Node*Current=First;
    if(First == NULL){
        return;
    }
    if(First->Next==NULL){
        return;
    }
    Node*p=First;
    while(p!=NULL){
        br++;
        p=p->Next;
    }
    int Srednji=br/2;
    while(Srednji!=1){
        Current=Current->Next;
        Srednji--;
    }
    Current=Current->Next;
    printf("\nSrednji element je %d.\n",Current->Data);
}

//BROJI POJAVLJIVANJA TRAZENOG BROJA U LISTI
int Pojavljivanja(Node*First,int x){
    int br=0;
    if(First == NULL){
        return 0;
    }
    if(First->Next==NULL){
        return 0;
    }
    Node*p=First;
    while(p!=NULL){
        if(p->Data==x){
            br++;
        }
        p=p->Next;
    }
    return br;
}

//BRISANJE K-TOG CVORA LISTE
Node*deleteKthNode(Node* Head,int k){
    if(Head==NULL){
        return NULL;
    }
    if(k==1){
        Node*temp=Head->Next;
        while(temp!=NULL){
        free(Head);
        Head=temp;
        }
    }
    int br=0;
    Node*p=Head;
    while(p!=NULL){
    br++;
        if(k==br){
            free(p->Prev->Next);
            p->Prev->Next=p->Next;
            br=0;
        }
        if(br!=0)
        p=p->Next;
    }

}

//TREBALO BI DA RADI ALI NECE
Node* presekListi(Node*firstList ,Node*secondList){
	if(firstList == NULL || secondList == NULL){
		return NULL;
	}
	Node*newList = NULL;
	Node*travel = NULL;
	Node*tempFirst = firstList;
	while(tempFirst!=NULL){
			Node*tempSecond =secondList;
		while(tempSecond != NULL){
			if(tempFirst->Data == tempSecond->Data){
				if(newList == NULL){
					newList = (Node*)malloc(sizeof(Node));
					travel =(Node*)malloc(sizeof(Node));
					Node *newListTail = (Node*)malloc(sizeof(Node));
					newList->Data = tempFirst->Data;
					newList->Next = NULL;
					newListTail = newList;
					travel = newList;
				}
				else{
					Node*newElement = (Node*)malloc(sizeof(Node));
					newElement->Data = tempFirst->Data;
					newList->Next = newElement;
					newList = newList->Next;
				}
			}
			tempSecond = tempSecond->Next;
	    }
		tempFirst = tempFirst->Next;
	}
	return travel;
}

//SORTIRANJE LISTE
void SortirajListu(Node*Head){
    if(Head==NULL){
            return;
    }
    Node*i,*j;
    for(i=Head;i!=NULL;i=i->Next){
        for(j=i->Next;j!=NULL;j=j->Next){
            if(i->Data<j->Data){
                int temp=i->Data;
                i->Data=j->Data;
                j->Data=temp;
            }
        }
    }
}

//ODVAJANJE PARNIH ELEMENATA LISTE
Node*OdvojParne(Node*Head){
    if(Head==NULL){
        return NULL;
    }
    if(Head->Next==NULL){
        if(Head->Data%2==0){
            return Head;
        }
    }
    Node*p=Head;
    Node*newHead=NULL;
    Node*newTail=NULL;
    Node*parni=NULL;
    Node*travel;
    while(p!=NULL){
        if(p->Data%2==0){
            parni=(Node*)malloc (sizeof(Node));
            parni->Data=p->Data;
            if(newHead==NULL){
                parni->Next=NULL;
                parni->Prev=NULL;
                newHead=parni;
                newTail=parni;
                travel=parni;
            }
            else{
            newTail->Next=parni;
            parni->Prev=newTail;
            newTail=parni;
            }
        }
        p=p->Next;
    }
    return travel;
}

//ODVAJANJE NEPARNIH ELEMENATA LISTE
Node*OdvojNeparne(Node*Head){
    if(Head==NULL){
        return NULL;
    }
    if(Head->Next==NULL){
        if(Head->Data%2!=0){
            return Head;
        }
    }
    Node*p=Head;
    Node*newHead=NULL;
    Node*newTail=NULL;
    Node*parni=NULL;
    Node*travel;
    while(p!=NULL){
        if(p->Data%2!=0){
            parni=(Node*)malloc (sizeof(Node));
            parni->Data=p->Data;
            if(newHead==NULL){
                parni->Next=NULL;
                parni->Prev=NULL;
                newHead=parni;
                newTail=parni;
                travel=parni;
            }
            else{
            newTail->Next=parni;
            parni->Prev=newTail;
            newTail=parni;
            }
        }
        p=p->Next;
    }
    return travel;
}

//OBRISATI M-TI CVOR NAKON N-TOG CVORA
void DeleteM_afterN(Node*Head,int M,int N){
    Node*temp=(Node*)malloc(sizeof(Node));
    Node*current=Head;
    if(Head==NULL || Head->Next==NULL){
        return;
    }
    if(M==0 || N==0){
        return;
    }
    Node*p=Head;
    while(M!=1){
        current=current->Next;
        M--;
    }
    while(N!=1){
        current=current->Next;
        N--;
    }
    temp=current->Next;
    current->Next=temp->Next;
    temp->Prev=current;
        free(temp);
        temp=NULL;

}
int main (){
    int i,n;
    InsertAtTheTail(9);InsertAtTheTail(100);InsertAtTheTail(555);InsertAtTheTail(678);
    /*
    InsertAfterPosition(Head,2,888);
    InsertBeforePositon(Head,2,999);
    DeleteAfter(Head,4);
    DeleteBefore(Head,5);
    DeletebyValue(Head,100);
    */
    //Inversion(Head);
    //Display(Head);

    Node * List1 = (Node*)malloc (sizeof(Node));
    Node * List12 = (Node*)malloc (sizeof(Node));
    Node * List123 = (Node*)malloc (sizeof(Node));

    Node * List2 = (Node*)malloc (sizeof(Node));
    Node * List22 = (Node*)malloc (sizeof(Node));
    Node * List23 = (Node*)malloc (sizeof(Node));


    List1->Data = 10; List1->Next=List12;List1->Prev=NULL;
    List12->Data = 20; List12->Next=List123;List12->Prev=List1;
    List123->Data = 30; List123->Next=NULL;List123->Prev=List12;
    Node*Head1=List1;
    List2->Data = 10; List2->Next=List22;List2->Prev=NULL;
    List22->Data = 20; List22->Next=List23;List22->Prev=List2;
    List23->Data = 30; List23->Next=NULL;List23->Prev=List22;
    Node*Head2=List2;
    /*
    if(Search(Head,900)){
        printf("Element je pronadjen.");
    }
    else{
        printf("Element nije pronadjen.");
    }
    */
    //InsertElement(Head);
    //Display(Head);
    //printf("Broj elemenata koji su veci od zadatog broja iznosi %d\n",brElemenata(Head,1));
    //printf("Zbir unije Liste1 i Liste2 iznosi: %d\n",SumaUnijeLista(List1,List2));
    //Zameni2(Head,9,100000);
    //Inversion(Head);
    //Display(Head);
    //printf("Njihov zbir iznosi %d.\n",MinMaxSuma(Head));
    newNODE=presekListi(Head1,Head2);
    Display2(newNODE);
    return 0;
}
