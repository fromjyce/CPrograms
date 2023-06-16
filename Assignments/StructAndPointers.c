//Write a program to access the elements of the structure using pointers

#include <stdio.h>
 
int main () {
    struct student {
        char gender[25];
        int roll;
    };
  struct student s1={"F", 12};
  struct student s2={"M", 24};
   struct student *ps1;
   struct student *ps2;
  ps1=&s1;
  ps2=&s2;
  printf ("\nGender of Roll.No: 12: %c", *ps1->gender);
  printf ("\nRoll no of the Boy: %d", (*ps2).roll);
return 0;
}
