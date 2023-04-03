// 1로 만들기//memorization

// option3. X%3==0, X/3
// option2. X%2==0, X/2
// option1. X-1

#include <stdio.h>
#define Xsize 1000000
#define OptionSize 3

int memory[Xsize][OptionSize] = {
    0,
};
int FindOptimal(int X, int Min, int option);

int main() {
  int X;
  int Min = 0;
  int compareVal = 0;

  scanf("%d", &X);

  //연산 적용
  for (int i = 3; i >= 1; i--) {
    if (X == 1)
      break;
    compareVal = FindOptimal(X, Min, i);
	
    //최소값 찾기 첫값은 무조건 Min.
    if (i == 3 || compareVal < Min) {
      Min = compareVal;
    }
  }
  //출력
  printf("%d", Min);

  return 0;
}

int FindOptimal(int X, int Min, int option) {
	int orginX=X;
  int compareVal = 0;
  int option1Block = 0;
  // 1이 되면 min 리턴
  if (X == 1) {
    return Min;
  }
  //메모리에 저장된 값과 옵션이면 저장값 리턴
  if (memory[X-1][option-1] != 0) {
    return memory[X-1][option-1];
  }
  //옵션에 따라 연산 진행
  if (option != 1 && X % option == 0) {
    X = X / option;
    Min++;
  } 
  else {
    X = X - 1;
    Min++;
    option1Block = 1;
  }

  for (int i = 3; i >= 1; i--) {
    // 2,3으로 나눠지지않는 수 -1은 무조건 짝수이므로option1 연산 진행할 필요없음
    if (i == option1Block) {
      continue;
    }
	  memory[orginX-1][i-1] = Min;
    compareVal = FindOptimal(X, Min, i);
    if (i == 3 || compareVal < Min) {
      Min = compareVal;
    }
  }
  return Min;
}