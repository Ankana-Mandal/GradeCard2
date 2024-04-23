# GradeCard2

main.c: Contains the main function and user interface for the program.

grade_card.c: Implementation of functions to display student details by Roll No or Name.

grade_card.h: Header file defining the structure of a Student and function prototypes.

average.c: Implementation of a function to calculate the average of marks.

average.h: Header file with the prototype for the average calculation function.

Makefile: Makefile for compiling the project.

Compile the project: gcc -c grade_card.c -o grade_card.o gcc -c average.c -o average.o gcc -c main.c -o main.o gcc -o program main.o grade_card.o average.o

Run the program:./program -Search for students by Roll No or Name.

Display student details including name, Roll No, Date of Birth (DOB), marks for two semesters, and average marks for each semester.
