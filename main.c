#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rank2Tensor.h"
#include "rank3Tensor.h"



int main()
{
	srand(time(NULL));
	int bound0=10;
	int bound1=20;
	
/*	
****snippet shows how to create and multiply two 3d vectors, print results,
	 and free allocated memory

	rank3Tensor t3;
	t3.rows=3;
	t3.height=3;
	t3.cols=3;
	initRank3Tensor(&t3);

	rank3Tensor res3=rank3Tensoradd(&t3,&t3);
	rank3Tensor res3mul=rank3TensorMult(&t3,&t3);
	printf("T3 :\n" );
	displayRank3Tensor(&t3);

	printf("Mul Res: \n" );
	displayRank3Tensor(&res3mul);

	disposeRank3Tensor(&res3mul);
	disposeRank3Tensor(&res3);
	disposeRank3Tensor(&t3);
*/

	rank2Tensor a_t2_0;
	rank2Tensor a_t2_1;
	rank2Tensor b_t2_0;
	rank2Tensor b_t2_1;
	
	
	a_t2_0.rows=bound0;
	a_t2_0.cols=bound0;
	initRank2Tensor(&a_t2_0);

	b_t2_0.rows=bound0;
	b_t2_0.cols=bound0;	
	initRank2Tensor(&b_t2_0);
	
	a_t2_1.rows=bound1;
	a_t2_1.cols=bound1;
	initRank2Tensor(&a_t2_1);
	
	b_t2_1.rows=bound1;
	b_t2_1.cols=bound1;	
	initRank2Tensor(&b_t2_1);
	
	rank2Tensor c_t2_0_add=rank2Tensoradd(&a_t2_0,&b_t2_0);
	rank2Tensor c_t2_0_mult=rank2TensorMult(&a_t2_0,&b_t2_0);
	rank2Tensor c_t2_1_add=rank2Tensoradd(&a_t2_1,&b_t2_1);
	rank2Tensor c_t2_1_mult=rank2TensorMult(&a_t2_1,&b_t2_1);
	
	disposeRank2Tensor(&a_t2_0);
	disposeRank2Tensor(&b_t2_0);
	disposeRank2Tensor(&c_t2_0_add);
	disposeRank2Tensor(&c_t2_0_mult);
	disposeRank2Tensor(&a_t2_1);
	disposeRank2Tensor(&b_t2_1);
	disposeRank2Tensor(&c_t2_1_add);	
	disposeRank2Tensor(&c_t2_1_mult);

	
	rank3Tensor a_t3_0;
	rank3Tensor a_t3_1;
	rank3Tensor b_t3_0;
	rank3Tensor b_t3_1;
	
	a_t3_0.rows=bound0;
	a_t3_0.cols=bound0;
	a_t3_0.height=bound0;
	initRank3Tensor(&a_t3_0);
	
	b_t3_0.rows=bound0;
	b_t3_0.cols=bound0;	
	b_t3_0.height=bound0;
	initRank3Tensor(&b_t3_0);
	
	a_t3_1.rows=bound1;
	a_t3_1.cols=bound1;
	a_t3_1.height=bound1;
	initRank3Tensor(&a_t3_1);
	
	b_t3_1.rows=bound1;
	b_t3_1.cols=bound1;
	b_t3_1.height=bound1;
	initRank3Tensor(&b_t3_1);
	
	rank3Tensor c_t3_0_add=rank3Tensoradd(&a_t3_0,&b_t3_0);
	rank3Tensor c_t3_0_mult=rank3TensorMult(&a_t3_0,&b_t3_0);
	rank3Tensor c_t3_1_add=rank3Tensoradd(&a_t3_1,&b_t3_1);
	rank3Tensor c_t3_1_mult=rank3TensorMult(&a_t3_1,&b_t3_1);
	
	disposeRank3Tensor(&a_t3_0);
	disposeRank3Tensor(&b_t3_0);
	disposeRank3Tensor(&c_t3_0_add);
	disposeRank3Tensor(&c_t3_0_mult);
	disposeRank3Tensor(&a_t3_1);
	disposeRank3Tensor(&b_t3_1);
	disposeRank3Tensor(&c_t3_1_add);	
	disposeRank3Tensor(&c_t3_1_mult);
	return 0;
}