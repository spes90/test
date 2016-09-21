#include <stdio.h>
#include <windows.h>
 
void main() {
	int s[3][3] = { NULL };
	int x, y, input;

	while (1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%d ", s[i][j]);
			}
			printf("\n");
		}
		printf("행 과 열 그리고 새로운 값을 입력하세요. ");
		scanf("%d %d %d", &x, &y, &input);
		s[x - 1][y - 1] = input;
	}
	system("cls");
}