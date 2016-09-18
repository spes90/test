#include <stdio.h>
#include <stdlib.h>

double plus(double x, double y);
double minus(double x, double y);
double multi(double x, double y);
double divide(double x, double y);

void main() {
	int i;
	double x, y;
	double(*f[4])(double, double) = { plus, minus, multi, divide };

	printf("사칙연산을 위하여 각 연산에 대한 번호를 입력하세요.>>\n");
	printf("[더하기]:0, [빼기]:1, [곱하기]:2, [나누기]:3>>>");
	scanf("%d", &i);

	printf("사칙연산을 수행할 실수 2개를 입력하세요.>>");
	scanf("%lf %lf", &x, &y);

	f[i](x, y);
}
	
double plus(double x, double y) {
	return printf("더하기 수행: %lf\n", x+y);
}
double minus(double x, double y) {
	return printf("빼기 수행: %lf\n", x - y);
}
double multi(double x, double y) {
	return printf("곱하기 수행: %lf\n", x * y);
}
double divide(double x, double y) {
	return printf("나누기 수행: %lf\n", x / y);
}

