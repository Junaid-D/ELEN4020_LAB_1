#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Tensor2
{
	int rows;
	int cols;
	int** matrix;

}rank2Tensor;

typedef struct Tensor3
{
	int height;
	int rows;
	int cols;
	int*** matrix;

}rank3Tensor;

void disposeRank2Tensor(rank2Tensor* t)
{
	
	for(int i=0; i<t->rows; i++)
	{
		free(t->matrix[i]);

	}
	free(t->matrix);

}

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


void initRank2Tensor(rank2Tensor* t)
{
	t->matrix=malloc(t->rows*sizeof(int*));
	for(int i=0; i<t->rows; i++)
	{
		t->matrix[i]=malloc(t->cols*sizeof(int));
		for(int j=0; j<t->cols; j++)
			t->matrix[i][j]=rand()%10;

	}

}

void initRank3Tensor(rank3Tensor* t)
{
	t->matrix=malloc(t->rows*sizeof(int**));
	for(int i=0; i<t->height; i++)
	{
		t->matrix[i]=malloc(t->rows*sizeof(int*));
		for(int j=0; j<t->rows; j++)
		{
			t->matrix[i][j]=malloc(t->cols*sizeof(int));
		}

	}

}

rank2Tensor rank2TensorAdd(rank2Tensor* t1, rank2Tensor* t2)
{
	rank2Tensor res;
	res.cols=-1;
	res.rows=-1;
	res.matrix=NULL;

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
			printf("left %d + right %d res : %d\n",t1->matrix[i][j],t2->matrix[i][j], res.matrix[i][j]);
		}

	}
	return res;
}



int main()
{
	srand(time(NULL));

	rank2Tensor t2_0;
	t2_0.rows=3;
	t2_0.cols=3;
	initRank2Tensor(&t2_0);


	rank2Tensor t2_1;
	t2_1.rows=3;
	t2_1.cols=3;
	initRank2Tensor(&t2_1);




	rank2Tensor res=rank2TensorAdd(&t2_0,&t2_1);

	disposeRank2Tensor(&t2_0);
	disposeRank2Tensor(&t2_1);
	disposeRank2Tensor(&res);


	rank3Tensor t3;
	t3.rows=2;
	t3.height=2;
	t3.cols=2;
	initRank3Tensor(&t3);
	disposeRank3Tensor(&t3);


	return 0;
}