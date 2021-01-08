#include "stdio.h"

void letter_grade(int grade) {

  int a;

  if(grade >= 90) {
    a = 1;
  } else if(grade >= 80) {
    a = 2;
  } else if(grade >= 70) {
    a = 3;
  } else if(grade >=60){
    a = 4;
  } else {
    a = 5;
  }

  switch(a) {

    case 1:
      printf("Excellent!\n");
      if(grade > 95) {
        printf("Your grade: A+\n");
      } else if(grade == 95) {
        printf("Your grade: A\n");
      } else {
        printf("Your grade: A-\n");
      } break;

    case 2:
    printf("Well done!\n");
    if(grade > 85) {
      printf("Your grade: B+\n");
    } else if(grade == 85) {
      printf("Your grade: B\n");
    } else {
      printf("Your grade: B-\n");
    } break;

    case 3:
    printf("You Passed!\n");
    if(grade > 75) {
      printf("Your grade: C+\n");
    } else if(grade == 75) {
      printf("Your grade: C\n");
    } else {
      printf("Your grade: C-\n");
    } break;

    case 4:
    printf("You failed!\n");
    if(grade > 65) {
      printf("Your grade: D+\n");
    } else if(grade == 65) {
      printf("Your grade: D\n");
    } else {
      printf("Your grade: D-\n");
    } break;

    case 5:
    printf("You failed!\n");
    if(grade < 60) {
      printf("Your grade: F\n");
    } break;
  }
}



int main(int argc, char const *argv[]) {

  // int s_1 = 98;
  // int s_2 = 95;
  // int s_3 = 90;
  // int s_4 = 87;
  // int s_5 = 85;
  // int s_6 = 81;
  // int s_7 = 79;
  // int s_8 = 75;
  // int s_9 = 72;
  // int s_10 = 65;
  // int s_11 = 56;
  int grade;
  printf("Enter your grade: ");
  scanf("%d", &grade);
  letter_grade(grade);

  // letter_grade(s_1);
  // letter_grade(s_2);
  // letter_grade(s_3);
  // letter_grade(s_4);
  // letter_grade(s_5);
  // letter_grade(s_6);
  // letter_grade(s_7);
  // letter_grade(s_8);
  // letter_grade(s_9);
  // letter_grade(s_10);
  // letter_grade(s_11);

  return 0;
}
