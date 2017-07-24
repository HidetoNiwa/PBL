/*���������t�@�C��*/
/*rand.c*/

//�e��t�@�C���E���C�u�����[�̃C���N���[�h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

//�e��g�̐ݒ�
int i, j;
double per, count = 0;

//���������֐�
double myrand(static unsigned char cell[PIXEL_NUM_X][PIXEL_NUM_Y])
{

    srand((unsigned)time(NULL));

    for (i = 0; i < PIXEL_NUM_X; i++)
    {
	for (j = 0; j < PIXEL_NUM_Y; j++)
	{
	    //�����̔���
	    cell[i][j] = (double)rand() / ((double)RAND_MAX + 1) * MAX_COLOR;

	    //���������m���̔��f
	    if (cell[i][j] < LIVE * MAX_COLOR)
	    {
		cell[i][j] = 1; //����
		count++;
	    }
	    else
	    {
		cell[i][j] = 0; //���S
	    }
	}
    }

    per = count / (PIXEL_NUM_X * PIXEL_NUM_Y); //���������̌v�Z

    return per * 100; //�������Ă��銄����߂�
}













