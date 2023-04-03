#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void) {
	char key[10];
	char sorting[10];
	char string[100];
	char encryption[10][100];
	char decryption[10][100];
	int keySize = 0;
	int stringSize = 0;
	int row;
	// HUMDING
	// EIAAHEBXOIFWEHRXONNAALRSUMNREDEXCTLFTVEXPEDARTAXNAARYIEX
	// ONCEUPONATIMEINALANDFARFARAWAYTHERELIVEDTHREEBEARSXXXXXX
	scanf("%s", key);
	scanf("%s", string);
	keySize = strlen(key);
	stringSize = strlen(string);
	row=(int) floor(stringSize/keySize);
	// input encryption
	memset(encryption, 0, sizeof(encryption));
	memset(decryption, 0, sizeof(decryption));

	int max=-1;
	for (int s = 0; s < stringSize; s++) {
		if (s % row == 0) {
		  	max++;
		}
		encryption[s % row][max] = string[s];
	}
	
	for (int k = 0; k < keySize; k++) {
		sorting[k]=key[k];
	}
	// sorting
	while(1){
		int check = 0;
		for (int k = 0; k < keySize-1; k++) {
			int temp;
			if (sorting[k] > sorting[k+1]) {
				temp=sorting[k+1];
				sorting[k+1]=sorting[k];
				sorting[k]=temp;
				continue;
			}
			check++;
		}
		if (check == keySize - 1) {
		  break;
		}
	}
	
	//decryption
	for(int k=0; k<keySize; k++){
		for (int s = 0; s < keySize; s++) {
			if (key[k] == sorting[s]) {
				for (int r = 0; r < row; r++) {
				  decryption[r][k] = encryption[r][s];
				}
				sorting[s]=0;
				break;
			}
		}
	}
	
	for (int r = 0; r < row; r++) {
		for(int k = 0; k < keySize; k++) {
			if(decryption[r][k]!=0){
				printf("%c", decryption[r][k]);
			}
		}
	}
	return 0;
}