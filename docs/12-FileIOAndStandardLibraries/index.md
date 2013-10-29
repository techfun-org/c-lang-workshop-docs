#	ファイル入出力と標準ライブラリ
C言語勉強会 第十二回

kumar  
October 1, 2013  
引用 : 

* [JM Project Linux Programmer's Manual](http://linuxjm.sourceforge.jp/html/LDP_man-pages/man3/)
* [N1570](http://www.open-std.org/jtc1/sc22/WG14/www/docs/n1570.pdf)

----
### 今回の内容
* ファイル入出力
* 標準ライブラリ
* プリプロセッサ

----
## ファイル入出力

----
### ストリーム
**データの入力または出力の機能を提供するもの。**

ここで言うデータとは、ファイル、メモリ、ネットワーク通信等、様々である。

----
### C言語におけるファイル入出力のおおまかな流れ
	ファイルを開く  
		 ↓
	ファイルに出力する or ファイルから入力を受ける  
		 ↓ 
	ファイルを閉じる

開いているファイルは、ハンドルと呼ばれる変数を利用して操作する。

また、標準ライブラリ`stdio.h`をインクルードしている必要がある。

----
#### ファイルに出力する擬似コード
	ハンドル = ファイルオープン(ファイル名);
	
	ファイルに出力(ハンドル, "hogehogehoge~~~~");
	
	ファイルクローズ(ハンドル);

実際にC言語において扱う関数は、以下のとおりだ。
<table>
	<tr>
		<th>
			擬似
		</th>
		<th>
			C言語
		</th>
	</tr>
	<tr>
		<td>
			ファイルオープン
		</td>
		<td>
			fopen
		</td>
	</tr>
	<tr>
		<td>
			ファイルクローズ
		</td>
		<td>
			fclose
		</td>
	</tr>
	<tr>
		<td>
			ファイルに出力
		</td>
		<td>
			fprintf
		</td>
	</tr>
	<tr>
		<td>
			ファイルから入力
		</td>
		<td>
			fscanf
		</td>
	</tr>	
</table>
そしてハンドルは、`FILE *`が担当する。

----
#### ファイルに出力するCのコード
	FILE * handle = fopen("unko.txt", "w");
	
	fprintf(handle, "hogehogehoge~~~~~\n");
	
	fclose(handle);

ね？簡単でしょう？

ただし、このコードは簡単のため、万が一ファイルを開けなかった場合のエラー処理を怠っている。そして、関数`fopen`の2個めの引数の意味もまだわからないだろう。

それらも含め、これより各部分を解説する。

----
### FILEポインタ
**C言語における、ファイルのストリーム**

	FILE *

**FILE構造体へのポインタである。** C言語ではこれを介して、ファイル(等)の入出力を行う。

ハンドルや、ストリームポインタとも呼ばれる。

これを含め、ファイル入出力のための構造体や関数などの定義は、標準ライブラリ `stdio.h` で定義されている。 

----
### fopen

	FILE *fopen(const char *path, const char *mode);

**path で指定された名前のファイルを開き、ストリームと結びつける。** 

引数 mode は、以下の文字をひとつ以上組み合わせた文字列へのポインタである。

それには以下がある。（次のページへ）

----

<table>
	<tr>
		<th>
			文字
		</th>
		<th>
			意味
		</th>
	</tr>
	<tr>
		<td>
			r
		</td>
		<td>
			テキストファイルを読み出すために開く。
		</td>
	</tr>
	<tr>
		<td>
			w
		</td>
		<td>
			ファイルを書き込みのために開く。（なければ新規作成、あれば上書き）
		</td>
	</tr>
	<tr>
		<td>
			a
		</td>
		<td>
			追加（ファイルの最後に書き込む）のために開く。（なければ新規作成）
		</td>
	</tr>
</table>

加えて、末尾に`b`をつけるとバイナリモードで開く。

----
**戻り値は開いたファイルを示すFILEポインタ。失敗するとNULL。**

簡単のためかなり省略している。完全な説明は
>[Man page of FOPEN](http://linuxjm.sourceforge.jp/html/LDP_man-pages/man3/fopen.3.html)

#### 例
はまだ載せずに、開いたファイルの閉じ方を紹介することにした。次のページヘ。

----
### fclose

	int fclose(FILE *fp);

**fpが指すストリームを閉じる。**

正常に終了すると `0` が返される。そうではない場合 `EOF` が返される。

また、ストリームを閉じる前に、バッファリングされていた全ての出力データをフラッシュする。

実際のところ、自分でfcloseしなくても、プログラムが終了するとき、OSが勝手にfcloseしてくれるのだが、強制終了した時はその限りでないので、忘れず書いたほうがいいと思う。（これは諸説あるので自信がない）

----
### ファイルを開いて閉じるだけのプログラム
理解の確認のため、全く入出力せず、ファイルを開いて閉じるだけの、プログラムの例を載せる。

	FILE * fp;
	
	/* ファイルを開く */
	fp = fopen("test.txt", "w");	/* 書き込みモードでtest.txtを開く */
	
	/* ファイルを閉じる */
	fclose(fp);

----
### ファイルを開いて閉じるだけのプログラム + エラー処理

面倒かもしれないがエラー処理は絶対にやってほしい。

	FILE * fp;
	
	fp = fopen("test.txt", "w");
	
	/* エラー処理 */
	if (NULL == fp) {
		printf("ファイルを開けなかった¥n");
		exit(EXIT_FAILURE);
	}
	
	fclose(fp);

----
### fprintf

	int fprintf(FILE *stream, const char *format, ...);

**出力をstreamに書き出す。**

お察しの通り、printfに一つ引数が増えただけで、以下のように使う。

	fprintf(yourstream, "%d個のうんこがある¥n", 10);

このほかにfputcや、fputsなどがある。

----
### fscanf

	int fscanf(FILE *stream, const char *format, ...);

**streamからの入力を読み込む。**

お(ry、scanfに一つ引数が増えただけで、以下のように使う。

	int x;
	fscanf(yourstream, "%d", &x);

このほかにfgetcや、fgetsなどがある。

----
### ファイルを書き出すプログラム
ファイルに文字列を書き出す簡単なプログラム

	FILE * fp;
	
	fp = fopen("test.txt", "w");	/* 書き込みモード */
	
	if (NULL == fp) {
		fprintf(stderr, "ファイルを開けなかった¥n");
		exit(EXIT_FAILURE);
	}
	
	/* fprintfで、fpに出力 */
	fprintf(fp, "やったぜ¥n");
	
	fclose(fp);

----
### ファイルを読み込むプログラム
ファイルから空白が来るまで文字列を読み込む簡単なプログラム

	FILE * fp;
	
	fp = fopen("test.txt", "r");	/* 読み込みモード */
	
	if (NULL == fp) {
		fprintf(stderr, "ファイルを開けなかった¥n");
		exit(EXIT_FAILURE);
	}
	
	/* fscanfで文字列を読み込んで、printfする */
	char str[100];
	fscanf(fp, "%99s", str);
	printf("%s¥n", str);
	
	fclose(fp);	

----
### コラム｜標準ストリーム
**ストリームの中でも、標準で用意されているもの**

それらは全て `FILE *` 型で、以下の通りである。

<table>
	<tr>
		<th>
			変数名
		</th>
		<th>
			名前
		</th>
	</tr>
	<tr>
		<td>
			stdout
		</td>
		<td>
			標準出力ストリーム
		</td>
	</tr>
	<tr>
		<td>
			stderr
		</td>
		<td>
			標準エラー出力ストリーム
		</td>
	</tr>
	<tr>
		<td>
			stdin
		</td>
		<td>
			標準入力ストリーム
		</td>
	</tr>
</table>

printf等の関数は、stdoutへ出力を行う。そしてscanf等の関数は、stdinから入力を受ける。

プログラムを起動した時点でオープンされている。だから、fopenを呼ぶ必要はない。

----
よって、printfはfprintfにより、こう書ける

	fprintf(stdout, "フォーマット", ...);

そして、scanfはfscanfにより、こう書ける

	fscanf(stdin, "フォーマット", ...);

エラーメッセージは、標準エラー出力へ出力すべきだ。

	fprintf(stderr, "エラーメッセージ¥n");

----
## 標準Cライブラリ

----
### 標準Cライブラリ

**C言語の標準規格で定められた、型・マクロ・関数の集合からなるライブラリ**

今まで使ってきた、 `stdio.h` や `stdlib.h` などのことである。

これは調べればわかるので、自分で調べて欲しい。Wikipediaで見やすくまとめられている。

>[標準Cライブラリ - Wikipedia](http://ja.wikipedia.org/wiki/標準Cライブラリ)

----
## プリプロセッサ

----
### プリプロセッサ

**ソースコードをコンパイルする前に、ソースコードに対して行われる前処理をプリプロセス（preprocess）と呼ぶ（直訳）。そのプリプロセスを行うプログラムのことをプリプロセッサと呼ぶ。**

C プリプロセッサは、以下の4つの機能を提供する。

* ヘッダファイルの読み込み
* マクロによる置換
* 条件文により、プログラムを含めたり除外する
* 行番号の取得。

----
プリプロセッサのための命令を、**プリプロセッサディレクティブ**という。ディレクティブは命令という意味である。

* プリプロセッサディレクティブの名前の先頭には、`#`が付いている。
* ディレクティブごとに改行を行う必要がある。

gccで、プリプロセスのみの実行を行うには、`-E`オプションを使う。標準出力に結果が出力される。

----
### ヘッダファイルの読み込み
`#include`により行う。

#### #include
**指定したファイルの中身をまるごと挿入する**

	#include <h-char-sequence>
	#include "q-char-sequence"

今まで使ってきたinclude文であるが実はこういう単純な意味であった。

----
### マクロによる置換
**プリプロセッサの中でも、文字列の置換を行うプログラムのことをマクロと呼ぶ。**

本当に単なる置換である。

マクロの定義は、 `#define` で行う。

----
#### #define

**`#define` にはいくつか文法がある。ここではメジャーなもの2つを紹介する。それぞれ、マクロ定数を定義するものと、マクロ関数を定義するものである。**

----
### マクロ定数を定義する

	#define identifier replacement-token-list

**指定したidentifierをソースコード内で見つけたら、replacement-token-listに置き換える**

##### 例

	#define UNKO 1
	
	int func(void) {
		return UNKO;
	}

関数funcは 1 を返す。

----
#### マクロ定数の定義を書かないこともできる

	#define identifier

後に出る`#ifdef`等と組み合わせて使う

----
### マクロ関数を定義する

	#define identifier(parameter-list) replacement-token-list
	
**マクロ定数の機能に加え、引数をとる事ができる。**

とった引数は、replacement-token-listの中で使うことが出来る。

##### 例

	#define ADD(A, B) A + B
	
	int func(void) {
		const int a = 1, b = 3;
		
		return ADD(a, b);
	}

----

`ADD(a, b)` は `a + b` に置換され、関数funcは 4 を返す。

#### マクロ関数の注意点
* ただの文字列置換なので、型を完全に無視してしまう。
* replacement-token-listを`()`で囲まないとヤバい

##### replacement-token-listを`()`で囲まなかったせいでヤバい例
	#define ADD(A, B) A + B
	
	int x = 5 * ADD(2, 3);

`5 * (2 + 3) = 25`になることを期待したと思うが、マクロ関数による単なる置換が行われ、`5 * 2 + 3 = 13`になってしまう。

----

なので、マクロ関数を書く場合、replacement-token-listを必ず`()`
で囲むべきだ。

##### 直した例
	#define ADD(A, B)	(A + B)

	int x = 5 * ADD(2, 3);	// 5 * (2 + 3) = 25

----
### 条件分岐
**条件を満たしたらプログラムを含め、そうでなければ除外する**

	#if constant-expression
		…
	#endif

constant-expressionが真のとき（0以外のとき）、...をプログラムに含む。偽のとき（0のとき）、...はプログラムから除外される。

constant-expressionは定数で無くてはならない。プリプロセッサはコンパイル前に実行されるので、当然である。

<small>（この場合、定数とはconst変数のことではない。）</small>

----
条件分岐ディレクティブは幾つかある。

<table>
	<tr>
		<th>
			ディレクティブ
		</th>
		<th>
			意味
		</th>
	</tr>
	<tr>
		<td>
			#if …
		</td>
		<td>
			if …
		</td>
	</tr>
	<tr>
		<td>
			#ifdef …
		</td>
		<td>
			if defined …
		</td>
	</tr>
	<tr>
		<td>
			#ifndef …
		</td>
		<td>
			if not defined ...
		</td>
	</tr>
	<tr>
		<td>
			#elif ...
		</td>
		<td>
			else if ...
		</td>
	</tr>
	<tr>
		<td>
			#else
		</td>
		<td>
			else
		</td>
	</tr>
	<tr>
		<td>
			#endif
		</td>
		<td>
			endif
		</td>
	</tr>
</table>

----
## おわりに

----
#### やってみませんか
* __複数のファイルを使ったC言語プログラミング__
	* C++でも役立つのでぜひ学んで欲しい。
	* ライブラリとの連携の仕方も、是非知ってほしい。
* __最新のC言語を学ぶ__
	* C言語含め、プログラミング言語には、規格がある。
	* 2013年10月現在、最新のC言語はC11で、2011年に承認されたものである。
	* [C11 (C言語) - Wikipedia](http://ja.wikipedia.org/wiki/C11_(C言語))

----
#### C言語よりも楽しい言語でプログラミングしませんか
大抵の最近の言語はC言語より楽しい。

他の言語を勉強してみませんか。

どの言語でも、どこかC言語に似ているので、このC言語勉強会で学んだことは、必ず役に立つはずです。

どの言語が良いかはあなたのやりたいこと次第で決まってきます。先輩方に相談してみよう！

----
__皆さん、お疲れ様でした。__

----
# 終わり

----
#	 Special thanks...

- __hitoyozake__
- ____oppai____
- ____akiym____
- __Mr.tanaka__
- __いーさんさん__
- __kumar8600__
- __AND YOU__