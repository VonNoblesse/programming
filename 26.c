#include <stdio.h>
#include <stdlib.h>
void sort(double *A, int k);
int main(void) {
	FILE *IN;
	double *A;
	int N = 0,i;
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
		printf("%lf ",A[i]);
	}
	fclose(IN);
	printf("\n");
	for (i = 2; i<N; i++) 
		sort(A,i);
	for (i = 0; i<N; i++) {
		printf("%lf ", A[i]);
	}
	return 0;
}
void sort(double *A, int k) {
	int i;
	double t;
	for (i = 0; i < k; i++) {
		if (A[k-2-i]>A[k-1-i]) {
			t = A[k-2-i];
			A[k-2-i] = A[k-i-1];
			A[k-i-1] = t;
		} else
			break;
	}
}