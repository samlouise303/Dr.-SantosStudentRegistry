#include <stdio.h>
#include <string.h>
#include "student_registry.h"

void addStudent(Student students[], int *count)
{
    if (*count >= MAX)
    {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Major: ");
    scanf(" %[^\n]", students[*count].major);

    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);

    printf("Enter Credits: ");
    scanf("%d", &students[*count].credits);

    (*count)++;

    printf("\nStudent added successfully!\n");
}

void displayAllStudents(Student students[], int count)
{
    int i;

    if(count==0)
    {
        printf("\nNo students available.\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

    for(i=0;i<count;i++)
    {
        printf("\nStudent %d\n",i+1);
        printf("ID: %d\n",students[i].id);
        printf("Name: %s\n",students[i].name);
        printf("Major: %s\n",students[i].major);
        printf("GPA: %.2f\n",students[i].gpa);
        printf("Credits: %d\n",students[i].credits);
    }
}

void searchByID(Student students[], int count)
{
    int id;
    int i;
    int found=0;

    printf("Enter Student ID: ");
    scanf("%d",&id);

    for(i=0;i<count;i++)
    {
        if(students[i].id==id)
        {
            printf("\nStudent Found\n");
            printf("ID: %d\n",students[i].id);
            printf("Name: %s\n",students[i].name);
            printf("Major: %s\n",students[i].major);
            printf("GPA: %.2f\n",students[i].gpa);
            printf("Credits: %d\n",students[i].credits);

            found=1;
            break;
        }
    }

    if(!found)
        printf("Student not found.\n");
}

void findByGPA(Student students[], int count)
{
    float gpa;
    int i;
    int found=0;
	
    printf("Enter minimum GPA: ");
    scanf("%f",&gpa);

    printf("\nStudents with GPA >= %.2f\n",gpa);

    for(i=0;i<count;i++)
    
    {
        if(students[i].gpa>=gpa)
        {
        	
            printf("%d | %s | %.2f\n",
                   students[i].id,
                   students[i].name,
                   students[i].gpa);

            found=1;
        }
    }

    if(!found)
        printf("No students found.\n");
}

void findByMajor(Student students[], int count)
{
    char major[50];
    int i;
    int found=0;

    printf("Enter Major: ");
    scanf(" %[^\n]",major);

    printf("\nStudents in %s\n",major);

    for(i=0;i<count;i++)
    {
        if(strcmp(students[i].major,major)==0)
        {
            printf("%d | %s\n",
                   students[i].id,
                   students[i].name);

            found++;
        }
    }

    printf("Total students: %d\n",found);
}

void saveStudentsToFile(Student students[], int count)
{
    FILE *fp=fopen(FILENAME,"w");

    int i;

    if(fp==NULL)
    {
        printf("Error saving file.\n");
        return;
    }

    for(i=0;i<count;i++)
    {
        fprintf(fp,"%d|%s|%s|%.2f|%d\n",
                students[i].id,
                students[i].name,
                students[i].major,
                students[i].gpa,
                students[i].credits);
    }

    fclose(fp);

    printf("\nStudents saved successfully!\n");
}

void loadStudentsFromFile(Student students[], int *count)
{
    FILE *fp=fopen(FILENAME,"r");

    if(fp==NULL)
    {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }

    while(fscanf(fp,"%d|%99[^|]|%49[^|]|%f|%d\n",
                 &students[*count].id,
                 students[*count].name,
                 students[*count].major,
                 &students[*count].gpa,
                 &students[*count].credits)==5)
    {
        (*count)++;
    }

    fclose(fp);

    printf("Loaded %d students.\n",*count);
}
