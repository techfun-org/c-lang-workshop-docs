#include <stdio.h>

 /*
  * TODO: ここで1問目の構造体Localeを定義せよ。
  */

int main(void) {
  Locale hello = {
    "Hello", "Bonjour", "こんにちは"
  };
  char l;

  printf("What is your language? ('e': English, 'f': French, 'j': Japanese)\n>");
  scanf("%c", &l);

  /*
   * TODO: 'e'と入力されたらHello, 'f'ならBonjourといった感じに出力するように書き足せ。
   */
  
  return 0;
}
