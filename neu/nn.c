/************************************************************/
/*					nn.c								*/
/*	単純なニューラルネットの計算				*/
/*	1出力のネットワークを計算します(学習なし)		*/
/*	使い方							*/
/*		/home/ML02/neu/nn.c < data.txt								*/
/************************************************************/

/* Visusal StudioÆÌÝ·«mÛ */
#define _CRT_SECURE_NO_WARININGS

/* wb_t@CÌCN[h */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Lè */
#define INPUTNO 2				/* üÍ */
#define HIDDENNO 2			/* 中間層のセル数 */
#define MAXINPUTNO 100		/* f[^ÌÅåÂ */

/* ÖÌvg^CvÌé¾ */
double f(double u);						/* `BÖ */
void initwh(double wh[HIDDENNO][INPUTNO + 1]);
						/* 中間層の重みの初期化 */
void initwo(double wo[HIDDENNO + 1]);		/* 出力層の重みの初期化 */
double  forward(double wh[HIDDENNO][INPUTNO + 1],
				double wo[HIDDENNO + 1], double hi[],
				double e[INPUTNO]);	/* 順方向の計算 */
int getdata(double e[][INPUTNO]);		/* f[^ÇÝÝ */

/************************************************************/
/*					main()Ö								*/
/************************************************************/
int main()
{
double wh[HIDDENNO][INPUTNO + 1];	/* 中間層の重み */
double wo[HIDDENNO + 1];		/* 出力層の重み */
double e[MAXINPUTNO][INPUTNO];		/* データセット */
double hi[HIDDENNO + 1];		/* 中間層の出力 */
double o;				/* 出力 */
int i, j;							/* JèÔµ */
int n_of_e;							/* f[^ÌÇÝÝ */

/* 重みの初期化 */
initwh(wh);
initwo(wo);


/* üÍf[^ÌÇÝÝ */
n_of_e = getdata(e);
printf("データの個数:%d\n", n_of_e);


/* 計算の本体 */
   for(i = 0; i < n_of_e; ++i)
   {
		printf("%d ", i);
		for(j = 0; j < INPUTNO; ++j)
			printf("%lf ", e[i][j]);
		o = forward(wh, wo, hi, e[i]);
		printf("%lf\n", o);
   }
return 0;
}
/************************************************************/
/*					getdata()Ö							*/
/*			wKf[^ÌÇÝÝ							*/
/************************************************************/
int getdata(double e[][INPUTNO])
{
int n_of_e = 0;			/* f[^ZbgÌÂ */
int j = 0;				/* JèÔµÌ§äp  */

/* f[^ÌüÍ */
   while(scanf("%lf", &e[n_of_e][j]) != EOF)
   {
   ++j;
   	if(j >= INPUTNO)		/* Ìf[^ */
   	{
   		j = 0;
   		++n_of_e;
   	}
   }
return n_of_e;
}
/************************************************************/
/*					forward()Ö							*/
/*					ûüÌvZ							*/
/************************************************************/
double forward(double wh[HIDDENNO][INPUTNO + 1],
		 double wo[INPUTNO + 1], double hi[],
		 double e[INPUTNO])
{
int i, j;			/* 繰り返しの制御 */
double u, o;				/* rÌvZluÆoÍo */

/* hiの計算 */
   for(i = 0; i < HIDDENNO; ++i)
   {
	u = 0;			/* 重み付き和を求める */
	   for(j = 0; j < INPUTNO; ++j)
		u += e[j] * wh[i][j];
	   u -= wh[i][j];	/* 閾値の処理 */
	   hi[i] = f(u);
   }
   /* 出力oの計算 */
   o = 0;
   for(i = 0; i < HIDDENNO; ++i)
	o += hi[i] * wo[i];
   o -= wo[i];			/* 閾値の処理 */

   return f(o);
}
/************************************************************/
/*					initwh()Ö								*/
/*					中間層の重みの初期化								*/
/************************************************************/
void initwh(double wh[HIDDENNO][INPUTNO + 1])
{
	/* èð×dÆµÄ^¦é */
	wh[0][0] = -2;
	wh[0][1] = 3;
	wh[0][2] = -1;
	wh[1][0] = -2;
	wh[1][1] = 1;
	wh[1][2] = 0.5;
	// wh[0][2] = 0.5;

}


/************************************************************/
/*					initwo()Ö								*/
/*					出力層の重みの初期化								*/
/************************************************************/
void initwo(double wo[HIDDENNO + 1])
{
	/* èð×dÆµÄ^¦é */
	wo[0] = -60;
	wo[1] = 94;
	wo[2] = -1;
}
/************************************************************/
/*					f()Ö									*/
/*					`BÖ								*/
/************************************************************/
double f(double u)
{
/* XebvÖÌvZ */
   if(u >= 0) return 1.0;
   else return 0.0;

/* VOChÖÌvZ */
// return 1.0 / (1.0 + exp(-u));
}
