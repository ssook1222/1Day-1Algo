//greedy algorithm
#include <stdio.h>
#include <stdlib.h>

#define THREE 0
#define FIVE 1

int main(){
    int kilogram;//goal
    int threeKiloCount=0;
    int fiveKiloCount=0;
    int tempKilogram=0;
	int choice=FIVE;
	
    scanf("%d",&kilogram);
    
    while(1){
        //1. 선택 : 무게 선택
		if(choice==FIVE){
			tempKilogram+=5;
        	fiveKiloCount++;
		}
		if(choice==THREE){
			tempKilogram+=3;
        	threeKiloCount++;
		}
        //2. 적절성 검사 : 목표 무게 초과하는지 확인
        if(tempKilogram>kilogram)
        {
            //초과 시 마지막 선택 무게 삭제 후 1.로 복귀 해 낮은 무게 선택
			tempKilogram-=5;
			fiveKiloCount--;
			choice=THREE;
			//삭제할 무게가 없으면
			if(fiveKiloCount<0){
				printf("-1");
				break;
			}
        }else{
			choice=FIVE;
		}
        //3. 해답 검사 : 목표 무게 일치하는지 검사.(불일치 시 1.반복)
        if(tempKilogram==kilogram)
        {
            printf("%d",fiveKiloCount+threeKiloCount);
            break;
        }
		
    }
    return 0;
}