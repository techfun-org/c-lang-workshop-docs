#include <stdio.h>
int main(){
	int i=0,j=0;
	for(i=0;i<16;i++){
		for(j=0;j<8;j++){
			unsigned char c = i*8 + j;
			printf("%03d: %c\t",c,c);
		}
		printf("\n");
	}
	return 0;
}

