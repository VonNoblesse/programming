#include <stdio.h>
int main(void) {
	FILE *IN;
	double x1,x2,x3,x4,x5;
	int count = 0;
	IN = fopen("tmp.dat", "r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	fscanf(IN, "%lf%lf%lf%lf", &x1,&x2,&x3,&x4);
	while (fscanf(IN, "%lf", &x5) == 1) {
		if (x1 == 1 && x2 == 2 && x3 == 3 && x4 == 4 && x5 == 5)
			++count;
		x1 = x2;
		x2 = x3;
		x3 = x4;
		x4 = x5;
	}
	fclose(IN);
	printf("%d", count);
	return 0;
}