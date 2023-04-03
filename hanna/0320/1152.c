#include <stdio.h>


int main(){
    char input;
	char previous='\0';
	int count=0;
	while(scanf("%c", &input)!=EOF){
		if(input==' '){
			if(previous!='\0')
				count++;
		}
		if(input=='\n'){
			if(previous!=' ')
				count++;
			break;
		}
		previous=input;
    }
	printf("%d",count);
    return 0;
}