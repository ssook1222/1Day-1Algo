#include <stdio.h>
#include <math.h>

int main(){
    int N;//100
    long double X;//10^(18)
    int result=1;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%lld",&X);
        if(floor(sqrtl(X))<sqrtl(X)<ceil(sqrtl(X))){
            result=0;
        }else{
            result=1;
        }
        printf("%d ", result);
    }
    
    return 0;
}