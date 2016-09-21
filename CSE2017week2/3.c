#include <stdio.h>

struct id {
	int age, month, day;
	char name[10];
	char sex[10];
};
struct id s1 = {27, 11, 17, "김기현", "남"};

void main() {
	printf("나이: %d\n", s1.age);
	printf("이름: %s\n", s1.name);
	printf("성별: %s\n", s1.sex);
	printf("생일: %d월%d일\n", s1.month, s1.day);
}