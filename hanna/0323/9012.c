#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NO 0
int main(){
    int T;//입력개수
    char input;//입력 문자열
	int Openflag=0;
    int OpenNum=0;
    int * printAnswer;
    scanf("%d\n", &T);

    printAnswer=(int *)malloc(sizeof(int)*T);

	for(int count=0; count<T; count++){
		Openflag=0;
		OpenNum=0;
		while(1){
	        scanf("%c",&input);
	        if(input=='('){
	            OpenNum++;
				Openflag=1;
	        }
	        else if(input==')'){
	            OpenNum--;
				Openflag=0;
				if(OpenNum<0){
					printAnswer[count]=NO;
					OpenNum-=100;
				}
	        }
	        if(input=='\n'){
	            if(OpenNum==0){
					if(!Openflag){
	                	printAnswer[count]=YES;
					}else{
						printAnswer[count]=NO;
					}
	            }else{
	                printAnswer[count]=NO;
	            }
	            break;
        	}
    	}

	}

    for(int i=0; i<T; i++){
        if(printAnswer[i]==YES){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}