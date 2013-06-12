/*
 * ex02.c
 * サイトに投稿された動画の情報を検索、余裕があるならソートせよ
 */

#include <stdio.h>
#include <time.h>

#define VM_LEN 5
/* #define _EX02_DIFFICULT */

/*
 * VideoMeta
 * 動画のメタ情報を格納する構造体
 */
typedef struct {
  int id; /* ID番号 */
  char name[50]; /* 動画の名前 */
  time_t posted_time; /* 投稿された時間（UNIX時間） */
  int length; /* 動画の長さ（秒） */
  int views; /* 再生回数 */
} VideoMeta;

VideoMeta vm[VM_LEN] = {
    { 3, "Super dogs", 1346988920, 260, 13213045 },
    { 2, "Kaitemita", 1302168012, 3000, 1242314250 },
    { 1, "Kaizo Mario", 1282492923, 132, 53251 },
    { 5, "phone review", 1360658491, 604, 4230 },
    { 4, "WTF????", 1370929768, 52, 14 }
};

/*
 * 動画のメタ情報を表示する。
 * - 標準ライブラリtime.hを使用。
 * - この関数の中身を理解せずに利用して良い。
 */
void printVideoMeta(VideoMeta a);

/*
 * 表の見出しを出力する。
 */
void printHeadRow();


int main(void) {
  int n;

  printHeadRow();
  int i;
  for(i = 0; i < VM_LEN; i++)
    printVideoMeta(vm[i]);
  
  
  do {
    puts("指示してください。");
    puts("(1):動画名検索");
#ifdef _EX02_DIFFICULT
    puts("ソートして表示");
    puts("(2):ID昇順 (3):投稿時間が新しい順");
    puts("(4):再生時間が長い順 (5):再生回数が多い順");
#endif
    puts("(0):終了");
    putchar(':');
    scanf("%d", &n);
    
    if(n == 0) {
      break;
    }

    switch(n) {
      case 1: /* 動画名検索（一部一致） */
        /*
         * TODO: ここを実装せよ。
         */
        break;
#ifdef _EX02_DIFFICULT
      case 2: /* ID昇順 */
        break;
      case 3: /* 投稿時間が新しい順 */
        break;
      case 4: /* 再生時間が長い順 */
        break;
      case 5: /* 再生回数が多い順 */
        break;
#endif
    }
    
  } while(1);  
  
  return 0;
}

void printVideoMeta(VideoMeta a) {
  struct tm *lt = localtime(&a.posted_time);
  char clt[50];
  sprintf(clt, "%d-%02d-%02d %02d:%02d:%02d", lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    
  printf("%6d | %-15.15s | %19.19s | %10d | %10d\n", a.id, a.name, clt, a.length, a.views);
}


void printHeadRow() {
  printf("    ID |            NAME |         POSTED_TIME |     LENGTH |      VIEWS\n");
}
