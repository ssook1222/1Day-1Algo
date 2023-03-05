//정수 나눗셈
#include <stdio.h>

int main(){
    int operand1;
    int operand2;
    scanf("%d %d", &operand1, &operand2);
    printf("%.9lf",(double)operand1/(double)operand2);
    return 0;
}