#include <stdio.h>
#include "student.h"

void getStudentInfo(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    
    printf("Enter section: ");
    scanf("%s", student->section);
    
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    
    printf("Enter number of subjects: ");
    scanf("%d", &student->numSubjects);
    
    printf("Enter number of exams per subject: ");
    scanf("%d", &student->numExamsPerSubject);
    
    printf("Enter marks for each exam (0 to 100):\n");
    for (int i = 0; i < student->numSubjects; i++) {
        printf("Subject %d:\n", i + 1);
        for (int j = 0; j < student->numExamsPerSubject; j++) {
            float marks;
            do {
                printf("Exam %d: ", j + 1);
                scanf("%f", &marks);
                if (marks < 0 || marks > 100) {
                    printf("Error: Marks must be between 0 and 100.\n");
                }
            } while (marks < 0 || marks > 100);
            student->grades[i][j] = marks;
        }
    }
}

void calculateGrade(struct Student *student) {
    float totalMarks = 0;
    int totalExams = student->numSubjects * student->numExamsPerSubject;
    for (int i = 0; i < student->numSubjects; i++) {
        for (int j = 0; j < student->numExamsPerSubject; j++) {
            totalMarks += student->grades[i][j];
        }
    }
    student->averageGrade = totalMarks / totalExams;
    student->percentage = (totalMarks / (totalExams * 100.0)) * 100.0;

    for (int i = 0; i < student->numSubjects; i++) {
        for (int j = 0; j < student->numExamsPerSubject; j++) {
            if (student->grades[i][j] >= 90) {
                student->grades[i][j] = 'A';
            } else if (student->grades[i][j] >= 80) {
                student->grades[i][j] = 'B';
            } else if (student->grades[i][j] >= 70) {
                student->grades[i][j] = 'C';
            } else if (student->grades[i][j] >= 60) {
                student->grades[i][j] = 'D';
            } else {
                student->grades[i][j] = 'F';
            }
        }
    }}

void printGradeCard(struct Student *student) {
    printf("\nGrade Card\n");
    printf("Name: %s\n", student->name);
    printf("Section: %s\n", student->section);
    printf("Roll Number: %d\n", student->rollNumber);
    
    printf("\nSubject-wise grades:\n");
    for (int i = 0; i < student->numSubjects; i++) {
        printf("Subject %d:\n", i + 1);
        for (int j = 0; j < student->numExamsPerSubject; j++) {
            printf("Exam %d: %c\n", j + 1, student->grades[i][j]);
        }
    }
    
    printf("\nAverage Percentage: %.2f%%\n", student->percentage);
    
    printf("Overall Grade: ");
    if (student->averageGrade >= 90) {
        printf("A\n");
    } else if (student->averageGrade >= 80) {
        printf("B\n");
    } else if (student->averageGrade >= 70) {
        printf("C\n");
    } else if (student->averageGrade >= 60) {
        printf("D\n");
    } else {
        printf("F\n");
    }
}



