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

     
