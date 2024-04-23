#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "grade_card.h"

int main() {
    int choice;
    int rollno;
    char name[50];

    printf("roll no. 1 = Alice \n");
    printf("roll no. 2 = Bob \n");
    printf("roll no. 3 = Charlie\n");
    printf("roll no. 4 = David\n");
    printf("roll no. 5 = Eva\n");
    printf("roll no. 6 = Kevin\n");
    printf("roll no. 7 = Daneil\n");
    printf("roll no. 8 = Elsa\n\n");
    
    printf("1. Search by Roll No\n");
    printf("2. Search by Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Roll No: ");
        scanf("%d", &rollno);
        displayStudentByRollNo(rollno);
    } else if (choice == 2) {
        printf("Enter Name: ");
        scanf("%s", name);
        displayStudentByName(name);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}

