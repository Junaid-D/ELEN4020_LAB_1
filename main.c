#include<stdio.h>
#include<stdlib.h>

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
		t->flattened[i]=0;

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
	int elemPer_0[] = {10,10};

	Tensor t;

	t.noDims=2;
	t.elemPerDim= elemPer_0;
	t.totalEntries=totalElements(t.noDims,t.elemPerDim);
	initFlat(&t);

	free(t.flattened);
	return 0;
}