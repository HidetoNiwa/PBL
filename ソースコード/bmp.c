/*�r�b�g�}�b�v����t�@�C��*/
/*bmp.c*/
/*�Q�l�T�C�g�@http://c-language-program.cocolog-nifty.com/blog/2010/03/bmp-4b2c.html
C�v���O���~���O���L�@C����v���O�����Ɋւ�����L�ł��B/BMP�t�@�C���������o���T���v���v���O�����i2010�N3��2���i�΁j�j
�i�ŏI�{�����F2017�N7��22���i�y�j�j*/

//�e��t�@�C���E���C�u�����[�̃C���N���[�h
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "define.h"

//�v���g�^�C�v�錾
int putBmpHeader(FILE *s, int x, int y, int c); //�w�b�_�t�@�C�������o���֐�
int fputc2LowHigh(unsigned short d, FILE *s);
int fputc4LowHigh(unsigned long d, FILE *s);
int x, y, size;

//�t�@�C���I�[�v��
FILE *bmp_FileOpen(const char filename[], char mode[])
{
    FILE *fp;

    fp = fopen(filename, mode);

    return fp;
}

//�t�@�C���N���[�Y
void bmp_FileClose(FILE *fp)
{
    fclose(fp);
}

//�t�@�C�������o���֐�
int bmp_WriteImage(FILE *fp, unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR])
{
    int r;

    /*�w�b�_�̏����o��*/
    r = putBmpHeader(fp, PIXEL_NUM_X, PIXEL_NUM_Y, COLOR_BIT);
    if (!r)
    {
        fclose(fp);
        return EXIT_FAILURE;
    }

    /* bitmap�̏����o��*/

    for (x = 0; x < PIXEL_NUM_X; x++)
    {
        for (y = 0; y < PIXEL_NUM_Y; y++)
        {
            for (size = 0; size < PIC_COLOR; size++)
            {
                fprintf(fp, "%c", image[x][y][size]);
            }
        }
    }

    if (r != PIC_DATA_SIZE)
    {
        fclose(fp);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

//�w�b�_�t�@�C�������o���֐�
int putBmpHeader(FILE *s, int x, int y, int c)
{
    int i;
    int color;                   /* �F�� */
    unsigned long int bfOffBits; /* �w�b�_�T�C�Y(byte) */

    /* �摜�T�C�Y���ُ�̏ꍇ,�G���[�Ń��^�[�� */
    if (x <= 0 || y <= 0)
    {
        return 0;
    }

    /* �o�̓X�g���[���ُ�̏ꍇ�A�G���[�Ń��^�[�� */
    if (s == NULL || ferror(s))
    {
        return 0;
    }

    /* �F�����v�Z */
    if (c == 24)
    {
        color = 0;
    }
    else
    {
        color = 1;
        for (i = 1; i <= c; i++)
        {
            color *= 2;
        }
    }

    /* �w�b�_�T�C�Y(byte) */
    /* �w�b�_�T�C�Y�̓r�b�g�}�b�v�t�@�C���w�b�_(14) + �r�b�g�}�b�v���w�b�_(40) + �F�� */
    bfOffBits = 14 + 40 + 4 * color;

    /* �r�b�g�}�b�v�t�@�C���w�b�_(�v14byte)�������o�� */
    /* ���ʕ����� */
    fputs("BM", s);

    /* bfSize �t�@�C���T�C�Y(byte) */
    fputc4LowHigh(bfOffBits + (unsigned long)x * y, s);

    /* bfReserved1 �\��̈�1(byte) */
    fputc2LowHigh(0, s);

    /* bfReserved2 �\��̈�2(byte) */
    fputc2LowHigh(0, s);

    /* bfOffBits �w�b�_�T�C�Y(byte) */
    fputc4LowHigh(bfOffBits, s);

    /*�r�b�g�}�b�v���w�b�_(�v40byte) */
    /* biSize ���T�C�Y(byte) */
    fputc4LowHigh(40, s);

    /* biWidth �摜X�T�C�Y(dot) */
    fputc4LowHigh(x, s);

    /* biHeight �摜Y�T�C�Y(dot) */
    fputc4LowHigh(y, s);

    /* biPlanes �ʐ�*/
    fputc2LowHigh(1, s);

    /* biBitCount �F�r�b�g��(bit/dot) */
    fputc2LowHigh(c, s);

    /* biCompression ���k���� */
    fputc4LowHigh(0, s);

    /* biSizeImage ���k�T�C�Y(byte) */
    fputc4LowHigh(0, s);

    /* biXPelsPerMeter �����𑜓x(dot/m) */
    fputc4LowHigh(0, s);

    /* biYPelsPerMeter �����𑜓x(dot/m) */
    fputc4LowHigh(0, s);

    /* biClrUsed �F�� */
    fputc4LowHigh(0, s);

    /* biClrImportant �d�v�F�� */
    fputc4LowHigh(0, s);

    /* �����o�����s�Ȃ�G���[�Ń��^�[�� */
    if (ferror(s)){
        return 0;
    }

    /* �����Ń��^�[�� */
    return 1;
}

//2�o�C�g�f�[�^�����o���֐�
int fputc2LowHigh(unsigned short d, FILE *s){
    putc(d & 0xFF, s);
    return putc(d >> CHAR_BIT, s);
}

//4�o�C�g�f�[�^�����o���֐�
int fputc4LowHigh(unsigned long d, FILE *s){
    putc(d & 0xFF, s);
    putc((d >> CHAR_BIT) & 0xFF, s);
    putc((d >> CHAR_BIT * 2) & 0xFF, s);
    return putc((d >> CHAR_BIT * 3) & 0xFF, s);
}