#include <stdio.h>

struct point {
	int x, y;
};
struct point p1, p2;

int equal(struct point p1, struct point p2) {
	if (p1.x == p2.x && p1.y == p2.y)
		return 1;
	else
		return 0;
}

void main() {
	printf("첫번째 점의 좌표를 입력하세요: ");
	scanf("%d %d", &p1.x, &p1.y);
	printf("두번째 점의 좌표를 입력하세요: ");
	scanf("%d %d", &p2.x, &p2.y);
	printf("%d\n", equal(p1, p2));
}