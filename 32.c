#include <stdio.h>
int main(void) {
	FILE *IN;
	double A[100][100];
	int i,j,M,N,phase = 0,count = 0;
	IN = fopen("tmp.dat","r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	scanf("%d%d",&M,&N);
	for (i = 0;i < M;i++) {
		for (j = 0;j < N;j++) {
			if(fscanf(IN,"%lf",&A[i][j]) != 1) {
				printf("not enough numbers");
				return -1;
			}
		}
	}
	fclose(IN);
	for (i = 0;i < M;i++) {
		for (j = 0;j < N;j++) {
			phase = 1;
			if (i - 1 >= 0)
				if (A[i-1][j] > A[i][j]) {
					phase = 0;
				}
			if (i + 1 < M)
				if (A[i+1][j] > A[i][j]) {
					phase = 0;
				}
			if (j + 1 < N)
				if (A[i][j+1] > A[i][j]) {
					phase = 0;
				}
			if (j - 1 >= 0)
				if (A[i][j-1] > A[i][j]) {
					phase = 0;
				}
			if (phase == 1) {
				++count;
			}
		}
	}
	printf("%d",count);
	return 0;
}