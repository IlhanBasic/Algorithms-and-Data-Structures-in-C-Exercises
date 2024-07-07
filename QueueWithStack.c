#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
//RED PREKO DVA STACKA
int stack1[SIZE],stack2[SIZE],top1=-1,top2=SIZE;
bool isEmpty(int stno){
    if(stno==1){
        if(top1==-1)
            return true;
        return false;
    }
    else if(stno==2){
        if(top2==SIZE)
        return true;
        return false;
    }
    else{
        printf("ERROR!");
    }
}
bool isFull ()
{
    return (top1==(top2+SIZE-1)%SIZE);
}
void enQueue(int element, int stno){
    if(isFull()){
        printf("OVERFLOW!");
        return;
    }
    if(stno==1){
            top1=(top1+1)%SIZE;
            stack1[top1]=element;
    }
    else if(stno==2){
            top2=(top2+SIZE-1)%SIZE;
            stack2[top2]=element;
    }
}
void deQueue(int stno){
    if(isEmpty(stno)){
        printf("UNDERFLOW!");
        return;
    }
    if(stno==1){
        top1=(top1-1)%SIZE;
    }
    else if(stno==2){
        top2=(top2-1)%SIZE;
    }
    else{
        printf("ERROR!");
    }
}
void Display(int stno){
    if(isEmpty(stno)){
        printf("QUEUE IS EMPTY!");
        return;
    }
    int i;
    if(stno==1){
        for(i=0;i!=top1;i++){
            printf("%d ",stack1[i]);
        }
        printf("%d",stack1[top1]);
    }
    else if(stno==2){
        for(i=SIZE-1;i!=top2;i--){
            printf("%d ",stack2[i]);
            return;
        }
        printf("%d",stack2[top2]);
    }
    else{
        printf("ERROR!");
        return;
    }
}
int main(){
    enQueue(700,1);enQueue(900,2);enQueue(300,1);deQueue(1);enQueue(777,2);enQueue(4,1);deQueue(2);
    Display(1);
    printf("\n\n");
    Display(2);
    return 0;
}
