#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int N;//1~90
    int num=0;
    int checkNum=0;
    int remainValue=0;
    int previousValue=0;
    int countPinaryNum=0;
	int *prinaryMap;
    //N
    scanf("%d",&N);
    prinaryMap=(int *)malloc(sizeof(int)*pow(2,N));
    //count pinary number
    while(1){
		if(num==pow(2,N-2)){
			if(N==1){
				countPinaryNum++;
			}
			break;
		}
        checkNum=pow(2,N-1)+num;
		int temp=checkNum;
        //check pinary number
        while(1){
			printf("%d\n",temp);
			if(temp==1){
				printf("ㄴ%d %d %d\n",temp, remainValue,previousValue);
				countPinaryNum++;
				break;
			}
			if(prinaryMap[temp]!=0){
				printf("ㄴ%d %d %d-prinaryMap\n",temp, remainValue,previousValue);
				break;
			}
            previousValue=remainValue;
            remainValue=temp%2;

			if(previousValue*remainValue==1){
				printf("ㄴ%d %d %d\n",temp, remainValue,previousValue);
				prinaryMap[temp]=-1;
				break;
			}
            temp=ceil(temp/2);
			
        }
        num++;
    }

	printf("%d",countPinaryNum);
	free(prinaryMap);
    return 0;
}