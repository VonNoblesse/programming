#include <stdio.h>
int main(void) {
	double s = 0,p = 1,x;
	FILE *IN;
	IN = fopen("tmp.dat", "r");
	if (IN == NULL) {
		printf("file not open");
		return -1;
	}
	if (fscanf(IN , "%lf", &x) == 1) {
		s += x;
		p *= x;
	}
	else {
		printf("There is no numbers");
		return -1;
	}
	while (fscanf(IN , "%lf", &x) == 1) {
		s += x;
		p *= x;
	}
	fclose(IN);
	printf("Sum - %lf\n",s);
	printf("Product - %lf",p);
	return 0;
}	

