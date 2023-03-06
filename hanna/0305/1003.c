#include <stdio.h>

int DP_topDown(int n);

int topDownTable[41];

int main() {
  int TestCount; // Test개수

  // Test 케이스 개수 받기
  scanf("%d\n", &TestCount);

  // Test 케이스 받기
  int TestNum[TestCount]; // 0<=TestNum<=40

  for (int num = 0; num < TestCount; num++) {
    scanf("%d", &TestNum[num]);
  }

  //출력 횟수 검증 및 출력
  for (int num = 0; num < TestCount; num++) {
    printf("%d %d\n",DP_topDown(TestNum[num]-1),DP_topDown(TestNum[num]));
  }
  return 0;
}

int DP_topDown(int n){
    if (n == -1){
        return 1;
    }
    if (n < 2) {
        topDownTable[n]=n;
        return topDownTable[n];
    }
    if(topDownTable[n]>0){
        return topDownTable[n];
    }

    topDownTable[n]=DP_topDown(n-1)+DP_topDown(n-2);
    
    return topDownTable[n];
}