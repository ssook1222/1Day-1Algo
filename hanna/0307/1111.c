//수열
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int *  quickSort(int * arr, int left, int right);
int position (int * arr, int left, int right);
int main(){
    int ArraySize=0; //A size//1 ~ 50
    int * A;//1~1000
	int * B;
	int * P;
	int * flag;
    //A size 받기
    scanf("%d",&ArraySize);
	
    //element 받기
	A= malloc(sizeof(int)*ArraySize); 
	B= malloc(sizeof(int)*ArraySize); 
	P= malloc(sizeof(int)*ArraySize); 
	flag=malloc(sizeof(int)*ArraySize);
    for(int num=0; num<ArraySize;num++){
        scanf("%d",(A+num));
		*(B+num)=*(A+num);
    }
	
    //정렬
	quickSort(B,0,ArraySize-1);
	//
	for(int anum=0; anum<ArraySize; anum++){
		for(int bnum=0; bnum<ArraySize; bnum++){
			if(A[anum]==B[bnum]){
				if(flag[bnum]==1) continue;
				*(P+anum)=bnum;
				flag[bnum]=1;
				break;
			}
		}
	}
	for(int num=0; num<ArraySize;num++){
        printf("%d ",*(P+num));
    }
	//메모리 해제
 	free(A);
    free(P);
    return 0;
}
int * quickSort(int * arr, int left, int right) {
  if (left < right) {
    //기준점을 찾고 기준점을 중심으로 더 작은수, 더 큰수 분류
    int i =  position(arr, left, right);
    //기준점 기준 좌측 정렬
    quickSort(arr, left, i - 1);
    //기준점 기준 우측 정렬
    quickSort(arr, i + 1, right);
  }
  return arr;
}

int position (int * arr, int left, int right) {
  int temp;
  int i = left;
  int j = right;
  int array = arr[left];

  //제자리 더 큰수/더 작은 수 좌우 배치.
  while (i < j) {
    while (arr[j] > array) j--;
    while (i < j && arr[i] <= array) i++;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  arr[left] = arr[j];
  arr[j] = array;

  return j;
}
