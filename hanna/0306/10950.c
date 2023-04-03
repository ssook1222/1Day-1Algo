#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    
    int a[T];
    int b[T];
    int result[T];
    for(int i=0; i<T; i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        result[i]=a[i]+b[i];
    }
    for(int i=0; i<T; i++)
    {
        printf("%d",result[i]);
        
    }
    return 0;
}