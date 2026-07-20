#include <stdio.h>
#include "student_registry.h"

int main()
{
    Student students[MAX];

    int count=0;
    int choice;

    loadStudentsFromFile(students,&count);

    do
    {
        printf("\n===== STUDENT REGISTRY =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Student ID\n");
        printf("4. Find by GPA Threshold\n");
        printf("5. Find by Major\n");
        printf("6. Save & Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent(students,&count);
                break;

            case 2:
                displayAllStudents(students,count);
                break;

            case 3:
                searchByID(students,count);
                break;

            case 4:
                findByGPA(students,count);
                break;

            case 5:
                findByMajor(students,count);
                break;

            case 6:
                saveStudentsToFile(students,count);
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    }while(choice!=6);

    return 0;
}
