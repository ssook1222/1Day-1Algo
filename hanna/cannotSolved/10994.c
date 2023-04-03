#include <stdio.h>
#include <stdlib.h>
void star(int n, int count);
int start=1;
int main(){
    int N;//1~100

    scanf("%d",&N);

    star(N, 0);
    return 0;
}

void star(int n, int count){
    if(!start && count==0){
        return;
    }
    start=0;
    for(int i=0; i<count; i++){
        printf("* ");
    }
    for(int i=0; i<4*n-3;i++){
        if(count%2==1)
            printf(" ");
        else
            printf("*");
    }

    for(int i=0; i<count; i++){
        printf(" *");
    }
    printf("\n");

    if(count%2==1){
        star(n,count);
    }
    else{
        star(--n,++count);
    }
}