/*乱数発生ファイル*/
/*rand.c*/

//各種ファイル・ライブラリーのインクルード
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

//各種枠の設定
int i, j;
double per, count = 0;

//乱数発生関数
double myrand(static unsigned char cell[PIXEL_NUM_X][PIXEL_NUM_Y])
{

    srand((unsigned)time(NULL));

    for (i = 0; i < PIXEL_NUM_X; i++)
    {
	for (j = 0; j < PIXEL_NUM_Y; j++)
	{
	    //乱数の発生
	    cell[i][j] = (double)rand() / ((double)RAND_MAX + 1) * MAX_COLOR;

	    //初期生存確率の反映
	    if (cell[i][j] < LIVE * MAX_COLOR)
	    {
		cell[i][j] = 1; //生存
		count++;
	    }
	    else
	    {
		cell[i][j] = 0; //死亡
	    }
	}
    }

    per = count / (PIXEL_NUM_X * PIXEL_NUM_Y); //生存割合の計算

    return per * 100; //生存している割合を戻す
}













