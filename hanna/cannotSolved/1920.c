#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int *A;
    int M;
    int *checkValue;

    scanf("%d",&N);
    A=(int *)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&M);
    checkValue=(int *)malloce(sizeof(int)*M);
    for(int i=0; i<M; i++){
        scanf("%d",&checkValue[i]);
    }

    //오름차순 정렬

    //이분 탐색
    int temp;
    int check;
    int left;
    int right;
    int middle;
    for(int i=0; i<M; i++){
        temp=checkValue[i];
        check=0;
        left=0;
        right=M-1;

        while(left<=right){
            middle=(left+right)/2;
            if(temp<A[middle]){
                right=middle-1;
            }
            else if(temp> A[middle]){
                left=middle+1;
            }
            else{
                check=middle;
                break;
            }
        }
    }
    return 0;
}