#include <stdio.h>

typedef struct {
  char name[7];
  int score;
} Person;

void printScoreStars(Person *persons, int len);

int main() {
  Person persons[3];
  for (int i = 0; i < 3; i++) {
    scanf("%s %d", persons[i].name, &persons[i].score);
  }
  printScoreStars(persons, 3);
  return 0;
}

void printScoreStars(Person *persons, int len) {
  for (int i = 0; i < len; i++) {
    printf("%-7s", persons[i].name);
    for (int j = 0; j < persons[i].score / 5; j++) {
      printf("*");
    }
    printf("\n");
  }
}