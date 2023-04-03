#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) a > b ? a : b
long long * maxScore;
int sequence(int * score, int n);
int main(){
    int N;//계단수
    int *score;

    scanf("%d", &N);
    score=(int *)malloc(sizeof(int)*N);
    maxScore=(long long *)malloc(sizeof(long long)*N);
    memset(maxScore,0,sizeof(long long)*N);
    for(int i=0; i<N; i++){
        scanf("%d\n", &score[i]);
    }
    printf("%d",sequence(score, N));
    
    return 0;
}

int sequence(int *score, int n){
    if(n<4){
        for(int i=0; i<n; i++)
            maxScore[n-1]+=score[i];
        return maxScore[n-1];
    }
    if(maxScore[n]!=0){
        return maxScore[n];
    }
    sequence(score, n-1);
    maxScore[n]=MAX(maxScore[n-2], maxScore[n-3]+score[n-1])+score[n];
    return maxScore[n];
}