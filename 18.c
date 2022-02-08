#include <stdio.h>
int f(int, int);
int main(void) {
	long int N,A,Res,n,n2,k = 1;
	printf("Enter A, N\n");
	scanf("%ld%ld", &A,&N);
	Res = 1;
	n = 0;
	n2 = 0;
	while (N > 0) {
		n2 = n2 + k*(N % 2);
		N = N / 2;
		k = k*10;
	}
	while (n2 > 0) {
		if (n2 % 10 == 1) 
			Res = Res*f(n,A);
		n++;
		n2 = n2 / 10;
	}
	printf("%ld\n", Res);
	return 0;
	}
int f(int n,int A) {
	int i;
	for (i = 1;i<=n;i++)
		A = A*A;
	return A;
	}