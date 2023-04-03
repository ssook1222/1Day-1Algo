#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPUTER 100

typedef struct GRAPH {
    int computerNum;
	int link[MAX_COMPUTER][MAX_COMPUTER];
}GRAPH;

int visited[MAX_COMPUTER]={0,};

//그래프 초기화
void init(GRAPH * graph, int num){
	graph->computerNum=num;
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			graph->link[i][j]=0;
		}
	}
}
void insert(GRAPH * graph, int computer1, int computer2){
	graph->link[computer1-1][computer2-1]=1;
	graph->link[computer2-1][computer1-1]=1;
}
//탐색
int DFS(GRAPH * graph, int num, int count){
	visited[num-1]=1;

	for(int search=0; search<graph->computerNum; search++){
		if(graph->link[num-1][search]&& !visited[search]){
			count=DFS(graph, search+1, ++count);
		}
	}
	return count;
}
int main(){
    int computerNum;//1~100
    int pairingComputer;
    int computer1;
    int computer2;
	int count=0;
	
    scanf("%d",&computerNum);
	GRAPH * graph=(GRAPH *)malloc(sizeof(GRAPH));
	init(graph, computerNum);

    scanf("%d",&pairingComputer);
    for(int i=0; i<pairingComputer;i++){
        scanf("%d %d", &computer1, &computer2);
		insert(graph, computer1, computer2);
	}

	printf("%d",DFS(graph,1,0));
    return 0;
}