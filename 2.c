#include <stdio.h>
int main(void) {
	double x,max;
	int nmin,nmax,n = 0;
	FILE *IN;
	IN = fopen("tmp.dat", "r");
	if (IN == NULL) {
		printf("file not open");
		return -1;
	}
	if (fscanf(IN, "%lf", &x) == 1) {
		max = x;
		++n;
		nmax = n;
		nmin = n;
	} 
	else {
		printf("there is no numbers");
		return -1;
	}
	while (fscanf(IN, "%lf", &x) == 1) {
		++n;
		if (x > max) {
			max = x;
			nmax = n;
			nmin = n;
		}
		if (x == max) {
			nmax = n;
		}
	}
	fclose(IN);
	printf("first max - %d\n", nmin);
	printf("last max - %d", nmax);
	return 0;
}