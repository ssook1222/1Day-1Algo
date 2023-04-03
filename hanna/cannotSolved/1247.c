#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    long long *A;
    long long S[3]={0,};

    for(int j=0; j<3; j++){
        scanf("%d",&N);
        A=(long long *)malloc(sizeof(long long)*N);
        for(int i=0; i<N; i++){
            scanf("%lld",&A[i]);
			if(S[j]>9223372036854775807-A[i]){
				S[j]=9223372036854775807-A[i];
				printf("%d %lld\n",i, S[j]);
			}
			else if(S[j]<-9223372036854775807-A[i]){
				S[j]=-9223372036854775807-A[i];
				printf("%d %lld\n",i, S[j]);
			}else{
				S[j]+=A[i];
			}
        }
    }
    for(int j=0; j<3; j++){
        if(S[j]<0)
            printf("-\n");
        else if(S[j]>0)
            printf("+\n");
        else if(S[j]==0.0)
            printf("0\n");
    }
}