#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    struct Student student;
    getStudentInfo(&student);
    calculateGrade(&student);
    printGradeCard(&student);
    return 0;
}
