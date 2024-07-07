#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
//STACK PREKO DVA REDA
int red1[SIZE],red2[SIZE],f1=-1,r1=-1,f2=-1,r2=-1;

bool isEmpty(int reno){
    if(reno==1){
        if(f1==-1)return true;
        return false;
    }
    else if(reno==2){
        if(f2=SIZE)return true;
        return false;
    }
    else{
        printf("ERROR!");
    }
}
bool isFull(){
        if(f1==f2-1)return true;
        return false;
}
void Push(int element,int reno){
    if(isFull())
            return;
    if(reno==1){
        if(isEmpty(reno)){
        f1=0;r1=0;
        red1[r1]=element;
        }
        else{
        r1=(r1+1)%SIZE;
        red1[r1]=element;
        }
    }
    else if(reno==2){
        if(isEmpty(reno)){
            f2=SIZE-1;r2=SIZE-1;
            red2[r2]=element;
        }
        else{
        r2=(r2+SIZE-1)%SIZE;
        red1[r2]=element;
        }
    }
    else{
        printf("DRROR!");
    }
}
void Pop(int reno){
    if(reno==1){
        if(isEmpty(reno)){
        printf("FIRST QUEUE IS EMPTY!");
        return;
        }
        if(f1==r1){
            f1=-1;r1=-1;
        }
        f1=(f1+1)%SIZE;
    }
    else if(reno==2){
        if(isEmpty(reno)){
            printf("SECOND QUEUE IS EMPTY\n");
            return;
        }
        if(f2==r2){
            f2=SIZE;r2=SIZE;
        }
        f2=(f2+1)%SIZE;
    }
}
void Display(int reno){
    if(isEmpty(reno)){
        printf("QUEUE IS EMPTY!\n");
        return;
    }
    int i;
    if(reno==1){
    for(i=f1;i!=r1;i=(i+1)%SIZE)
        printf("%d ",red1[i]);
    printf("%d",red1[r1]);
    }
    else if(reno==2){
      for(i=f2;i!=r2;i=(i+1)%SIZE)
        printf("%d ",red2[i]);
    printf("%d",red2[r2]);
    }
}
int main (){
    Push(145,1);
    Push(250,1);
    Push(500,2);
    Display(1);
    return 0;
}
