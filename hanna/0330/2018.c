#include<stdio.h>

int main()
{
	int n,i,cnt=0,sum=0;
	scanf("%d",&n);
	for(i=1;sum<=n;i++){
		sum +=i;
		if((n-sum)>=0 && (n-sum)%i==0) cnt++;
	}
	printf("%d",cnt);
	return 0;
}