#include <stdio.h>

typedef struct {
	char name[10];
	int age;
} User;

int main() {
	User user;
	
	scanf("%s %d", user.name, &user.age);

	printf("name: %s\n", user.name);
	printf("age: %d\n", user.age);

	return 0;
}
