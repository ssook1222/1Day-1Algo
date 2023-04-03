//기타 코 난이도 중  최솟값 구기
//자명하지 않아 포기함
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;//기타 줄의 개
    int M;//코드를 구성하는 음의 개수
    char input;
    int * line;
    int * code;
    int * flat;
    int minLevel=100;
    int maxLevel=-100;
    int temp;

    scanf("%d %d", &N, &M);
	printf("%d %d\n", N, M);
	getchar();
	
    line = (int *)malloc(sizeof(int)*N);
    code = (int *)malloc(sizeof(int)*M);
    flat = (int *)malloc(sizeof(int)*M);

    int i=0;
    while(scanf("%c", &input)!=EOF){
        switch(input){
            case 'A':line[i]=1;break;
            case 'B':line[i]=3;break;
            case 'C':line[i]=4;break;
            case 'D':line[i]=6;break;
            case 'E':line[i]=8;break;
            case 'F':line[i]=9;break;
            case 'G':line[i]=11;break;
            case '#':line[i]++;break;
            case ' ': i++;
            default : break;
        }
		printf("line[%d] %d\n", i, line[i]);
		if(input=='\n'){
			break;
		}
    }
    
    int j=0;
    while(scanf("%c", &input)!=EOF){
        switch(input){
            case 'A':code[j]=1;break;
            case 'B':code[j]=3;break;
            case 'C':code[j]=4;break;
            case 'D':code[j]=6;break;
            case 'E':code[j]=8;break;
            case 'F':code[j]=9;break;
            case 'G':code[j]=11;break;
            case '#':code[j]++;break;
            case ' ': j++;
            default : break;
        }
		printf("code[%d] %d\n", j, code[j]);
		if(input=='\n'){
			break;
		}
    }

    for(int j=0; j<M; j++){
        for(int i=0; i<N; i++){
			printf("ㄴ%d %d\n",code[j], line[i]);
            //같으면
            if(code[j]==line[i]){
                flat[j]=0;
                break;
            }
			//다르면
			printf("%d %d\n",(code[j]-line[i]), line[i]-code[j]);
            temp=line[i]-code[j];
			temp=code[j]-line[i];
			if(flat[j]==0 || flat[j]>temp){
				flat[j]=temp;
			}
			printf(" ㄴ%d\n",temp);
        }
		printf("flat[%d] %d\n", j, flat[j]);
        if(flat[j]>maxLevel){
            maxLevel=flat[j];
        }
        if(flat[j]<minLevel){
            minLevel=flat[j];
        }
    }
    
    printf("%d", (maxLevel-minLevel+1));

    return 0;
}