<small>C言語勉強会 第十二回 ファイル入出力と標準ライブラリ</small>
###  演習問題

* 好きな文章（例えばうんこ）をlecture.txtに書き出すプログラムを書け
* 何かテキストファイルを開いて、全て標準出力に書き出すプログラムを書け。（テキストファイルのパスを、コマンドライン引数で指定するプログラムだとなお良し）
* （コンパイル対象の）OSによって動作を変えるプログラムを書け。
* 次のページもあるでｗ

----
問題

	#include <assert.h>

	#define add(A, B) A + B
	
	int main(void) {
		
		assert(6 == add(1, 2) * 2);
		
		return 0;
	}

* 上記のプログラムは、実行するとアサーション違反となる。main関数の中身を書き換えずに、期待通りの動作をするプログラムに書き換えよ。
	* <small>アサーションとは→→→</small>

----

* <small>アサーションとは、直訳すると「表明」を意味し、期待するある条件を満たしているかを確かめるために用いられる。今回の例では、`add(1, 2) * 2`の答えが、`6`であって欲しい。とても便利なのでこの先バリバリ使って行こう。バリバリ</small> 
	* <small>[表明 - Wikipedia](http://ja.wikipedia.org/wiki/%E8%A1%A8%E6%98%8E)</small>
	* <small>[C言語関数辞典 - assert](http://www.c-tipsref.com/reference/assert/assert.html)</small>

次のページもあるでｗ
	
----
問題

	#include <stdio.h>
	
	#define MAX(A, B) (A > B ? A : B)	
	
	int main(void) {
		int a = 1;
		int m = MAX(0, a++);
		
		printf("m: %d\n", m);
		
		return 0;
	}

* 上記のプログラムを実行し、問題点を探せ。そしてその解決法は何か考えよ。