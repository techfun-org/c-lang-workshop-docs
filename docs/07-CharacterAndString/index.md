文字/文字列
======================
C言語勉強会 第七回

kodam

Jun. 5, 2013

----
### C言語が扱える値

C言語では、整数、小数、文字、文字列といった値が扱える。

	int hoge = 100;
	float huga = 1.0;
	char foo = 'A';
	char bar[] = "hogehoge";

プログラミングでは、直接扱える定数（＝の右側の値）を *リテラル* と呼ぶ。

----
### C言語の文字の扱い

C言語では文字リテラルをシングルクォーテーション(*'*)で挟んだ記号として表現する。(例:'a' 'A')

*文字リテラルは1バイト*で扱われ、以下のようにchar型の変数に格納することができる。
<small>(1バイト以上の変数にも格納はできるが、バイト数が異なるので注意して扱う必要がある。)</small>

	int chara_of_a = 'a';  /* 97 */
	char chara_of_b = 'b'; /* 98 */
	unsigned char chara_of_c = 99; /* 'c' */

これらの文字はASCIIコードと呼ばれ、対応表が存在する。
<small>(参考:[ASCII文字コード](http://e-words.jp/p/r-ascii.html))</small>

----
### 文字の出力
文字の標準出力に書き出すには様々な方法があるが、ここでは簡単なputchar関数を紹介する。

	putchar('a'); /* a (改行が含まれてないので注意 */

putchar関数は、引数に1文字取り1文字出力する関数である。

	/* Hello と表示させるプログラム */
	putchar('H');
	putchar('e');
	putchar('l');
	putchar('l');
	putchar('o');
	putchar('\n');


----
### 文字の入力
文字の標準入力を受けるには様々な方法があるが、ここでは簡単なgetchar関数を紹介する。

	char c = 0;
	c = getchar(); /* 入力を受け付けるためここでプログラムが一時停止する */

getchar関数は標準入力から1文字受け取り、返り値として返す関数である。

----
### C言語の文字列の扱い
C言語では文字列をダブルクォーテーション(*"*)で挟んだ記号の列として表現する。

C言語では文字列リテラルを扱える変数がないため、 *文字リテラルの配列* として扱われる。
また、配列の *宣言の際に限り* char型の配列に以下のように初期化することができる。

	char city[10] = "Hakodate";
	char name[] = "Shindo kodama";

----
### C言語の文字列の扱い
文字列リテラルは、必ず *末尾に'\0'(ヌル文字)* が存在し、文字列の終わりを意味する。
そのため、文字列を扱う配列は実際の文字列より1文字大きくなければならないので注意する。

	char city[10] = "Hakodate"; /* 大きさ10の配列 */
	char name[] = "kodama"; /* 大きさ7の配列 */

配列の添字に書かなかった場合は、初期化する文字列の長さ+1だけ配列が確保される。

----
### 文字列の出力
文字列の出力にはputs関数を使う。putsは引数で受け取った文字列を標準出力に書き出す単純な関数である。

	char name[] = "kodama";
	puts(name); /* => kodama */

ただし出力の最後に改行が勝手に追加されるので使いにくい。
後述するprintf関数が柔軟で使いやすいので、そちらを使うことを勧める。

----
### 文字列の入力
文字列の入力にはfgets関数が使える。fgetsは引数に *文字列の先頭のアドレス* (配列の名前部分)、サイズ、ファイルストリームを指定すると  
標準入力から受け取った文字列を変数に格納することが出来る。  
(配列は名前の部分が配列の先頭のアドレスを示し、&配列名[0]と同値である)

    char name[10];
    fgets(name, 10, stdin);

ちなみに、gets関数は読み込むバッファ長を指定することができないために使ってはいけない。すでに廃止されていて使う必要のない危険な関数である。

----
### (補足1) printfについて
printf関数は、文字列で指定したフォーマットで標準出力に書き出すための関数である。

引数を可変長にとり、第一引数に書式を書いた文字列を指定し、それ以降の引数に変数を指定することで、書式内で変数を展開することが出来る。

書式化された文字列は、標準出力へと書きだされる。

	char c = 'A';
	printf("%03d:%c\n",c,c); /* 097:A */

%から始まりアルファベットで終わる記号(%03d,%cなど)のことを *型指定子* と呼ぶ。  
また、書式を書いた文字列は変数でも指定が可能だが、[書式文字列攻撃](http://ja.wikipedia.org/wiki/%E6%9B%B8%E5%BC%8F%E6%96%87%E5%AD%97%E5%88%97%E6%94%BB%E6%92%83)という脆弱性があるため注意が必要である。

----
### (補足1) printfについて
<table width="90%" border="0" cellspacing="1" cellpadding="3">
  <tbody style="font-size:22px;">
<tr> 
<th bgcolor="#33FF99">指定子</th>
<th bgcolor="#99FFFF">対応する型</th>
<th bgcolor="#99FFFF">説明</th>
<th bgcolor="#99FFFF">使用例</th>
</tr>
<tr> 
<th class="bg_green">%c</th>
<td class="bg_cyan">char</td>
<td class="bg_cyan">１文字を出力する</td>
<td class="bg_cyan">"%c"</td>
</tr>
<tr> 
<th class="bg_green">%s</th>
<td class="bg_cyan">char \*</td>
<td class="bg_cyan">文字列を出力する</td>
<td class="bg_cyan">"%8s", "%10s"</td>
</tr>
<tr> 
<th class="bg_green">%d</th>
<td class="bg_cyan">int, short</td>
<td class="bg_cyan">整数を10進で出力する</td>
<td class="bg_cyan">"%+10d","%03d"</td>
</tr>
<tr> 
<th class="bg_green">%u</th>
<td class="bg_cyan">unsigned int, unsigned short</td>
<td class="bg_cyan">符号なし整数を10進で出力する</td>
<td class="bg_cyan">"%2u","%02u"</td>
</tr>
<tr> 
<th class="bg_green">%f</th>
<td class="bg_cyan">float, double</td>
<td class="bg_cyan">実数を出力する</td>
<td class="bg_cyan">"%5.2f"</td>
</tr>
<tr> 
<th class="bg_green">%e</th>
<td class="bg_cyan">float, double</td>
<td class="bg_cyan">実数を指数表示で出力する</td>
<td class="bg_cyan">"%5.3e"</td>
</tr>
</tbody>
</table>
(出典:[フォーマット指定子一覧](http://www.k-cube.co.jp/wakaba/server/format.html))

----
### (補足2) scanfについて
scanf関数は、標準入力から指定したフォーマットで変数に格納するための関数である。

printfの様に引数を可変長にとり、第一引数に書式を書いた文字列を指定し、それ以降の引数に *変数のアドレス* を指定することで、書式から変数に展開することが出来る。(アドレスは変数の先頭に&をつけることで取得が可能)

	char c = 0;
	scanf("%c",&c);
	printf("%c\n",c); /* 入力した1文字を表示 */

printfと同様にscanfにも型指定子が存在する。  
また、空白(または改行、タブなど)を含んだ文字列は入力できない。
その場合は、[fgets関数](http://hitorilife.com/fgets.php)を使う必要がある。

----
### (補足2) scanfについて
<table width="90%" border="0" cellspacing="1" cellpadding="3">
  <tbody style="font-size:22px;">
<tr> 
<th bgcolor="#33FF99">指定子</th>
<th bgcolor="#99FFFF">対応する型</th>
<th bgcolor="#99FFFF">説明</th>
</tr>
<tr> 
<th class="bg_green">%c</th>
<td class="bg_cyan">char</td>
<td class="bg_cyan">１文字を入力する</td>
</tr>
<tr> 
<th class="bg_green">%s</th>
<td class="bg_cyan">char \*</td>
<td class="bg_cyan">文字列を入力する</td>
</tr>
<tr> 
<th class="bg_green">%d</th>
<td class="bg_cyan">int</td>
<td class="bg_cyan">整数を10進で入力する</td>
</tr>
<tr> 
<th class="bg_green">%u</th>
<td class="bg_cyan">unsigned int</td>
<td class="bg_cyan">符号なし整数を10進で入力する</td>
</tr>
<tr> 
<th class="bg_green">%f</th>
<td class="bg_cyan">float</td>
<td class="bg_cyan">実数を入力する</td>
</tr>
<tr> 
<th class="bg_green">%lf</th>
<td class="bg_cyan">double</td>
<td class="bg_cyan">倍精度実数を入力する</td>
</tr>
</tbody>
</table>
(出典:[フォーマット指定子一覧](http://www.k-cube.co.jp/wakaba/server/format.html))

----
### (補足2) scanf関数の入力制限について
以下の様なコードの場合、[バッファオーバーフロー](http://ja.wikipedia.org/wiki/%E3%83%90%E3%83%83%E3%83%95%E3%82%A1%E3%82%AA%E3%83%BC%E3%83%90%E3%83%BC%E3%83%A9%E3%83%B3)の危険性がある。

	char a[20];
	scanf("%s", a);

上記のコードは、19バイト以上の文字列を入力するとバッファオーバーフローが発生する。

上記のコードは、aとして確保された領域に入力されるのは先頭の19バイト+'\0'までしか入力されず、それ以上の文字列が入力されるとバッファオーバーフローが発生する。
aの領域を十分に確保すれば問題はないが、入力される文字列の大きさを推測することは不可能であり、いくら大きくしてもバッファオーバーフローを回避することができない。

----
### (補足2) scanf関数の入力制限について
この問題を防ぐ手段として、一般的に最大入力幅を指定することができる。  
先ほどのコードの場合は、以下のようにすることで、回避することができる。

	char a[20];
	scanf("%19s", a);

aには先頭の19バイトが読み込まれて、それ以降は読み込まれず終了する。  

----
### (補足3) scanf関数の複数の入力について
scanf関数は一度に複数の入力を読み込むことができる。

	char a[11],b[11];
	scanf("%10s %10s",a,b); /* スペースまたは改行にて入力を分ける */ 
	printf("%s %s",a,b);

<small>(上記の場合は、10文字以上の入力を行うことでも、入力を分けることが出来る)</small>

