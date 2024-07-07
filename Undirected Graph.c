#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct Node{
  int dest;
  struct Node*next;
}Node;

typedef struct Graph{
  struct Node*head[N];  
}Graph;

typedef struct Edge{
  int src,dest;  
}Edge;

Graph*createGraph(Edge edges[],int n){
    int i;
    Graph* graph= (Graph*)malloc(sizeof(Graph));
    for(i=0;i<N;i++)
    graph->head[i]=NULL;
    for(i=0;i<n;i++){
        int src=edges[i].src;
        int dest=edges[i].dest;
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->dest=dest;
    newNode->next=graph->head[src];
    graph->head[src]=newNode;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->dest=src;
    newNode->next=graph->head[dest];
    graph->head[dest]=newNode;
    }
    return graph;
}
void printGraph(Graph* graph){
    int i;
    for(i=0;i<N;i++){
        Node*ptr=graph->head[i];
    while(ptr!=NULL){
        printf("%d ",ptr->dest);
        ptr=ptr->next;
    }
    printf("\n");
    }
}
int main(){
    Edge edges[]=
    {
        {0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
    };
    int n=sizeof(edges)/sizeof(edges[0]);
    Graph*graph=createGraph(edges,n);
    printGraph(graph);
    return 0;
}
