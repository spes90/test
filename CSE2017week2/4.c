#include <stdio.h>

struct grade {
	int mid, final;
};

void main() {
	struct grade s1;
	struct grade *p = &s1;
	int tot;

	printf("희망하는 중간 점수를 입력하시오: ");
	scanf("%d", &s1.mid);
	printf("희망하는 기말 점수를 입력하시오: ");
	scanf("%d", &s1.final);

	tot = (*p).mid + (*p).final;

	printf("두 점수의 합: %d\n", tot);
}