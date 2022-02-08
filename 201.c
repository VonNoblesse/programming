#include <stdio.h>
int main(void) {
	double macheps = 1;
	while (1 + macheps != 1)
		macheps = macheps / 2;
	printf("%.50lf",macheps);
	return 0;
}
	