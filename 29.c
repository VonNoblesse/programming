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
	C = (double*)malloc((a+b)*sizeof(double));
	c = 0;
	i = 0;
	j = 0;
	k = 0;
	while(c != a+abs(a-b)) {
		printf("%lf %lf\n", A[i],B[j]);
		if (A[i] < B[j]) {
			C[k] = A[i];
			++k;
			++i;
		}
		else if (A[i] > B[j]) {
			C[k] = B[j];
			++k;
			++j;
		}
		else if (A[i] == B[j]) {
			++j;
			++i;
		}
		if (i > a)
			C[k-1] = B[j];
		if (j > b)
			C[k-1] = A[i];
		++c;
	}
	printf("%d %d", i,j);
	for (i = 0;i < k;i++)
		printf("%lf ", C[i]);
	return 0;
}
	
