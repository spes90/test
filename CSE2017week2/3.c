#include <stdio.h>

struct id {
	int age, month, day;
	char name[10];
	char sex[10];
};
struct id s1 = {27, 11, 17, "�����", "��"};

void main() {
	printf("����: %d\n", s1.age);
	printf("�̸�: %s\n", s1.name);
	printf("����: %s\n", s1.sex);
	printf("����: %d��%d��\n", s1.month, s1.day);
}