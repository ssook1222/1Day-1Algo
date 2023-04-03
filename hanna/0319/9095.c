//1, 2, 3 더하기

#include <stdio.h>
#include <stdlib.h>

#define MAX 11

int wayCount[MAX]={0,};

int main(){
    int T;//test 개수
    int * n;//test number

    scanf("%d", &T);

    n= (int *)malloc(sizeof(int)*T);
    for(int t=0; t<T; t++)
        scanf("%d", (n+t));

    for(int t=0; t<T; t++)    
        printf("%d\n", recurrence(*(n+t)));


    return 0;

}
int recurrence(int n){
    if(n==0 || n==1){
        wayCount[n]=1;
        return 1;
    }
    if(n==2){
        wayCount[n]=2;
        return 2;
    }
    if(wayCount!=0){
        return wayCount[n];
    }
    wayCount[n]=recurrence(n-1)+recurrence(n-2)+recurrence(n-3);
    
    return wayCount[n];
}