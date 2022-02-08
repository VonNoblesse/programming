#include <stdio.h>
#include <stdlib.h>
int main(void) {
	double *A;
	double x;
	int N = 0,i;
	FILE *IN;
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
	fclose(IN);
	IN = fopen("tmp.dat","r");
	A = (double*)malloc(N*sizeof(double));
	for (i = 0; i < N; i++) {
		fscanf(IN, "%lf", &A[i]);
	}
	if (A == NULL) {
		printf("error");
		return -1;
	}
	fclose(IN);
	for (i = 0; i < N/2; i++) {
		A[i] = A[i]+A[(N-1)-i];
		A[(N-1)-i] = A[i]-A[(N-1)-i];
		A[i] = A[i]-A[(N-1)-i];
	}
	for (i = 0; i < N; i++) {
		printf("%lf\n",A[i]);
	}
	return 0;
	}
	
	
	
	
	
	