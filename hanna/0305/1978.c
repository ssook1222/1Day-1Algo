//소수 찾기

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	int naturalNumber;//1000이하의 자연수
	int primeNumber;
} Number;

int main(void) {
	int numCount=0;//100 이하
	int primeNumberCount=0;
	
	//입력되는 숫자의 개수 받기
	scanf("%d", &numCount);

	Number * number = malloc(sizeof(Number)*numCount); 
	//숫자 목록 저장
	for(int num=0; num<numCount; num++){
		scanf("%d",&(number+num)->naturalNumber);
		
	}
	
	//소수 판정
	for(int num=0; num<numCount; num++){
		(number+num)->primeNumber=TRUE;
		
		//1은 무조건 소수 아님
		if((number+num)->naturalNumber==1){
			(number+num)->primeNumber=FALSE;
			continue;
		}

		//2는 무조건 소수
		if((number+num)->naturalNumber==2){
			(number+num)->primeNumber=TRUE;
			continue;
		}
		
		//그 외 자연수에 대하여 소수 판정
		for(int n=2; n<((number+num)->naturalNumber)/2+1; n++){
			//n으로 나눠지면 소수 아님
			if((number+num)->naturalNumber%n==0){
				(number+num)->primeNumber=FALSE;
				break;
			}
		}
	}

	//소수 개수 세기
	for(int num=0; num<numCount; num++){
		if((number+num)->primeNumber == TRUE){
			primeNumberCount++;
		}
	}
	
	//소수 개수 출력
  	printf("%d", primeNumberCount);
	
  	return 0;
}