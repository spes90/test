#include <stdio.h>

int main(void) {
	int a[4] = { 10,20,30,40 };
	int *pa = a;

	printf("%d %d %d %d\n", *pa, *(pa+1),*(pa+2),*(pa+3));
	printf("%d %d %d %d\n", pa[0], pa[1], pa[2], pa[3]);
	printf("%d ", ++*pa);
	printf("%d ", *(++pa));
	printf("%d ", *pa++);
	printf("%d ", --*(pa++));
	printf("%d\n", (*pa)--);
	
	printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
	
	return 0;
}