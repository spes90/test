#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s[7];
void search(int a) {

	int complete = 0;

	for (int i = 0; i < 7; i++) {
		if (s[i] == a) {
			printf("숫자 %d는 %d번째에 있습니다.\n", a, (i + 1));
			complete = 1;
			break;
		}
	}
	if (complete == 0)
		printf("숫자 %d는 없습니다.\n", a);
}

void main() {
	srand((unsigned int)time(NULL));
	int a;

	printf("7개의 난수는 다음과 같다.\n");
	for (int i = 0; i<7; i++) {
		int n = rand() % 100 + 1;
		s[i] = n;
		
		printf("%d ", s[i]);
	}
	printf("\n검색할 숫자를 입력하시오: ");
	scanf("%d", &a);
	search(a);
}
