#include "filter.h"


int multiply(matrix P, matrix A, matrix B)
{
	if(A.matr->y!=B.matr->x)
		return 1;

	for(int i=0;i<A.matr->x;i++)
	{
		for(int j=0;j<B.matr->y;j++)
		 {
		    *(*(P.matr->a+i)+j) = 0;
		   	for(int k=0; k<B.matr->y;k++)
			{
		  		*(*(P.matr->a+i)+j)= *(*(P.matr->a+i)+j)+ *(*(A.matr->a+i)+k) *  *(*(B.matr->a+k)+j);
			}
		 }
	}

	return 0;
}

