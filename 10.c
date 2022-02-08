#include <stdio.h>
int main(void) {
	FILE *IN;
	int count = 0;
	double prev,cur;
	IN = fopen("tmp.dat", "r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	if (fscanf(IN, "%lf", &prev) == 1) 
		++count;
	while (fscanf(IN, "%lf", &cur) == 1) {
		if (prev != cur)
			++count;
		prev = cur;
	}
	fclose(IN);
	printf("count of the different numbers : %d",count);
	return 0;
	}