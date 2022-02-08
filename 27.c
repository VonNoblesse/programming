#include <stdio.h>
#include <stdlib.h>
void advanced_sort(double *A, int k);
int check(double *A, int k);
int main(void){
	double *A;
	int i = 0,k;
	FILE *IN;
	IN = fopen("tmp.dat","r");
	if (IN == NULL) 
		return -1;
	fscanf(IN,"%d",&k);
	k = 2*k;
	A = (double *)malloc(k*sizeof(double));
	while (fscanf(IN,"%lf %lf",&A[i],&A[i+1]) == 2)
		i += 2;
	if ((i == 0)||(i != k)) {
		printf("not enough numbers");
		return -1;
	}
	for (i = 0; i < k; i++) {
		printf("%lf ",A[i]);
	}
	printf("\n");
	advanced_sort(A,k);
	for (i = 0; i < k; i++) {
		printf("%lf ",A[i]);
	}
	printf("\n");
	if (check(A,k) == 1)
		printf("Yes");
	else
		printf("No");
	return 0;
	fclose(IN);
}
void advanced_sort(double *A, int k) {
	double t;
	int i,j;
	for (i = 0; i < k - 1; i++) {
		for (j = 0; j < k - 2 - i; j++) {
			if ((A[j] > A[j+2])&&(j % 2 == 0)) {
				t = A[j];
				A[j] = A[j+2];
				A[j+2] = t;
				t = A[j+1];
				A[j+1] = A[j+3];
				A[j+3] = t;
			}
		}
	}
}
int check(double *A, int k) {
	double end;
	int i;
	end = A[1];
	for (i = 0; i < k; i++) {
		if (i % 2 == 0) {
			printf("%lf %lf\n",end,A[i]);
			if ((A[i] > end)&&(end >= 0)&&(A[i] <= 1))
				return -1;
			end = A[i+1];
		}
	}
	return 1;
}