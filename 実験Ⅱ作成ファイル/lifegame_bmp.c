/*ライフゲーム画像変換ファイル*/
/*lifegame_bmp.c*/

//各種ファイル・ライブラリーのインクルー?ド
#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int row,column;
int i,j,k;

//RGBカラー値代入関数
void setbmp(unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR],int row,int colum,int a){
	image[row][column][0]=a;
	image[row][column][1]=a;
	image[row][column][2]=a;
}

//セル生存確認関数
void bmp_Print(unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR],static unsigned char name[PIXEL_NUM_X][PIXEL_NUM_Y]){
	int temp;
	for(row=0;row<PIXEL_NUM_X;row++){
		for(column=0;column<PIXEL_NUM_Y;column++){

			//セルが生存していたら白色、死亡していたら黒色に
			if(name[row][column]==1){
				setbmp(image,row,column,MAX_COLOR);
			}else{
				setbmp(image,row,column,0);
			}
		}
	}
}

