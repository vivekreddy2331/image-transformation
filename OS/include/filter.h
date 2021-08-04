#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef FILTER_H
#define FILTER_H


typedef struct {
     int x, y;
     unsigned char *data;
} PPMImage;

typedef struct{
    int x;
    int y;
    float **a;
} mat;

typedef struct{
	mat* matr;
} matrix;

#define CREATOR "HARI"
#define RGB_COMPONENT_COLOR 255

PPMImage *readPPM(const char *filename);

void writePPM(const char *filename,PPMImage *img);

PPMImage *grayscale(PPMImage *img);
PPMImage *blur(PPMImage* image);

int multiply(matrix P, matrix A, matrix B);

#endif
