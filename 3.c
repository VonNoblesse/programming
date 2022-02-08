#include <stdio.h>
int main(void) {
	double min,x;
	int count;
	FILE *IN;
	IN = fopen("tmp.dat", "r");
	if (IN == NULL) {
		printf("file not open");
		return -1;
	}
	if (fscanf(IN, "%lf", &x) == 1) {
		min = x;
		count = 1;
	}
	else {	
		printf("There is no numbers");
		fclose(IN);
		return -1;
	}
	while (fscanf(IN, "%lf", &x) == 1) {
		if (x < min) {
			min = x;
			count = 1;
		}
		else
		if (x == min) {
			++count;
		}
	}
	fclose(IN);
	printf("count of the minimal numbers - %d", count);
	return 0;
}
		