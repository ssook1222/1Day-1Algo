//Deque(덱)
#include <stdio.h>
#include <stdlib.h>

//Deque 생성
void makeDeque(int * Q, int Qsize);
//Deque 첫번째 원소 소멸
int popFirst(int * Q, int Qsize);
//Deque 왼쪽 이동
void moveLeft(int * Q, int Qsize);
//Deque 오른쪽 이동
void moveRight(int * Q, int Qsize);

int main(){
    int Qsize=0; //Deque size//1<=Qsize<=50
    int PickCount=0; //Pick Count//PickCount<=Qsize
    int * location;//1~N
    int minValue=0; //뽑는데 걸리는 최소 횟수
    int * Deque;
    int currentHeader;

    //Deque size 받기
    scanf("%d",&Qsize);
    //Pick Count 받기
    scanf("%d",&PickCount);
    //위치 받기
	location= malloc(sizeof(int)*PickCount); 
    for(int position=0; position<PickCount;position++){
        scanf("%d",(location+position));
    }
	
    //Deque 생성
	Deque = malloc(sizeof(int)*Qsize);
    makeDeque(Deque, Qsize);
	
    //최솟값 찾기
    for(int num=0; num<PickCount;){
        //현재 위치가 찾고자 하는 위치인 경우
        currentHeader=Deque[0];
        if(location[num]==currentHeader){
            Qsize=popFirst(Deque,Qsize);
            num++;
        }
        if(Qsize-location[num]>location[num]-currentHeader){
            moveLeft(Deque, Qsize);
        }
        if(Qsize-location[num]<location[num]-currentHeader){
            moveRight(Deque,Qsize);
        }
    }
    //메모리 해제
    free(Deque);
    return 0;
}

//Deque 생성
void makeDeque(int * Q, int Qsize){
    for(int num=0; num<Qsize; num++){
        Q[num] = num+1;
    }
}
//Deque 첫번째 원소 소멸
int popFirst(int * Q, int Qsize){
    Q = &Q[1];
    Qsize--;
    return Qsize;
}
//Deque 왼쪽 이동
void moveLeft(int * Q, int Qsize){
    Q[Qsize-1]=Q[0];
    for(int num=0;num<Qsize-1;num++){
        Q[num]=Q[num+1];
    }
}
//Deque 오른쪽 이동
void moveRight(int * Q, int Qsize){
    Q[0]=Q[Qsize-1];
    for(int num=1;num<Qsize;num++){
        Q[num]=Q[num-1];
    }
}