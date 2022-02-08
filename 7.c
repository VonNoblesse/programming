#include <stdio.h>
int main(void) {
	double x,i;
	int n = 0,nfirst = 0,nlast = 0;
	FILE *IN;
	printf("Enter x\n");
	scanf("%lf",&x);
	IN = fopen("tmp.dat","r");
	if (IN == NULL) {
		printf("File is not open");
		return -1;
	}
	while (fscanf(IN, "%lf", &i) == 1) {
		++n;
		if (x == i) {
			if (nfirst == 0) {
				nfirst = n;
			}
			nlast = n;
		}
		
	}
	fclose(IN);
	printf("Number of the first x - %d \n",nfirst);
	printf("Number of the last x - %d",nlast);
	return 0;
	}