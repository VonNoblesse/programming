#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sort(double *A, int k);
int check(double *A, double *B,int N,int M, int mx);
double fmin(double a, double b);
double fmax(double a, double b);
int main(void) {
	int i,M = 0,N = 0,mx;
	double a,b;
	double *A,*B;
	FILE *inA,*inB,*out;
	inA = fopen("ina.txt","r");
	if (inA == NULL)
		return -1;
	while (fscanf(inA,"%lf",&a) == 1)
		++N;
	if (N == 0) {
		printf("empty file A");
		return -1;
	}
	fclose(inA);
	inB = fopen("inb.txt","r");
	if (inB == NULL)
		return -1;
	while (fscanf(inB,"%lf",&b) == 1)
		++M;
	if (M == 0) {
		printf("empty file B");
		return -1;
	}
	fclose(inB);
	if ((N < 2)&&(M < 2))
		return -1;
	mx = fmax(N,M);
	A = (double*)malloc(N*sizeof(double));
	B = (double*)malloc(M*sizeof(double));
	inA = fopen("ina.txt","r");
	inB = fopen("inb.txt","r");
	for (i = 0;i < mx;i++) {
		if (i < N)
			fscanf(inA,"%lf",&A[i]);
		if (i < M)
			fscanf(inB,"%lf",&B[i]);
	}
	a = A[0];
	b = B[0];
	for (i = 0; i < N; i++)
		printf("%lf ",A[i]);
	printf("\n");
	for (i = 0; i < M; i++)
		printf("%lf ",B[i]);
	printf("\n");
	sort(A,N);
	sort(B,M);
	printf("\n");
	for (i = 0; i < N; i++)
		printf("%lf ",A[i]);
	printf("\n");
	for (i = 0; i < M; i++)
		printf("%lf ",B[i]);
	printf("\n");
	out = fopen("output.txt","w");
	if (out == NULL) {
		printf("error with out");
		return -1;
	}
	if (check(A,B,N,M,mx) == 1)
		fprintf(out,"YES");
	else
		fprintf(out,"NO");
	fclose(inA);
	fclose(inB);
	fclose(out);
	return 0;
}
void sort(double *A, int k) {
	double t;
	int i,j;
	for (i = 0; i < k - 1; i++) {
		for (j = 0; j < k - 1 - i; j++) {
			if (A[j] > A[j+1]) {
				t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}
}
int check(double *A, double *B,int N,int M, int mx) {
	int i;
	for (i = 0;i < mx-1;i++)
		if ((i < N-1)&&(i < M-1)) {
			if ((A[i]-B[i]) != (A[i+1]-B[i+1])) {
				printf("%lf %lf; %lf %lf 1",A[i],A[i+1],B[i],B[i+1]);
				return 0;
			}
		}
		else if ((i >= N-1)&&(i < M-1)) {
			if (B[i]!=B[i+1]) 
				return 0;
		}
		else if ((i < N-1)&&(i >= M-1)) {
			if (A[i]!=A[i+1]) 
				return 0;
		}
	return 1;
}
double fmin(double a, double b) {
	if (a > b)
		return b;
	else
		return a;
}
double fmax(double a, double b) {
	if (a > b)
		return a;
	else
		return b;
}