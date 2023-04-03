#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNODE 1001

int visited[MAXNODE]={0,};
int queue[MAXNODE]={0,};
int connect[MAXNODE][MAXNODE]={0,};
int initial=1;
void DFS(int N, int V){
    visited[V]=1;
    if(!initial)
        printf(" ");
    initial=0;
    printf("%d",V);
    for(int i=1; i<=N; i++){
        if((!visited[i])&& connect[V][i]){
            DFS(N,i);
        }
    }
}
void BFS(int N, int V,int count){
    memset(queue, 0, sizeof(int)*MAXNODE);
    visited[V]=1;
    for(int i=1; i<=N; i++){
        if((!visited[i])&&connect[V][i]){
            queue[count++]=i;
            visited[i]=1;
            printf(" %d", i);
            //printf("queue[%d]= %d\n",count-1,i);
        }
    }
    for(int i=0; i<count; i++){
        if(queue[i]!=0){
            BFS(N,queue[i],0);
        }
    }
}
int main(){
    int N;//1~1000
    int M;//1~10000
    int V;//start
    int point1;
    int point2;

    scanf("%d %d %d", &N, &M, &V);
    getchar();

    for(int i=0; i<M; i++){
        scanf("%d %d",&point1, &point2);
        getchar();
        connect[point1][point2]=1;
        connect[point2][point1]=1;
    }

    DFS(N,V);
    printf("\n");

    memset(visited,0,sizeof(int)*MAXNODE);
    printf("%d",V);
    BFS(N,V,0);
    printf("\n");
    return 0;
}