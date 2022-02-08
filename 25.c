#include <stdio.h>
#include <stdlib.h>
void replace(double *A,int N, int k);
int main(void) {
	FILE *IN;
	double *A;
	int N = 0,k,i;
	double x;
	IN = fopen("tmp.dat","r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	if (fscanf(IN, "%lf", &x) != 1) {
		printf("empty file");
		return -1;
	}
	++N;
	while (fscanf(IN, "%lf", &x) == 1)
		++N;
	fclose(IN);
	IN = fopen("tmp.dat","r");
	A = (double*)malloc(N*sizeof(double));
	for (i = 0; i<N; i++) {
		fscanf(IN, "%lf", &A[i]);
	}
	fclose(IN);
	printf("\n");
	printf("enter k\n");
	scanf("%d",&k);
	replace(A,N,k);
	for (i = 0; i<N; i++) {
		printf("%f ", A[i]);
	}
	return 0;
}
void replace(double *A,int N, int k) {
	int i;
	double t;
	for (i = 0; i < k-1; i++) {
		if (A[k-2-i]>A[k-1-i]) {
			t = A[k-2-i];
			A[k-2-i] = A[k-i-1];
			A[k-i-1] = t;
		} else
			break;
	}
}