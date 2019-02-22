#include <stdlib.h>
#include <stdio.h>


const int RANDOM_RANGE_3=21;

typedef struct Tensor3
{
	int height;
	int rows;
	int cols;
	int*** matrix;

}rank3Tensor;



void disposeRank3Tensor(rank3Tensor* t)
{
	
	for(int i=0; i<t->height; i++)
	{
		for(int j=0; j<t->rows; j++)
		{
			free(t->matrix[i][j]);
		}
		free(t->matrix[i]);

	}
	free(t->matrix);

}




void initRank3Tensor(rank3Tensor* t)
{
	t->matrix=malloc(t->height*sizeof(int**));
	for(int i=0; i<t->height; i++)
	{
		t->matrix[i]=malloc(t->rows*sizeof(int*));
		for(int j=0; j<t->rows; j++)
		{
			t->matrix[i][j]=malloc(t->cols*sizeof(int));
			for(int k=0; k<t->cols; k++)
				t->matrix[i][j][k]=rand()%RANDOM_RANGE_3;
		}

	}

}

rank3Tensor rank3Tensoradd(rank3Tensor* t1, rank3Tensor* t2)
{
	rank3Tensor res;
	res.height=-1;
	res.cols=-1;
	res.rows=-1;
	res.matrix=NULL;
	/* error code default parameters*/
	if(t1->rows!=t2->rows || t1->cols!=t2->cols || t1->height!=t2->height)
		return res;

	res.cols=t1->cols;
	res.rows=t1->rows;
	res.height=t1->height;
	initRank3Tensor(&res);
	for(int i=0; i<res.height; i++)
	{
		for(int j=0; j<res.rows; j++)
		{
			for(int k=0; k<res.cols; k++)
			{
				res.matrix[i][j][k]=t1->matrix[i][j][k]+t2->matrix[i][j][k];
			}
		}
		
	}
	return res;
}

rank3Tensor rank3TensorMult(rank3Tensor* t1, rank3Tensor* t2)
{
	rank3Tensor res;
	res.cols=-1;
	res.rows=-1;
	res.matrix=NULL;
/* error code default parameters*/
	if(t1->cols!=t2->height )
		return res;
	res.cols=t1->cols; 


	res.height=t2->height;
	res.rows=t1->rows;

	initRank3Tensor(&res);
	for(int i=0; i<res.height; i++)
	{
		for(int j=0; j<res.rows; j++)
		{
			for(int k=0; k<res.cols; k++)
			{
				int sum=0;
				for(int l=0; l<t1->cols; l++)
	 			{
	 				sum+=t1->matrix[i][k][l]*t2->matrix[t2->height-1-l][j][k];
	 			}
	 			res.matrix[i][j][k]=sum;
			}
		}
	}
	return res;


}

void displayRank3Tensor(rank3Tensor* t)
{
	for(int i=0; i<t->height; i++)
	{
		printf("Level %d\n",i );
		for(int j=0; j<t->rows; j++)
		{
			printf("(");
			for(int k=0; k<t->cols; k++)
			{

				printf("%d,", t->matrix[i][j][k]);
			}
			printf("\b)\n");
		}
		
	}	
}

