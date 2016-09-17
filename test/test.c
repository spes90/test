#include <stdio.h>
#include <windows.h>

void main() {
	int s[3][3] = { NULL };
	int a, b, c;
	while (1) {
		for (int i = 0; i < 3; i++) {
			printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
		}
		printf("행 과 열 그리고 새로운 값을 입력하세요. ");
		scanf("%d, %d, %d", &a, &b, &c);
		c = s[a][b];

		printf("%d", c);
		system("cls");
	}
}