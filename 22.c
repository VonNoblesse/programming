#include <stdio.h>
#include <stdlib.h>
void kStepLeft(double *A, int N, int k);
int main(void) {
	FILE *IN;
	int k,i,N = 0;
	double *A;
	double x;
	scanf("%d", &k);
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
	kStepLeft(A,N,N-k);
	for (i = 0; i < N; i++) {
		printf("%lf ", A[i]);
	}
	return 0;
}
void kStepLeft(double *A, int N, int k) {
	int i;
	for (i = 0; i < N/2; i++) {
		A[i] = A[i]+A[(N-1)-i];
		A[(N-1)-i] = A[i]-A[(N-1)-i];
		A[i] = A[i]-A[(N-1)-i];
	}
	for (i = 0; i < k/2; i++) {
		A[i] = A[i]+A[(k-1)-i];
		A[(k-1)-i] = A[i]-A[(k-1)-i];
		A[i] = A[i]-A[(k-1)-i];
	}
	for (i = 0; i < (N-k)/2; i++) {
		A[i+k] = A[i+k]+A[(N-1)-i];
		A[(N-1)-i] = A[i+k]-A[(N-1)-i];
		A[i+k] = A[i+k]-A[(N-1)-i];
	}
}