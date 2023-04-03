#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int *a=(int*)malloc(sizeof(int));
    int *b=(int*)malloc(sizeof(int));
    int T=0;
    int * result;
    while(scanf("%d %d",a,a)==EOF)
    {   
        a=(int*)malloc(sizeof(int));
        b=(int*)malloc(sizeof(int));
        a++;
        b++;
        T++;
    }
    result=(int*)malloc(sizeof(int)*T);
    for(int i=0; i<T; i++)
    {
        result[i]=a[i]+b[i];
        printf("%d\n",result[i]);
        
    }
    return 0;
}