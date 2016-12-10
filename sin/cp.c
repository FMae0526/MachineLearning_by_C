/****************************************************************/
/*  			cp.c					*/
/* 畳み込みとプーリングの処理					*/
/* 2次元データを読み取り、畳込みとプーリングを施します		*/
/* 使い方							*/
/* /home/fandm/ML02/sin/cp.c  ./cp < data1.txt			*/
/****************************************************************/

/* Visual Studioとの互換性 */
#define _CRT_SECURE_NO_WARNINGS

/* ヘッダファイルのインクルード */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 記号定数の定義 */
#define INPUTSIZE 11			/* 入力数 */
#define FILTERSIZE 3			/* フィルタの大きさ */
#define POOLSIZE 3			/* プーリングサイズ */
#define POOLOUTSIZE 3			/* プーリングの出力サイズ */

/* 関数のプロトタイプ宣言 */
void conv(double filter[][FILTERSIZE],
		double e[][INPUTSIZE],
		double convout[][INPUTSIZE]);	/* 畳み込みの計算 */

void calcconv(double filter[][FILTERSIZE],
		double e[][INPUTSIZE], int i, int j);
						/* フィルタの適用 */

void convres(double convout[][INPUTSIZE]);	/* 畳み込みの結果出力 */


void pool(double convout[][INPUTSIZE],
		double poolout[][POOLOUTSIZE]);	/* プーリングの計算 */

void maxpooling(double convout[][INPUTSIZE],
		int i, int j);			/* 最大値プーリング */

void poolres(double poolout[][POOLOUTSIZE]);	/* 結果出力 */

void getdata(double e[][INPUTSIZE]);		/* データ読み込み */

/****************************************************************/
/*  			main()関数				*/
/****************************************************************/
int main()
{
double filter[FILTERSIZE][FILTERSIZE
	// = {{0, 0, 0}, {1, 1, 1}, {0, 0, 0}};		/* 横フィルタ */
	= {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};		/* 縦フィルタ */
double e[INPUTSIZE][INPUTSIZE];				/* 入力データ */
double convout[INPUTSIZE][INPUTSIZE] = {0};		/* 畳み込み出力 */
double poolout[POOLOUTSIZE][POOLOUTSIZE];		/* 出力データ */


/* 入力データの読み込み */
getdata(e);

/* 畳み込みの計算 */
conv(filter, e, convout);
convres(convout);

/* プーリングの計算 */
poolres(poolout);

return 0;

}
/****************************************************************/
/*  			poolres()関数				*/
/* 結果出力							*/
/****************************************************************/
void poolres(double poolout[][POOLOUTSIZE])
{
int i, j;		/* 繰り返しの制御 */

   for(i = 0; i < POOLOUTSIZE; ++i)
   {
	for(j = 0; j < POOLSIZEl ++j)
	{
		printf("%.3lf ", poolout[i][j]);
	}
	printf("\n");
   }
}
/****************************************************************/
/*  			pool()関数				*/
/* プーリングの計算						*/
/****************************************************************/
void pool(double convout[][INPUTSIZE],
		double poolout[][POOLSIZE])
{
int i, j;		/* 繰り返しの制御 */

   for(i = 0; i < POOLOUTSIZE; ++i)
	for(j = 0; j < POOLOUTSIZE; ++j)
		poolout[i][j] = maxpooling(convout, i, j);
}

/****************************************************************/
/*  			maxpooling()関数			*/
/* 最大値プーリング						*/
/****************************************************************/
double maxpooling(double couvout[][INPUTSIZE],
			inti, int j)
{
int m, n;			/* 繰り返しの制御用 */
double max;			/* 最大値 */
int halfpool = POOLSIZE / 2;	/* プーリングのサイズの1/2 */

max = 
	convout[i * POOLOUTSIZE + 1 + halfpool][j * POOLOUTSIZE + 1 + halfpool];

for(m = POOLOUTSIZE * i + 1; m <= POOLOUTSIZE * i + 1 + (POOLSIZE - halfpool); ++m)
	for(n = POOLOUTSIZE * j + 1; n <= POOLOUTSIZE * j + 1 + (POOLSIZE - halfpool); ++n)
		if(max < convout[m][n])	max = convout[m][n];
return max;
}

/****************************************************************/
/*  			cp.c					*/
/* 畳み込みとプーリングの処理					*/
/****************************************************************/
