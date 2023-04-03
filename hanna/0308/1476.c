//날짜 계산

//1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19
#include <stdio.h>

int main(){
    int E;
    int S;
    int M;
    int year=0;
   

    scanf("%d %d %d", &E, &S, &M);
	
    while(1){
        if(E==S && S==M){
            year+=E;
            break;
        }
        E--;
        S--;
        M--;
        if(E<1) E=15;
        if(S<1) S=28;
        if(M<1) M=19;
        year++;
    }

    printf("%d", year);
    return 0;
}