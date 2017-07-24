/*ライフゲームメインファイル*/
/*main_lifegame.c*/

//各種ファイル・ライブラリーのインクルード
#include <stdio.h>
#include <stdlib.h>
#include "rand.c"
#include "define.h"
#include "bmp.c"
#include "lifegame_N.c"
#include "lifegame_bmp.c"

int main(){

	//各種変数の設定
	char output_file[DO_COUNT];
	double alive[DO_COUNT+1];
	FILE *fp;
 	static unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR]={{0},{0},{0}};
	static unsigned char cell[PIXEL_NUM_X][PIXEL_NUM_Y];
	int i;
	
	alive[0]=myrand(cell);//セルの生存設定
	bmp_Print(image,cell);//セルの画像化


	for(i=0;i<DO_COUNT;i++){

		//BMP_COUNT回数分の１だけ画像生成
		if(i%BMP_COUNT==0){
			
			//i番目のビットマップファイル生成
			sprintf(output_file,"lifegame_t=%d.bmp",i);
			fp = bmp_FileOpen( output_file, "w" );
			bmp_WriteImage( fp, image);
			bmp_FileClose( fp );

		}

		alive[i+1]=lifegame(cell);//ライフゲーム関数の実行
		bmp_Print(image,cell);//セルの画像化
		printf("OK%d\t",i);//画像生成完了表示
	}

	//生存割合のdatファイル書き出し
	fp=fopen("lifegame.dat","w");
	for(i=0;i<DO_COUNT;i++){
		fprintf(fp,"%d\t%f\n",i,alive[i]);
	}
	fclose(fp);

	printf("Fin...\a\n");//終了案内

    return 0;

}

