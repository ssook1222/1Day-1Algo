//그대로 출력
#include <stdio.h>

int main(){
    char string;
    while(scanf("%c", &string)!=EOF){
        printf("%c",string);
    };
    
    return 0;
}