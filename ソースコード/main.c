/*���C�t�Q�[�����C���t�@�C��*/
/*main_lifegame.c*/

//�e��t�@�C���E���C�u�����[�̃C���N���[�h
#include <stdio.h>
#include <stdlib.h>
#include "rand.c"
#include "define.h"
#include "bmp.c"
#include "lifegame_N.c"
#include "lifegame_bmp.c"

int main(){

	//�e��ϐ��̐ݒ�
	char output_file[DO_COUNT];
	double alive[DO_COUNT+1];
	FILE *fp;
 	static unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR]={{0},{0},{0}};
	static unsigned char cell[PIXEL_NUM_X][PIXEL_NUM_Y];
	int i;
	
	alive[0]=myrand(cell);//�Z���̐����ݒ�
	bmp_Print(image,cell);//�Z���̉摜��


	for(i=0;i<DO_COUNT;i++){

		//BMP_COUNT�񐔕��̂P�����摜����
		if(i%BMP_COUNT==0){
			
			//i�Ԗڂ̃r�b�g�}�b�v�t�@�C������
			sprintf(output_file,"lifegame_t=%d.bmp",i);
			fp = bmp_FileOpen( output_file, "w" );
			bmp_WriteImage( fp, image);
			bmp_FileClose( fp );

		}

		alive[i+1]=lifegame(cell);//���C�t�Q�[���֐��̎��s
		bmp_Print(image,cell);//�Z���̉摜��
		printf("OK%d\t",i);//�摜���������\��
	}

	//����������dat�t�@�C�������o��
	fp=fopen("lifegame.dat","w");
	for(i=0;i<DO_COUNT;i++){
		fprintf(fp,"%d\t%f\n",i,alive[i]);
	}
	fclose(fp);

	printf("Fin...\a\n");//�I���ē�

    return 0;

}

