#include <stdlib.h>
#include <stdio.h>

const int RANDOM_RANGE_2=21;

typedef struct Tensor2
{
	int rows;
	int cols;
	int** matrix;

}rank2Tensor;


void disposeRank2Tensor(rank2Tensor* t)
{
	
	for(int i=0; i<t->rows; i++)
	{
		free(t->matrix[i]);

	}
	free(t->matrix);

}

void initRank2Tensor(rank2Tensor* t)
{
	t->matrix=malloc(t->rows*sizeof(int*));
	for(int i=0; i<t->rows; i++)
	{
		t->matrix[i]=malloc(t->cols*sizeof(int));
		for(int j=0; j<t->cols; j++)
			t->matrix[i][j]=rand()%RANDOM_RANGE_2;

	}

}


rank2Tensor rank2Tensoradd(rank2Tensor* t1, rank2Tensor* t2)
{
	rank2Tensor res;
	res.cols=-1;
	res.rows=-1;
	res.matrix=NULL;
/* error code default parameters*/

	if(t1->rows!=t2->rows || t1->cols!=t2->cols)
		return res;

	res.cols=t1->cols;
	res.rows=t1->rows;

	initRank2Tensor(&res);
	for(int i=0; i<res.rows; i++)
	{

		for(int j=0; j<res.cols; j++)
		{
			res.matrix[i][j]=t1->matrix[i][j]+t2->matrix[i][j];
		}

	}
	return res;
}


rank2Tensor rank2TensorMult(rank2Tensor* t1, rank2Tensor* t2)
{
	rank2Tensor res;
	res.cols=-1;
	res.rows=-1;
	res.matrix=NULL;
/* error code default parameters*/
	if(t1->cols!=t2->rows)
		return res;

	res.cols=t1->rows;
	res.rows=t2->cols; 

	initRank2Tensor(&res);
	for(int i=0; i<res.rows; i++)
	{
		for(int j=0; j<res.rows; j++)
		{
			int sum=0;
			for(int k=0; k<t1->cols; k++)
 			{
 				sum+=t1->matrix[i][k]*t2->matrix[k][j];
 			}
 			res.matrix[i][j]=sum;
		}
	}
	return res;


}

void displayRank2Tensor(rank2Tensor* t)
{
	for(int i=0; i<t->rows; i++)
	{
		printf("(");
		for(int j=0; j<t->cols; j++)
		{

			printf("%d,", t->matrix[i][j]);
		}
		printf("\b)\n");
	}
}
