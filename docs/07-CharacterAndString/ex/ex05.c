#include <stdio.h>
#include <string.h>

int main(){
	char input[5] = "";
	char answer[5] = "0000"; /* Challenge: rand関数とsprintf関数を使って動的に生成してみよう！ */

	printf("HitAndBlow Game!\n");
	do{
		/* 入力 */
		printf("guess a number [0-9]{4}\n>");
		scanf("%4s",input);

		/* 4文字以下の入力であれば終了 */
		if(strlen(input) < 4){
			printf("bye!\n");
			break;
		}
		
		/**
		 * TODO
		 *  ここにHit:xxx Blow:xxxを表示するプログラムを追記する
		 *  hitcount(ans,inp)のような関数を作るとなお良い
		 * */

		if(strcmp(answer,input)==0){
			printf("correct!\n");
			break;
		}
	}while(1);

	return 0;
}

