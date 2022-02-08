#include <stdio.h>
int main(void) {
	double x,p,d = 0,c;
	FILE *IN;
	IN = fopen("tmp.dat", "r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	if (fscanf(IN, "%lf", &c) != 1) {
		printf("where is no coefficients");
		fclose(IN);
		return -1;
	}
	printf("Enter x\n");
	scanf("%lf", &x);
	p = c;
	while (fscanf(IN, "%lf", &c) == 1) {
		d = d*x + p;
		p = p*x + c;
	}
	fclose(IN);
	printf("polynom: %lf\n",p);
	printf("derivative: %lf", d);
	return 0;
}
	