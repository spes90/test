#include <stdio.h>

struct grade {
	int mid, final;
};

void main() {
	struct grade s1;
	struct grade *p = &s1;
	int tot;

	printf("����ϴ� �߰� ������ �Է��Ͻÿ�: ");
	scanf("%d", &s1.mid);
	printf("����ϴ� �⸻ ������ �Է��Ͻÿ�: ");
	scanf("%d", &s1.final);

	tot = (*p).mid + (*p).final;

	printf("�� ������ ��: %d\n", tot);
}