//1~N 중 중복 없이 M개를 고른 수열
//1 ≤ M ≤ N ≤ 8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sequence(int *array, int N, int M, int num);
int main(){
    int N;
    int M;
	int num=0;
    int *array;
    //자연수와 수열 길이 입력받기
    scanf("%d %d", &N, &M);

    //수열 배열 할당 
    array = (int*) malloc(sizeof(int)*M);
    memset(array, 0, sizeof(int)*M);

    //수열 작성
	for(int X=1; X<=N; X++){
		array[num]=X;
		sequence(array, N, M, 0);
	}
}

void sequence(int *array, int N, int M, int num){
	num++;
    if(M!=num){
        for(int X=1; X<=N; X++){
			int flag=0;
			for(int Y=1; Y<=num ;Y++){
	            if(array[num-Y]==X){
					flag=1;
					break;
	            }
			}
			if(!flag){
				array[num]=X;
	        	sequence(array, N, M, num);
			}
        }
    }else{
        for(int s=0; s<M; s++){
            printf("%d ", array[s]);
        }
        printf("\n");
    }
    
}