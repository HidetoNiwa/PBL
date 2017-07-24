/*ビットマップ製作ファイル*/
/*bmp.c*/
/*参考サイト　http://c-language-program.cocolog-nifty.com/blog/2010/03/bmp-4b2c.html
Cプログラミング日記　C言語プログラムに関する日記です。/BMPファイルを書き出すサンプルプログラム（2010年3月2日（火））
（最終閲覧日：2017年7月22日（土））*/

//各種ファイル・ライブラリーのインクルード
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "define.h"

//プロトタイプ宣言
int putBmpHeader(FILE *s, int x, int y, int c); //ヘッダファイル書き出し関数
int fputc2LowHigh(unsigned short d, FILE *s);
int fputc4LowHigh(unsigned long d, FILE *s);
int x, y, size;

//ファイルオープン
FILE *bmp_FileOpen(const char filename[], char mode[])
{
    FILE *fp;

    fp = fopen(filename, mode);

    return fp;
}

//ファイルクローズ
void bmp_FileClose(FILE *fp)
{
    fclose(fp);
}

//ファイル書き出し関数
int bmp_WriteImage(FILE *fp, unsigned char image[PIXEL_NUM_X][PIXEL_NUM_Y][PIC_COLOR])
{
    int r;

    /*ヘッダの書き出し*/
    r = putBmpHeader(fp, PIXEL_NUM_X, PIXEL_NUM_Y, COLOR_BIT);
    if (!r)
    {
        fclose(fp);
        return EXIT_FAILURE;
    }

    /* bitmapの書き出し*/

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

//ヘッダファイル書き出し関数
int putBmpHeader(FILE *s, int x, int y, int c)
{
    int i;
    int color;                   /* 色数 */
    unsigned long int bfOffBits; /* ヘッダサイズ(byte) */

    /* 画像サイズが異常の場合,エラーでリターン */
    if (x <= 0 || y <= 0)
    {
        return 0;
    }

    /* 出力ストリーム異常の場合、エラーでリターン */
    if (s == NULL || ferror(s))
    {
        return 0;
    }

    /* 色数を計算 */
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

    /* ヘッダサイズ(byte) */
    /* ヘッダサイズはビットマップファイルヘッダ(14) + ビットマップ情報ヘッダ(40) + 色数 */
    bfOffBits = 14 + 40 + 4 * color;

    /* ビットマップファイルヘッダ(計14byte)を書き出し */
    /* 識別文字列 */
    fputs("BM", s);

    /* bfSize ファイルサイズ(byte) */
    fputc4LowHigh(bfOffBits + (unsigned long)x * y, s);

    /* bfReserved1 予約領域1(byte) */
    fputc2LowHigh(0, s);

    /* bfReserved2 予約領域2(byte) */
    fputc2LowHigh(0, s);

    /* bfOffBits ヘッダサイズ(byte) */
    fputc4LowHigh(bfOffBits, s);

    /*ビットマップ情報ヘッダ(計40byte) */
    /* biSize 情報サイズ(byte) */
    fputc4LowHigh(40, s);

    /* biWidth 画像Xサイズ(dot) */
    fputc4LowHigh(x, s);

    /* biHeight 画像Yサイズ(dot) */
    fputc4LowHigh(y, s);

    /* biPlanes 面数*/
    fputc2LowHigh(1, s);

    /* biBitCount 色ビット数(bit/dot) */
    fputc2LowHigh(c, s);

    /* biCompression 圧縮方式 */
    fputc4LowHigh(0, s);

    /* biSizeImage 圧縮サイズ(byte) */
    fputc4LowHigh(0, s);

    /* biXPelsPerMeter 水平解像度(dot/m) */
    fputc4LowHigh(0, s);

    /* biYPelsPerMeter 垂直解像度(dot/m) */
    fputc4LowHigh(0, s);

    /* biClrUsed 色数 */
    fputc4LowHigh(0, s);

    /* biClrImportant 重要色数 */
    fputc4LowHigh(0, s);

    /* 書き出し失敗ならエラーでリターン */
    if (ferror(s)){
        return 0;
    }

    /* 成功でリターン */
    return 1;
}

//2バイトデータ書き出し関数
int fputc2LowHigh(unsigned short d, FILE *s){
    putc(d & 0xFF, s);
    return putc(d >> CHAR_BIT, s);
}

//4バイトデータ書き出し関数
int fputc4LowHigh(unsigned long d, FILE *s){
    putc(d & 0xFF, s);
    putc((d >> CHAR_BIT) & 0xFF, s);
    putc((d >> CHAR_BIT * 2) & 0xFF, s);
    return putc((d >> CHAR_BIT * 3) & 0xFF, s);
}