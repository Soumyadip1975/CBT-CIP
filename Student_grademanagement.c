#include <stdio.h>
#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5

struct Student {
    char name[50];
    float scores[MAX_SUBJECTS];
    float average;
    char grade; 
};

void input_StudentData(struct Student students[], int studentCount, int subjectCount) {
 for (int i = 0; i < studentCount; i++) {
     printf("Enter name of student %d: ", i + 1);
     scanf("%s", students[i].name);
        
        for (int j = 0; j < subjectCount; j++) {
            printf("Enter score for subject %d: ", j + 1);
            scanf("%f", &students[i].scores[j]);
        }
    }
}

void calculate_Averages(struct Student students[], int studentCount, int subjectCount) {
    for (int i = 0; i < studentCount; i++) {
        float total = 0;

        for (int j = 0; j < subjectCount; j++) {
            total += students[i].scores[j];
        }
        students[i].average = total / subjectCount;

        
        if (students[i].average >= 90) {
            students[i].grade = 'O';
            }
         else if (students[i].average >= 80) {
            students[i].grade = 'A';
            } 
        else if (students[i].average >= 70) {
            students[i].grade = 'B';
            } 
        else if (students[i].average >= 60) {
            students[i].grade = 'C';
            }
         else {
            students[i].grade = 'F';
            }
    }
}

void display_Performance(struct Student students[], int studentCount) {
    printf("\nStudent Performance Summary:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s, Average Score: %.2f, Grade: %c\n", students[i].name, students[i].average, students[i].grade);
    }
}

int main() {
    int studentCount, subjectCount;
    
    
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);
    printf("Enter the number of subjects: ");
    scanf("%d", &subjectCount);
    
    struct Student students[MAX_STUDENTS];

    input_StudentData(students, studentCount, subjectCount);
    
    calculate_Averages(students, studentCount, subjectCount);
    
    display_Performance(students, studentCount);
    
    return 0;
}

