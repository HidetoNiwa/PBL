/*���C�t�Q�[���摜�ϊ��t�@�C��*/
/*lifegame_bmp.c*/

//�e��t�@�C���E���C�u�����[�̃C���N���[?�h
#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int row,column;
int i,j,k;

//RGB�J���[�l����֐�
void setbmp(unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR],int row,int colum,int a){
	image[row][column][0]=a;
	image[row][column][1]=a;
	image[row][column][2]=a;
}

//�Z�������m�F�֐�
void bmp_Print(unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR],static unsigned char name[PIXEL_NUM_X][PIXEL_NUM_Y]){
	int temp;
	for(row=0;row<PIXEL_NUM_X;row++){
		for(column=0;column<PIXEL_NUM_Y;column++){

			//�Z�����������Ă����甒�F�A���S���Ă����獕�F��
			if(name[row][column]==1){
				setbmp(image,row,column,MAX_COLOR);
			}else{
				setbmp(image,row,column,0);
			}
		}
	}
}

