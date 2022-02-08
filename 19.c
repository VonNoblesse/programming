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
	if (A == NULL) {
		printf("error");
		return -1;
	}
	for (i = 0; i < N; i++) {
		if (fscanf(IN, "%lf", &A[i]) != 1) {
			printf("not enough numbers");
			return -1;
		}
	}
	fclose(IN);
	for (i = 0; i <= (N-1)/2; i++) {
		if (A[i] != A[(N-1)-i]) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
	}
	
	
	