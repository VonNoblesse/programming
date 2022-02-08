#include <stdio.h>
int main(void) {
	int n = 0,phase = 0;
	double prev,curr;
	FILE*IN;
	IN = fopen("tmp.dat","r");
	if (IN == NULL) {
		printf("file is not open");
		return -1;
	}
	if (fscanf(IN,"%lf",&prev) == 0) {
		printf("there is no numbers");
		return -1;
	}
	++n;
	if (fscanf(IN,"%lf",&curr) == 1) {
		if (curr > prev)
			n -= 1;
		if (prev <= curr)
			phase = 1;
		prev = curr;
		while (fscanf(IN,"%lf",&curr) == 1) {
			if ((curr <= prev)&&(phase == 1)) {
				++n;
				phase = 0;
			}
			if ((curr >= prev)&&(phase == 0))
				phase = 1;
			prev = curr;
		}
		if (phase == 1)
			++n;
	}
	printf("%d",n);
	return 0;
}