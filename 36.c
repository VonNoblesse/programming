#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double fmin(double a, double b);
double fmax(double a, double b);
int main(void) {
	double S = 0,P = 0,maxX,maxY,minX,minY,x1,y1,x2,y2,x3,y3,x4,y4;
	printf("enter first coords\n");
	scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
	printf("enter second coords\n");
	scanf("%lf%lf%lf%lf", &x3,&y3,&x4,&y4);
	maxX = fmax(abs(x1),abs(x3));
	minX = fmin(abs(x2),abs(x4));
	maxY = fmax(abs(y1),abs(y3));
	minY = fmin(abs(y2),abs(y4));
	S = abs(x2-x1)*abs(y2-y1)+abs(x4-x3)*abs(y4-y3);
	P = 2*abs(x2-x1)+2*abs(y2-y1)+2*abs(x4-x3)+2*abs(y4-y3);
	if ((maxX <= minX)&&(maxY <= minY)) {
		S = S-abs(minX-maxX)*abs(minY-maxY);
		P = P-2*abs(minX-maxX)-2*abs(minY-maxY);
	}
	printf("S = %lf; P = %lf", S,P);
	return 0;
}
double fmin(double a, double b) {
	if (a > b)
		return b;
	else
		return a;
}
double fmax(double a, double b) {
	if (a > b)
		return a;
	else
		return b;
}