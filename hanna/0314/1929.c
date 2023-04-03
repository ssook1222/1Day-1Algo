#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int M;
  int N;
  int * count;

  scanf("%d %d",&M, &N);
  count=(int *)malloc(sizeof(int)*(N+1));
  memset(count,0,sizeof(int)*(N+1));
  for(int num=1; num*num<=N; num++){
	  if(num==1){
		  count[num]=1;
		  continue;
	  }
	  if(count[num]==1){
		  continue;
	  }
	  for(int t=num*num; t<=N; t+=num){
		  count[t]=1;
	  }
	  
  }
  //소수면 출력
  for(int X=M; X<=N; X++){
    if(count[X]==0){
        printf("%d\n",X);
    }
  }
  free(count);
  return 0;
}