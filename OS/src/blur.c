#include "filter.h"

PPMImage* blur(PPMImage* image)
{
	float kernel[3][3] = {
				{0.0625, 0.125/2.0, 0.0625 },
				{0.125,  0.25/2.0,  0.125},
				{0.0625, 0.125/2.0,  0.0625}
		 	};
	int width=image->x;
	int height=image->y;
	unsigned int ofs;
	for(int x=1;x<height-1;x++)
		{					
			for(int y=1;y<width-1;y++)
			{
				float sum0= 0.0;
				float sum1= 0.0;
				float sum2= 0.0;
				for(int i=-1;i<=1;++i)
				{
					for(int j=-1;j<=1;++j)			//matrix multiplication with kernel with every color plane
					{			
						ofs = (x * image->x) + y;	
						sum0=sum0+(float)kernel[i+1][j+1]*image->data[3*ofs];
						sum1=sum1+(float)kernel[i+1][j+1]*image->data[3*ofs+1];
						sum2=sum2+(float)kernel[i+1][j+1]*image->data[3*ofs+2];
					}
				}
				ofs = (x * image->x) + y;
				image->data[3*ofs]=(unsigned char)sum0;
				image->data[3*ofs+1]=(unsigned char)sum1;
				image->data[3*ofs+2]=(unsigned char)sum2;
			}
		}
		return image;

}

