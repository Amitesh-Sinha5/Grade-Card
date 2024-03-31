#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[50];
    char section[10];
    int rollNumber;
    int numSubjects;
    int numExamsPerSubject;
    float grades[50][10];
    char grade;
    float averageGrade;
    float percentage; // New member for percentage
};

void getStudentInfo(struct Student *student);
void calculateGrade(struct Student *student);
void printGradeCard(struct Student *student);

#endif

