// 1로 만들기//memorization

// option3. X%3==0, X/3
// option2. X%2==0, X/2
// option1. X-1

#include <stdio.h>

#define Xsize 1000000

int memory[Xsize] = { 0,};

int main() {
  int X;
  int Min = 0;
  

  scanf("%d", &X);

  //연산 적용
  for (int i = 2; i <=X; i++ ){
    memory[i]=memory[i-1]+1;
    if(i%2==0){
		memory[i]=(memory[i]<memory[i/2]+1)?memory[i]:memory[i/2]+1;
	}
	if(i%3==0){
		memory[i]=(memory[i]<memory[i/3]+1)?memory[i]:memory[i/3]+1;
	}
  }
  //출력
  printf("%d", memory[X]);

  return 0;
}