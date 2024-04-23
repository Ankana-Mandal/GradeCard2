#include <stdio.h>
#include <stdlib.h>
#include "grade_card.h"

void displayStudentByRollNo(int rollno) {
    struct Student students[] = {
        {"Alice", 1, "01/01/2000", (float[]){80, 85, 70, 90, 88}, (float[]){85, 90, 75, 95, 90}},
        {"Bob", 2, "02/02/2001", (float[]){75, 82, 78, 88, 90}, (float[]){80, 85, 80, 90, 85}},
        {"Charlie", 3, "03/03/2002", (float[]){85, 88, 90, 82, 85}, (float[]){90, 92, 85, 88, 92}},
        {"David", 4, "04/04/2003", (float[]){70, 75, 80, 82, 78}, (float[]){72, 78, 75, 80, 77}},
        {"Eva", 5, "05/05/2004", (float[]){90, 92, 95, 88, 90}, (float[]){92, 94, 88, 90, 92}},
        {"Kevin", 6, "07/12/2002", (float[]){86, 89, 91, 83, 86}, (float[]){91, 93, 86, 89, 93}},
        {"Daniel", 7, "29/04/2003", (float[]){74, 79, 87, 92, 88}, (float[]){77, 71, 78, 83, 79}},
        {"Elsa", 8, "08/12/2004", (float[]){89, 72, 85, 78, 80}, (float[]){82, 74, 98, 80, 92}},
    };

    int found = 0;
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); ++i) {
        if (students[i].rollno == rollno) {
            found = 1;
            printf("Name: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].rollno);
            printf("DOB: %s\n", students[i].dob);
            printf("Semester 1 Marks: \n");
            displayGrades(students[i].marks_sem1, 5);
            printf("\n");
            printf("Semester 2 Marks: \n");
            displayGrades(students[i].marks_sem2, 5);
            printf("\n");

            // Calculate and display average marks for semester 1 and 2
            float avg_sem1 = calculateSemesterAverage(students[i].marks_sem1, 5);
            float avg_sem2 = calculateSemesterAverage(students[i].marks_sem2, 5);
            printf("Average Semester 1 Marks: %.2f - Grade: %c\n", avg_sem1, calculateGrade(avg_sem1));
            printf("Average Semester 2 Marks: %.2f - Grade: %c\n", avg_sem2, calculateGrade(avg_sem2));

            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n", rollno);
    }
}

void displayStudentByName(const char *name) {
    struct Student students[] = {
        {"Alice", 1, "01/01/2000", (float[]){80, 85, 70, 90, 88}, (float[]){85, 90, 75, 95, 90}},
        {"Bob", 2, "02/02/2001", (float[]){75, 82, 78, 88, 90}, (float[]){80, 85, 80, 90, 85}},
        {"Charlie", 3, "03/03/2002", (float[]){85, 88, 90, 82, 85}, (float[]){90, 92, 85, 88, 92}},
        {"David", 4, "04/04/2003", (float[]){70, 75, 80, 82, 78}, (float[]){72, 78, 75, 80, 77}},
        {"Eva", 5, "05/05/2004", (float[]){90, 92, 95, 88, 90}, (float[]){92, 94, 88, 90, 92}},
        {"Kevin", 6, "07/12/2002", (float[]){86, 89, 91, 83, 86}, (float[]){91, 93, 86, 89, 93}},
        {"Daniel", 7, "29/04/2003", (float[]){74, 79, 87, 92, 88}, (float[]){77, 71, 78, 83, 79}},
        {"Elsa", 8, "08/12/2004", (float[]){89, 72, 85, 78, 80}, (float[]){82, 74, 98, 80, 92}},
    };

    int found = 0;
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); ++i) {
        int j;
        for (j = 0; students[i].name[j] != '\0' && name[j] != '\0'; ++j) {
            if (students[i].name[j] != name[j]) {
                break; // Characters don't match, move to the next student
            }
        }
        if (students[i].name[j] == '\0' && name[j] == '\0') {
            // All characters match until the end of the strings
            found = 1;
            printf("Name: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].rollno);
            printf("DOB: %s\n", students[i].dob);
            printf("Semester 1 Marks: \n");
            displayGrades(students[i].marks_sem1, 5);
            printf("\n");
            printf("Semester 2 Marks: \n");
            displayGrades(students[i].marks_sem2, 5);
            printf("\n");

            // Calculate and display average marks for semester 1 and 2
            float avg_sem1 = calculateSemesterAverage(students[i].marks_sem1, 5);
            float avg_sem2 = calculateSemesterAverage(students[i].marks_sem2, 5);
            printf("Average Semester 1 Marks: %.2f - Grade: %c\n", avg_sem1, calculateGrade(avg_sem1));
            printf("Average Semester 2 Marks: %.2f - Grade: %c\n", avg_sem2, calculateGrade(avg_sem2));

            break;
        }
    }

    if (!found) {
        printf("Student with Name %s not found. please enter the name as mentioned in list it is case sensitive\n", name);
    }
}

char calculateGrade(float marks) {
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 80) {
        return 'B';
    } else if (marks >= 70) {
        return 'C';
    } else if (marks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void displayGrades(const float *marks, int size) {
    const char *subjects[] = {"PHY  ", "C    ", "EEE  ", "MECH ", "MATHS"};

    for (int i = 0; i < size; ++i) {
        printf("%s: %.2f (%c)\n", subjects[i], marks[i], calculateGrade(marks[i]));
    }
}







