#include <stdio.h>
#include <string.h>

void main() {
	char ch[100];

	printf("문자열을 입력하시오: ");
	gets(ch);

	for (int i = 0; ch[i] != NULL; i++) {
		if (isalpha(ch[i]))
			printf("%c", ch[i]);
	}
	printf("\n");
}