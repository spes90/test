#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s[7];
void search(int a) {

	int complete = 0;

	for (int i = 0; i < 7; i++) {
		if (s[i] == a) {
			printf("���� %d�� %d��°�� �ֽ��ϴ�.\n", a, (i + 1));
			complete = 1;
			break;
		}
	}
	if (complete == 0)
		printf("���� %d�� �����ϴ�.\n", a);
}

void main() {
	srand((unsigned int)time(NULL));
	int a;

	printf("7���� ������ ������ ����.\n");
	for (int i = 0; i<7; i++) {
		int n = rand() % 100 + 1;
		s[i] = n;
		
		printf("%d ", s[i]);
	}
	printf("\n�˻��� ���ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &a);
	search(a);
}
