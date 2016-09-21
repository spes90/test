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
	printf("좌표를 입력: ");
	scanf("%d %d", &p.x, &p.y);
	printf("%d사분면\n",quadrant(p));
}