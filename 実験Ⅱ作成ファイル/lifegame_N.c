/*ライフゲーム実行ファイル*/
/*lifegame_N.c*/

//各種ファイル・ライブラリーのインクルード
#include <stdio.h>
#include "define.h"

double lifegame(static unsigned char cell[PIXEL_NUM_X][PIXEL_NUM_Y]){

    //各種枠の設定
    double per,count=0;
    int ix,iy,sum;
    static unsigned char dell[PIXEL_NUM_X][PIXEL_NUM_Y];

    //順次ライフゲームの実行
    for(ix=0;ix<PIXEL_NUM_X;ix++){
        for(iy=0;iy<PIXEL_NUM_Y;iy++){
            sum=0;
            if(iy==0){
                if(ix==0){
                    sum +=cell[ix][iy+1];
                    sum +=cell[ix+1][iy];
                    sum +=cell[ix+1][iy+1];
                }else if(ix==PIXEL_NUM_X-1){
                    sum +=cell[ix-1][iy];
                    sum +=cell[ix-1][iy+1];
                    sum +=cell[ix][iy+1];
                }else{
                    sum +=cell[ix-1][iy];
                    sum +=cell[ix-1][iy+1];
                    sum +=cell[ix][iy+1];
                    sum +=cell[ix+1][iy];
                    sum +=cell[ix+1][iy+1];
                }
            }else if(iy==PIXEL_NUM_Y-1){
                if(ix==0){
                    sum +=cell[ix][iy-1];
                    sum +=cell[ix+1][iy-1];
                    sum +=cell[ix+1][iy];
                }else if(ix==PIXEL_NUM_X-1){
                    sum +=cell[ix-1][iy-1];
                    sum +=cell[ix][iy-1];
                    sum +=cell[ix-1][iy];
                }else{
                    sum +=cell[ix-1][iy-1];
                    sum +=cell[ix-1][iy];
                    sum +=cell[ix][iy-1];
                    sum +=cell[ix+1][iy-1];
                    sum +=cell[ix+1][iy];
                }
            }else{
                if(ix==0){
                    sum +=cell[ix][iy-1];
                    sum +=cell[ix][iy+1];
                    sum +=cell[ix+1][iy-1];
                    sum +=cell[ix+1][iy];
                    sum +=cell[ix+1][iy+1];
                }else if(ix==PIXEL_NUM_X-1){
                    sum +=cell[ix-1][iy-1];
                    sum +=cell[ix-1][iy];
                    sum +=cell[ix-1][iy+1];
                    sum +=cell[ix][iy-1];
                    sum +=cell[ix][iy+1];
                }else{
                    sum +=cell[ix-1][iy-1];
                    sum +=cell[ix-1][iy];
                    sum +=cell[ix-1][iy+1];
                    sum +=cell[ix][iy-1];
                    sum +=cell[ix][iy+1];
                    sum +=cell[ix+1][iy-1];
                    sum +=cell[ix+1][iy];
                    sum +=cell[ix+1][iy+1];
                }
            }
            if(cell[ix][iy]==1){
                if(sum==2||sum==3){
                    dell[ix][iy]=1;
                }else{
                    dell[ix][iy]=0;
                }
            }else if(cell[ix][iy]==0){
                if(sum==3){
                    dell[ix][iy]=1;
                }
            }
        }
    }

    //元の配列に戻す
    for(ix=0;ix<PIXEL_NUM_X;ix++){
        for(iy=0;iy<PIXEL_NUM_Y;iy++){
            cell[ix][iy]=dell[ix][iy];
            if(cell[ix][iy]==1){
                count++;
            }
        }
    }

    per=count/(PIXEL_NUM_X*PIXEL_NUM_Y);//生存割合の計算

    return per*100;//生存割合を戻す
}