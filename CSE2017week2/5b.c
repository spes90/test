#include <stdio.h>

struct point {
	int x, y;
};
struct point p;

int quadrant(struct point p) {
	if (p.x > 0 && p.y > 0)
		return 1;
	else if (p.x < 0 && p.y > 0)
		return 2;
	else if (p.x < 0 && p.y < 0)
		return 3;
	else
		return 4;
}

void main() {
	printf("��ǥ�� �Է�: ");
	scanf("%d %d", &p.x, &p.y);
	printf("%d��и�\n",quadrant(p));
}