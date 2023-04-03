//별 찍기
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;

    scanf("%d", &N);
    for(int s=0; s<N; s++){
        for(int t=0; t<=s; t++)
            printf("*");
        printf("\n");
    }
	return 0;
}