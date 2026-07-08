#include <stdio.h>
#include <string.h>

#define MAX 10

struct Student {
    int id;
    char name[30];
    char major[30];
    float gpa;
    int credits;
};

int main() {
    struct Student student[MAX];
    int count = 0;
    int choice, i, id;
    float gpa;
    char major[30];
    int found;

    do {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by ID\n");
        printf("4. Search by GPA\n");
        printf("5. Search by Major\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            if (count < MAX) {
                printf("Enter ID: ");
                scanf("%d", &student[count].id);

                printf("Enter Name: ");
                scanf(" %[^\n]", student[count].name);

                printf("Enter Major: ");
                scanf(" %[^\n]", student[count].major);

                printf("Enter GPA: ");
                scanf("%f", &student[count].gpa);

                printf("Enter Credits: ");
                scanf("%d", &student[count].credits);

                count++;
                printf("Student added successfully!\n");
            } else {
                printf("Student list is full!\n");
            }
            break;

        case 2:
            if (count == 0) {
                printf("No students found.\n");
            } else {
                for (i = 0; i < count; i++) {
                    printf("\nStudent %d\n", i + 1);
                    printf("ID: %d\n", student[i].id);
                    printf("Name: %s\n", student[i].name);
                    printf("Major: %s\n", student[i].major);
                    printf("GPA: %.2f\n", student[i].gpa);
                    printf("Credits: %d\n", student[i].credits);
                }
            }
            break;

        case 3:
            printf("Enter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++) {
                if (student[i].id == id) {
                    printf("\nStudent Found\n");
                    printf("Name: %s\n", student[i].name);
                    printf("Major: %s\n", student[i].major);
                    printf("GPA: %.2f\n", student[i].gpa);
                    printf("Credits: %d\n", student[i].credits);
                    found = 1;
                }
            }

            if (found == 0)
                printf("Student not found.\n");
            break;

        case 4:
            printf("Enter minimum GPA: ");
            scanf("%f", &gpa);

            found = 0;

            for (i = 0; i < count; i++) {
                if (student[i].gpa >= gpa) {
                    printf("%d - %s - %.2f\n",
                           student[i].id,
                           student[i].name,
                           student[i].gpa);
                    found = 1;
                }
            }

            if (found == 0)
                printf("No students found.\n");
            break;

        case 5:
            printf("Enter Major: ");
            scanf(" %[^\n]", major);

            found = 0;

            for (i = 0; i < count; i++) {
                if (strcmp(student[i].major, major) == 0) {
                    printf("%d - %s\n",
                           student[i].id,
                           student[i].name);
                    found++;
                }
            }

            printf("Total students: %d\n", found);
            break;

        case 6:
            printf("Thank you!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
