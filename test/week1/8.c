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

	printf("��Ģ������ ���Ͽ� �� ���꿡 ���� ��ȣ�� �Է��ϼ���.>>\n");
	printf("[���ϱ�]:0, [����]:1, [���ϱ�]:2, [������]:3>>>");
	scanf("%d", &i);

	printf("��Ģ������ ������ �Ǽ� 2���� �Է��ϼ���.>>");
	scanf("%lf %lf", &x, &y);

	f[i](x, y);
}
	
double plus(double x, double y) {
	return printf("���ϱ� ����: %lf\n", x+y);
}
double minus(double x, double y) {
	return printf("���� ����: %lf\n", x - y);
}
double multi(double x, double y) {
	return printf("���ϱ� ����: %lf\n", x * y);
}
double divide(double x, double y) {
	return printf("������ ����: %lf\n", x / y);
}

