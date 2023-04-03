#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int network[MAX][MAX]={0,};
int visited[MAX]={0,};

int output(int N, int check){
    if(visited[check]){
        return 0;
    }

    visited[check]=1;
    for(int j=1; j<=N; j++){
        if((!visited[j]) && network[check][j]){
            output(N, j);
        }
    }
    return 1;
}
int main(){
    int N;//정점 개수 1~1000
    int M;//간선 개수 0~N*(N-1)/2
    int u;//1~N
    int v;//1~N
    int count=0;
    scanf("%d %d",&N, &M);
    getchar();
    for(int i=0; i<M; i++){
        scanf("%d %d",&u, &v);
        getchar();

        network[u][v]=1;
        network[v][u]=1;
    }

    for(int i=1; i<=N; i++){
        count+=output(N,i);
    }
   	printf("%d", count);
    return 0;
}