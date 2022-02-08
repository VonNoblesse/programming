#include <stdio.h>
#include <stdlib.h>
int bin_search(double *A, int N, double x);
int main(void) {
	FILE *IN;
	int i,N = 0;
	double *A;
	double a,x;
	IN = fopen("tmp.dat","r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	if (fscanf(IN, "%lf", &a) != 1) {
		printf("empty file");
		return -1;
	}
	++N;
	while (fscanf(IN, "%lf", &a) == 1) {
		++N;
	}
	A = (double*)malloc(N*sizeof(double));
	fclose(IN);
	IN = fopen("tmp.dat","r");
	for (i = 0; i <N; i++) {
		fscanf(IN, "%lf", &A[i]);
	}
	fclose(IN);
	if (scanf("%lf", &x) == 1) {
	}
	printf("%d %lf\n",N,x);
	if (bin_search(A,N,x) == 1)			
		printf("Yes");
	else 
		printf("No");
	return 0;
}
int bin_search(double *A, int N, double x) {
	int first,last,mid,req;
	req = 0;
	first = 0;
	last = N-1;
	mid = (first+last)/2;
	printf("%lf %d %d\n",x,first,last);
	while (first < last) {
		if (A[mid] < x) {
			first = mid+1;
			mid = (first+last)/2;
			printf("%lf %d %d\n",x,first,last);
		}
		if (A[mid] == x) {
			req = 1;
			printf("%lf %d %d\n",x,first,last);
			break;
		}
		if (A[mid] > x) {
			last = mid;
			mid = (first+last)/2;
			printf("%lf %d %d\n",x,first,last);
		}
	}
	if (req == 1) 
		return 1;
	else
		return 0;
}