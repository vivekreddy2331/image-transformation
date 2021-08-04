#include "filter.h"

int main()
{
    PPMImage *image;
    char name[50];
    int choice;
    scanf("%s",name);
    char input[]="./input/";
    strcat(input,name);
    image = readPPM(input);
    scanf("%d",&choice);
    
    char output[]="./output/";
    if(choice==1)
    {
    	image= grayscale(image);
    	writePPM(strcat(output,"grey.ppm"),image);
    }
    else if(choice==2)
    {
    	image=blur(image);
    	writePPM(strcat(output,"blur.ppm"),image);
    }
    else if(choice==3)
    {
    	image=blur(grayscale(image));
    	writePPM(strcat(output,"both.ppm"),image);
    }
    else
    {
    	printf("Wrong Option\n");
    }
}
