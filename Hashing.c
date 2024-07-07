#include <stdio.h>
#include <stdbool.h>
#define SIZE 11

typedef struct {
    int key;
    int next;
}HashEntry;

void Init(HashEntry table[]){
    int i;
    for(i=0;i<SIZE;i++){
        table[i].key=-1;
        table[i].next=-1;
    }
}

int HashFunction(int key){
    return key%SIZE;
}

int HashFunction2(int key){
    return 2+(key%2);
}

int searchInsert(HashEntry table[],int key){
    int i=HashFunction(key);
    while(table[i].key!=key && table[i].next!=-1){
        i=table[i].next;
    }
    if(table[i].key==key)
    return i;
    int FreeIndex=SIZE-1;
    while(table[FreeIndex].key!=-1){
        FreeIndex--;
        if(FreeIndex<0)
        return -1;
    }
    int j=FreeIndex;
    if(table[i].key==-1){
        table[i].next=FreeIndex;
    }
    table[j].key=key;
    return j;
}

int searchInsert2(HashEntry table[],int key){
    int i=HashFunction(key);
    int j=HashFunction2(key);
    while(table[i].key!=key && table[i].key!=-1){
        i=(i+j)%SIZE;
    }
    if(table[i].key==key)
    return i;
    if(table[i].key==-1){
        table[i].key=key;
        return i;
    }
    else
    return -1;
}
int main(){
    HashEntry table[SIZE];
    Init(table);
    printf("DVOSTRUKO HESIRANJE\n");
    searchInsert2(table,23);
    searchInsert2(table,45);
    searchInsert2(table,67);
    searchInsert2(table,81);
    searchInsert2(table,22);
    for(int i=0;i<SIZE;i++){
        printf("Index:%d,Key:%d",i,table[i].key);
        printf("\n");
    }
    Init(table);
    printf("\nOBJEDINJENO ULANCAVANJE\n");
    searchInsert(table,23);
    searchInsert(table,45);
    searchInsert(table,67);
    searchInsert(table,81);
    searchInsert(table,22);
    for(int i=0;i<SIZE;i++){
    printf("Index:%d,Key:%d,Next:%d",i,table[i].key,table[i].next);
    printf("\n");
    }
    return 0;
}
