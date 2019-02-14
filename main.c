#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Tensor
{
	int noDims;
	int* elemPerDim;
	int* flattened;
	int totalEntries;

}Tensor;

void initFlat(Tensor* t)
{
	t->flattened= (int*)malloc(t->totalEntries*sizeof(int));
	for(int i=0; i<t->totalEntries; i++)
		t->flattened[i]=rand()%10;

}

void initElemsPerDim(Tensor* t, int* elemPerDim)
{
	t->elemPerDim=malloc(t->noDims*sizeof(int));
	for(int i=0; i<t->noDims; i++)
	{
		t->elemPerDim[i]=elemPerDim[i];

	}

}

Tensor rank2TensorAdd(Tensor* t1, Tensor* t2)
{

	Tensor res;
	res.noDims=0;//error case
	res.totalEntries=-1;//error case

	if(t1->noDims!=2 || t2->noDims!=2)
		return res;

	if(t1->elemPerDim[0]!=t2->elemPerDim[0] || t1->elemPerDim[1]!=t2->elemPerDim[1])
		return res;

	res.noDims=2;
	res.totalEntries=t1->totalEntries;
	initElemsPerDim(&res,t1->elemPerDim);
	initFlat(&res);
	for (int i=0; i<t1->totalEntries; i++)
	{
		res.flattened[i]=t1->flattened[i]+t2->flattened[i];
		printf("%d%s%d\t%d\n",t1->flattened[i],"+",t2->flattened[i],res.flattened[i]);
	}
	return res;

}

int totalElements(int noDims, int* elemPerDim)
{
	int ans=1;
	for(int i=0; i<noDims; i++)
	{
		ans*=elemPerDim[i];
	}
	return ans;

}



int main()
{
	srand(time(NULL));

	int elemPer_0[] = {10,10};

	Tensor t;
	t.noDims=2;
	initElemsPerDim(&t,elemPer_0);
	t.totalEntries=totalElements(t.noDims,t.elemPerDim);
	initFlat(&t);

	Tensor t2;
	t2.noDims=2;
	initElemsPerDim(&t2,elemPer_0);
	t2.totalEntries=totalElements(t2.noDims,t2.elemPerDim);
	initFlat(&t2);

	Tensor res = rank2TensorAdd(&t,&t2);


	free(res.flattened);
	free(res.elemPerDim);

	free(t.flattened);
	free(t.elemPerDim);

	free(t2.flattened);
	free(t2.elemPerDim);
	return 0;
}