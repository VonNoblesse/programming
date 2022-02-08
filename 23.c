#include <stdio.h>
#include <stdlib.h>
void NeighbourSum(double *A, int N);
int main(void) {
	FILE *IN;
	int i,N = 0;
	double *A;
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
	while (fscanf(IN, "%lf", &x) == 1) {
		++N;
	}
	A = (double*)malloc(N*sizeof(double));
	fclose(IN);
	IN = fopen("tmp.dat","r");
	for (i = 0; i < N; i++) {
		fscanf(IN, "%lf", &A[i]);
	}
	NeighbourSum(A,N);
	for (i = 0; i < N; i++) {
		printf("%lf ", A[i]);
	}
	return 0;
}
void NeighbourSum(double *A, int N) {
	int i;
	double t,sup;
	t = A[0];
	for (i = 1; i < N-1; i++) {
		sup = A[i];
		A[i] = (t+A[i+1])/2;
		t = sup;
	}
}