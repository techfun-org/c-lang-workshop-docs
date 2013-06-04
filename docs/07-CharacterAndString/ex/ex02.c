#include <stdio.h>

int count(char str[]){
	/* TODO:文字列の長さを数える関数を作成する */
	return 0;
}

int main(){
	char str1[] = "12345"
			,str2[] = "123456789"
			,str3[] = "1234567890abc";

	printf("%15s:%d\n",str1,count(str1));
	printf("%15s:%d\n",str2,count(str2));
	printf("%15s:%d\n",str3,count(str3));

	return 0;
}
