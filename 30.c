#include <stdio.h>
#include <stdlib.h>
int main(void) {
	double *A,*B,*C;
	int i,j,k;
	int a,b,c;
	if (scanf("%d %d", &a,&b) != 2) {
		printf("not enough numbers");
		return -1;
	}
	A = (double*)malloc(a*sizeof(double));
	B = (double*)malloc(b*sizeof(double));
	for (i = 0;i < a;i++) {
		scanf("%lf",&A[i]);
	}
	for (i = 0;i < b;i++) {
		scanf("%lf",&B[i]);
	}
	if (a < b)
		c = a;
	else
		c = b;
	C = (double*)malloc(c*sizeof(double));
	b = 0;
	i = 0;
	j = 0;
	k = 0;
	while(b != c) {
		if (A[i] < B[j])
			++i;
		if (A[i] > B[j])
			++j;
		if (A[i] == B[j]) {
			C[k] = A[i];
			++k;
			++j;
			++i;
		}
		++b;
	}
	for (i = 0;i < k;i++)
		printf("%lf ", C[i]);
	return 0;
}
	
