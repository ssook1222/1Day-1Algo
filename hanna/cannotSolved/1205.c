#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;//number of rank list
    long int TaeSuCount;//TaeSu Count
    int P;//limit Count to rank list
    long int *Rank;
    int ranking=1;

    scanf("%d %lld %d", &N, &TaeSuCount, &P);
    Rank=(long int *)malloc(sizeof(long int)*N);
    for(int i=0; i<N; i++){
        scanf("%lld",&Rank[i]);
    }
	for(int i=0; i<N; i++){
		long int temp;
		for (int j = 0; j < (N - 1) - i; j++) {
			if (Rank[j] < Rank[j + 1]) {	// 버블 정렬 사용
				temp = Rank[j];
				Rank[j] = Rank[j + 1];
				Rank[j + 1] = temp;
			}
		}
	}

	for(int i=0; i<N; i++){
        if(Rank[i]>=TaeSuCount){
			if(Rank[i]==TaeSuCount){
				if(ranking==P){
					ranking=-1;
				}
				break;
			}
			ranking++;
        }
    }
    printf("%d",ranking);
    return 0;
}
// 10 1 10
// 10 9 8 7 6 5 4 3 3 2 0
// -1

// 10 1 10
// 10 9 8 7 6 5 4 3 2 1
// -1