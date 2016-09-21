#include <stdio.h>
#include <stdlib.h>

void main() {
	int num = 3;
	a = (int*)malloc(sizeof(num));

	printf("%d\n", a.num);
	free(a);
}