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
	t->matrix=malloc(t->height*sizeof(int**));
	for(int i=0; i<t->height; i++)
	{
		t->matrix[i]=malloc(t->rows*sizeof(int*));
		for(int j=0; j<t->rows; j++)
		{
			t->matrix[i][j]=malloc(t->cols*sizeof(int));
			for(int k=0; k<t->cols; k++)
				t->matrix[i][j][k]=rand()%10;
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




rank2Tensor rank2TensorMult(rank2Tensor* t1, rank2Tensor* t2)
{
	rank2Tensor res;
	res.cols=-1;
	res.rows=-1;
	res.matrix=NULL;

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


rank3Tensor rank3TensorAdd(rank3Tensor* t1, rank3Tensor* t2)
{
	printf("%s\n","Rank3 Addition:" );
	rank3Tensor res;
	res.height=-1;
	res.cols=-1;
	res.rows=-1;
	res.matrix=NULL;

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
				printf("left %d + right %d res : %d\n",t1->matrix[i][j][k],t2->matrix[i][j][k], res.matrix[i][j][k]);
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

	if(t1->cols!=t2->height)// there are likely other criteria
		return res;

	res.cols=t1->rows;
	res.height=t1->height;
	res.rows=t2->cols; 

	initRank3Tensor(&res);
	for(int i=0; i<res.height; i++)
	{
		for(int j=0; j<res.rows; j++)
		{
			for(int k=0; k<res.rows; k++)
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



int main()
{
	srand(time(NULL));

	rank2Tensor t2_0;
	t2_0.rows=3;
	t2_0.cols=2;
	initRank2Tensor(&t2_0);


	rank2Tensor t2_1;
	t2_1.rows=2;
	t2_1.cols=3;
	initRank2Tensor(&t2_1);

	printf("%s\n", "Mat1" );
	displayRank2Tensor(&t2_0);
	printf("%s\n", "Mat2");
	displayRank2Tensor(&t2_1);

	printf("%s\n", "Result" );
	rank2Tensor resMult=rank2TensorMult(&t2_0,&t2_1);

	displayRank2Tensor(&resMult);
	rank2Tensor res=rank2TensorAdd(&t2_0,&t2_1);

	disposeRank2Tensor(&t2_0);
	disposeRank2Tensor(&t2_1);
	disposeRank2Tensor(&res);
	disposeRank2Tensor(&resMult);


	rank3Tensor t3;
	t3.rows=3;
	t3.height=3;
	t3.cols=3;
	initRank3Tensor(&t3);

	rank3Tensor res3=rank3TensorAdd(&t3,&t3);
	rank3Tensor res3mul=rank3TensorMult(&t3,&t3);
	printf("T3 :\n" );
	displayRank3Tensor(&t3);

	printf("Mul Res: \n" );
	displayRank3Tensor(&res3mul);

	disposeRank3Tensor(&res3mul);
	disposeRank3Tensor(&res3);
	disposeRank3Tensor(&t3);


	return 0;
}