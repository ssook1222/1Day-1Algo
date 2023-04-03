#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int visited[MAX]={0,};
int array[MAX];

void DFS(int N, int M, int depth, int stop);

int main(){
    int N;//N까지 수
    int M;//size
	
    scanf("%d %d",&N, &M);
	DFS( N, M, 0, 0);
    return 0;
}

void DFS(int N, int M, int depth, int stop){
    if (depth == M) {
		for(int i=0; i<M; i++){
			printf("%d ", array[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++){
		if (visited[i] || stop>i) 
			continue;
		array[depth]=i+1;
		visited[i] = 1;
		DFS(N, M, depth+1, i);
		visited[i] = 0;
	}
}