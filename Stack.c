#include <stdio.h>
#define SIZE 10

int Stack[SIZE],top=-1;

//ILHAN BASIC BROJ INDEKSA:036048

int isStackfull(){
    if(top == SIZE-1) return 1;
    return 0;
}

int isStackempty(){
    if(top == -1) return 1;
    return 0;
}

void push(int elem){
    if( isStackfull()) printf("\n\n Overflow!\n\n");
    else
    {
        ++top;
        Stack[top]=elem;
    }
}

int pop(){
    int elem;
    if(isStackempty()){
    printf("\n\nUnderflow!\n\n");
    return(-1);
    }
    else{
        elem=Stack[top];
        top--;
        return(elem);
    }
}

void display(){
    int i;
    if(isStackempty()) printf(" \n Prazan stek.\n");
    else{
        for(i=0;i<=top;i++)
            printf("%d\n",Stack[i]);
    }
    printf("^\n|\nTop");
}

int main(){
    int opn,elem;
    do
    {
        printf("\n ===OPERACIJE SA STEKOVIMA=== \n");
        printf("\n Pritisni 1-Dodaj, 2-Izbrisi,3-Prikaz,4-Izlaz\n");
        printf("\n Tvoja opcija ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1: printf("\nKoji element zelite da dodate ?");
            scanf("%d",&elem);
            push(elem); break;
        case 2: elem=pop();
            if( elem != -1)
                printf("\nIzbrisani element je %d \n",elem);
            break;
        case 3: printf("\nStanje steka\n");
            display(); break;
        case 4: printf("\n Kraj programa. \n"); break;
        default: printf("\nNedozvoljena opcija !\n");
            break;
        }
    }while(opn != 4);
    return 0;
}

