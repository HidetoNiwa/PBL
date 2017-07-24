/*���C�t�Q�[�����s�t�@�C��*/
/*lifegame_N.c*/

//�e��t�@�C���E���C�u�����[�̃C���N���[�h
#include <stdio.h>
#include "define.h"

double lifegame(static unsigned char cell[PIXEL_NUM_X][PIXEL_NUM_Y]){

    //�e��g�̐ݒ�
    double per,count=0;
    int ix,iy,sum;
    static unsigned char dell[PIXEL_NUM_X][PIXEL_NUM_Y];

    //�������C�t�Q�[���̎��s
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

    //���̔z��ɖ߂�
    for(ix=0;ix<PIXEL_NUM_X;ix++){
        for(iy=0;iy<PIXEL_NUM_Y;iy++){
            cell[ix][iy]=dell[ix][iy];
            if(cell[ix][iy]==1){
                count++;
            }
        }
    }

    per=count/(PIXEL_NUM_X*PIXEL_NUM_Y);//���������̌v�Z

    return per*100;//����������߂�
}