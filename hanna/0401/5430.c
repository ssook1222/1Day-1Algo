#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define STRMAX 400001
int array[MAX]; //array (array size ~100,000)
int arrayStart;
int arrayEnd;//array size ~100,000

void parse(char * str){
    char *p = strtok(str,",");
    int i=0;
    while(p!=NULL){
        array[i]=atoi(p);
        p=strtok(NULL,",");
        i++;
    }
    
}
void output(char * p, int pEnd){
    int temp;
    for(int i=0; i<pEnd; i++){
        if(p[i]=='R'){
            temp=arrayStart;
            arrayStart=arrayEnd;
            arrayEnd=temp;
        }
        
        else if(p[i]=='D'){
            if(arrayStart<arrayEnd){
                arrayStart+=1;
                if(arrayStart>arrayEnd){
                    printf("error\n");
                    return;
                }
            }
            else if(arrayStart>arrayEnd){
                arrayStart-=1;
                if(arrayStart<arrayEnd){
                    printf("error\n");
                    return;
                }
            }
			else{
				printf("error\n");
                return;
			}
        }
    }
    printf("[");
    if(arrayStart<arrayEnd)
        for(int i=arrayStart; i<arrayEnd; i++){
            printf("%d", array[i]);
            if(i!=arrayEnd-1){
                printf(",");
            }
        }
    else
        for(int i=arrayStart-1; i>=arrayEnd; i--){
            printf("%d", array[i]);
            if(i!=arrayEnd){
                printf(",");
            }
        }
    printf("]\n");
}
int main(){
    int T;//Test case ~100
    char p[MAX];//function ~100,000
    int pEnd;
    char str[STRMAX];
    scanf("%d",&T);
	for(int j=0; j<T; j++){
		getchar();
		memset(array,0,sizeof(int)*MAX);
		memset(p,0,sizeof(char)*MAX);
		arrayStart=0;
        for(int i=0;;i++){
            scanf("%c",&p[i]);
            if(p[i]=='\n'){
                pEnd=i;
                break;
            }
        }
        scanf("%d",&arrayEnd);
		getchar();
        scanf("[%s]", str);
        parse(str);
        output(p, pEnd);
	}
    return 0;
}