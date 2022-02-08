#include <stdio.h>
int main(void) {
	FILE *IN;
	int req = 1;
	double prev,cur;
	IN = fopen("tmp.dat", "r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	if (fscanf(IN, "%lf", &prev) != 1) {
		fclose(IN);
		printf("no numbers in sequence");
		return -1;
	}
	while (fscanf(IN, "%lf", &cur) == 1) {
		if (prev != cur) {
			req = 0;
		    break;
		}
		prev = cur;
	}
	fclose(IN);
	printf("equality of elements : %d", req);
	return 0;
	}
	