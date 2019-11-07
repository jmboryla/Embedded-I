#include <stdio.h>
#include <stdlib.h>

typedef struct studentTag{
    int id;
    char name[25];
    double gpa;
}student;

void modifyGPA(student *s, double newGPA)
{
    s->gpa=newGPA;
}

void printStudentRecord(student s)
{
    printf("id: %d, name: %s, gpa: %.2f \n", s.id, s.name,s.gpa);
}

int main (void)
{
    struct studentTag Jon= {12,"Jon", 4.0};

    printStudentRecord(Jon);
    modifyGPA(&Jon,5.0);

   return 0;
}
