#include <stdio.h> 
#include <stdlib.h>
void StepRigth(double *array, int N);
int main(void) {
	FILE *IN;
	double x;
	double *A;
	int N = 0,i;
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
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	A = (double*)malloc(N*sizeof(double));
	for (i = 0; i < N; i++) {
		fscanf(IN, "%lf", &A[i]);
	}
	fclose(IN);
	StepRigth(A, N);
	for (i = 0; i < N; i++) {
		printf("%lf",A[i]);
	}
	return 0;
}
void StepRigth(double *A, int N) {
	double last;
	int i;
	last = A[N-1];
	for (i = 0; i < N; i++) {
		A[N-1-i] = A[N-2-i];
	}
	A[0] = last;
}
	