#include <stdio.h>
int main(void) {
	int i;
	float macheps = 1,first = 1,second = 0;
	while (1 + macheps != 1)
		macheps = macheps / 2;
	for (i = 0; i < 1000; i++) {
		first +=  macheps;
		second += macheps;
	}
	second += 1;
	printf("%.50lf\n", first);
	printf("%.50lf", second);
	return 0;
}
	