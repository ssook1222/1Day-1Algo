//-2진수
//
#include <stdio.h>
#include <math.h>
#define STACK_SIZE 32

int stack[STACK_SIZE];
int top=-1;

int IsEmpty();
void push(int result);
int pop();

int main(){
    double N;

    scanf ("%lf", &N);

    while(fabs(N)>1){
        push(abs((int) remainder(N,(-2))));
        N=ceil(N/(-2));
    }
	if(N==0){
		push(0);
	}else{
		if(N==-1){
			push(1);
		}
		push(1);
	}
    
    while(!IsEmpty()){
        printf("%d",pop());
    }
    return 0;
}
int IsEmpty(){
    if(top<0) return 1;
    else return 0;
}
void push(int result){
    stack[++top]=result;
}
int pop(){
    return stack[top--];
}