#include "StdAfx.h"
#include "IsToeplitzMatrix.h"
//1 2 3 4											00 11 22        01 12 23    02 13 
//
//5 1 2 3											10 21					
//
//9 5 1 2

bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) //可用 网站接受 
{

	int row = 0,col = 0;
	int matrixColSize = 0;
	int offset = 0;
	matrixColSize = *matrixColSizes;
	for(row = 0;row <matrixRowSize;row++)
	{
		for(col = 0;col <matrixColSize;col++)
		{
			if(col <= row)
			{
				offset = row - col;
				if( matrix[row][col] != matrix[offset][0])
				{
					return 0;
				}
			}
			else
			{
				offset = col - row;
				if( matrix[row][col] != matrix[0][offset])
				{
					return 0;
				} 
			}
		}
	}

	return 1;
}

bool isToeplitzMatrix2(int** matrix, int matrixRowSize, int *matrixColSizes)//可用 网站接受 
{

	int row = 0,col = 0;
	int matrixColSize = 0;
	int offset = 0;
	matrixColSize = *matrixColSizes;
	for(row = 0;row <matrixRowSize-1;row++)
	{
		for(col = 0;col <matrixColSize-1;col++)
		{
			if( matrix[row][col] != matrix[row+1][col+1])
			{
				return 0;
			}
		}
	}

	return 1;
}

bool isToeplitzMatrix1(int** matrix1, int matrixRowSize1, int *matrixColSizes1) //不可用 存在bug 
{

	int row = 0,col = 0;
	//int matrixColSize = 0;
	//matrixColSize = *matrixColSizes;

	int matrix[3][1] = {83,64,57};
	int matrixColSize = 1;
	int matrixRowSize = 3;
	for(int i = 0;i<matrixRowSize;i++)
	{

		for(int j = 0;j<matrixColSize;j++)
		{
			printf("%d ,",matrix[i][j]);
		}
		printf("\n");
	}

	for(row = 0;row <matrixRowSize;row++)
	{
		for(col = 0;col <matrixColSize - row;col++)
		{

			if(matrix[row][col + row] != matrix[0][col])
			{
				printf("上三角第%d行,第%d列，左值为%d，右值为%d\n",row,col,matrix[row][col + row],matrix[0][col]);

				return 0;
			}
			else
			{

			}
		}
	}
	for(row = 1;row <matrixRowSize;row ++)
	{
		for(col = 0;col <matrixRowSize - row;col ++)	
		{
			if((matrix[row+col][col] != matrix[row][0])&&(col + row < matrixRowSize))
			{
				printf("下三角第%d行,第%d列，左值为%d，右值为%d\n",row,col,matrix[row][col + row],matrix[0][col]);

				return 0;
			}
			else
			{

			}

		}

	}
	return 1;
}
