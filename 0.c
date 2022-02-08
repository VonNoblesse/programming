#include <stdio.h>
#include <math.h>
int main(void) {
	double a,b,c,x1,x2,D;
	printf("Input a,b,c\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	D = (b*b)-(4*a*c);
	if (D<0) {
		printf("No");
		}
	if (D==0) {
		x1 = -b/(2*a);
		printf("%lf",x1);
		}
	if (D>0) {
		x1 = (-b+sqrt(D))/(2*a);
		x2 = (-b-sqrt(D))/(2*a);
		printf("%lf\n",x1);
		printf("%lf",x2);
		}
	return 0;
	}