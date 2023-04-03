#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
int way[MAX]={0,};
int sequence(int n);
int main(){
    int N;//타일 너비
    scanf("%d", &N);
    printf("%d",sequence(N));
    return 0;
}

int sequence(int n){
    if(n<4){
        way[n]=n;
        return n;
    }
    if(way[n]!=0){
        return way[n];
    }
    way[n]=(sequence(n-1)+sequence(n-2))%10007;
    return way[n];
}