#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 300
#define MAX_NUM 10000
int main(){
    int N,M;
    int K;
    int input;
    int x1,y1,x2,y2;
    int array[MAX_ARRAY][MAX_ARRAY]={0,};
    int sum=0;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &input);
            array[i][j]=input;
        }
    }
    scanf("%d",&K);
    for(int temp=0; temp<K; temp++){
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        sum=0;
        for(int i=x1-1; i<x2; i++){
            for(int j=y1-1; j<y2; j++){
                sum+=array[i][j];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}