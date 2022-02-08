#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int solve(double a, double b, double c,double *roots);
double max(double a, double b);
double f(double a, double b, double c, double d, double x);
int main(void) {
	double a,b,c,d,left,right,m = 0,x1,x2;
	double *roots;
	int count = 0;
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&left,&right);
	if ((a == 0)||(right < left)) {
		printf("incorrect data");
		return -1;
	}
	roots = (double*)malloc(2*sizeof(double));
	count = solve(a*3,b*2,c,roots);
	x1 = roots[0];
	x2 = roots[1];
	if (count == 2) {
		if (left >= x2) {
			m = max(f(a,b,c,d,left),f(a,b,c,d,right));
			printf("1\n");
		}
		if ((left >= x1)&&(left <= x2)&&(right >= x2)) {
			m = max(f(a,b,c,d,left),max(f(a,b,c,d,right),f(a,b,c,d,x2)));
			printf("2\n");
		}
		if ((left <= x1)&&(right >= x2)) {
			m = max(f(a,b,c,d,left),max(f(a,b,c,d,right),max(f(a,b,c,d,x2),f(a,b,c,d,x1))));
			printf("3\n");
		}
		if ((left >= x1)&&(right <= x2)) {
			m = max(f(a,b,c,d,left),f(a,b,c,d,right));
			printf("4\n");
		}
		if ((left <= x1)&&(right <= x2)&&(right >= x1)) {
			m = max(f(a,b,c,d,left),max(f(a,b,c,d,x1),f(a,b,c,d,right)));
		printf("5\n");
		}
		if (right <= x1) {
			m = max(f(a,b,c,d,left),f(a,b,c,d,right));
			printf("6\n");
		}
	}
	else {
		m = max(f(a,b,c,d,left),f(a,b,c,d,right));
		printf("7\n");
	}
	printf("%lf", m);
	return 0;
}
double max(double a, double b) {
	if (a>b)
		return a;
	else
		return b;
}
double min(double a, double b) {
	if (a>b)
		return b;
	else
		return a;
}
double f(double a, double b, double c, double d, double x) {
	return a*x*x*x+b*x*x+c*x+d;
}
int solve(double a, double b, double c,double *roots) {
	double D = b*b-4*a*c;
	if (D > 0) {
		roots[0] = min((-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a));
		roots[1] = max((-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a));
		return 2;
	}
	if (D == 0)
		return 1;
	return 0;
}