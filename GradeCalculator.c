
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the student struct
typedef struct {
    char firstName[50];
    char lastName[50];
    int ID;
    int gradeCount;
    double pointsTotal;
    double average;
} student;

// Function prototypes
void Greeting(void);
void FiveStudents(student list[]);
int  AddOneStudent(student list[], int studentCount);
void PrintOneStudent(student oneStudent);
void PrintStudentList(student list[], int studentCount);
int  SelectAndReturnIndex(student list[], int studentCount);
char DisplayMenu();
void AddPoints(student list[], int index);
void CalculateAverage(student list[], int index);

int main() {
    student studentList[MAX_STUDENTS];
    int studentCount = 5; 
    FiveStudents(studentList);
    Greeting();
    char menuOption;
    do {
        menuOption = DisplayMenu();
        menuOption = toupper(menuOption);
    
        switch (menuOption) {
        case 'P':
            PrintStudentList(studentList, studentCount);
            break;
        case 'O':{
            int index = SelectAndReturnIndex(studentList, studentCount);
            PrintOneStudent(studentList[index]);
        }
        break;
        case 'S':{
            int index = SelectAndReturnIndex(studentList, studentCount);
            AddPoints(studentList, index);
        }
        break;
        case 'A':{
            int index = SelectAndReturnIndex(studentList, studentCount);
            CalculateAverage(studentList, index);
        }
        break;
        case 'N':
            studentCount = AddOneStudent(studentList, studentCount);
            break;
        case 'Q':
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (menuOption != 'Q');

    return 0;
}

void Greeting(void) {
    printf("***************************************************************\n");
    printf("Welcome to the grade calculator.\n");
    printf("-- All assessments must have a minimum of 0 and a maximum of 100 point value\n");
    printf("-- All assessments have the same weight\n");
    printf("***************************************************************\n");
}

void FiveStudents(student list[]) {
    char firstNames [] [50] = {"Jim", "Austin", "Carl", "Lucas", "Nick"};
    char lastNames [] [50] = {"Adams", "Perez", "Stark", "Robinson", "Johns"};
    for (int i = 0; i < 5; i++) {
        strcpy(list[i].firstName, firstNames[i]);
        strcpy(list[i].lastName, lastNames[i]);
        list[i].ID = i + 1;  
        list[i].gradeCount = 0;
        list[i].pointsTotal = 0.0;
        list[i].average = 0.0;
    }
}

int AddOneStudent(student list[], int studentCount) {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter new student information:\n");
        printf("First Name: ");
        scanf("%s", list[studentCount - 1].firstName);
        printf("Last Name: ");
        scanf("%s", list[studentCount - 1].lastName);
        printf("ID: ");
        scanf("%d", &list[studentCount - 1].ID);
        list[studentCount - 1].gradeCount = 0;
        list[studentCount - 1].pointsTotal = 0.0;
        list[studentCount - 1].average = 0.0;
        printf("Student add success!\n");
        studentCount++;
    } 
    else {
        printf("Cannot add more students. Maximum limit reached.\n");
    }
    return studentCount;
}

void PrintOneStudent(student oneStudent) {
    printf("\nStudent Information:\n");
    printf("First Name: %s\n", oneStudent.firstName);
    printf("Last Name: %s\n", oneStudent.lastName);
    printf("ID: %d\n", oneStudent.ID);
    printf("Grade Count: %d\n", oneStudent.gradeCount);
    printf("Points Total: %.2f\n", oneStudent.pointsTotal);
    printf("Average: %.2f\n", oneStudent.average);
}

void PrintStudentList(student list[], int studentCount) {
    printf("\nList of Students:\n");

    // Loop through the students and print their information
    for (int i = 0; i < studentCount; i++) {
        printf("Student %d:\n", i + 1);
        PrintOneStudent(list[i]);
        printf("\n");
    }
}

int SelectAndReturnIndex(student list[], int studentCount) {
    printf("\nSelect a student:\n");
    PrintStudentList(list, studentCount);
    int selectedIndex;
    do {
        printf("Enter the index of the student (1 to %d): ", studentCount);
        scanf("%d", &selectedIndex);
        if (selectedIndex < 1 || selectedIndex > studentCount) {
            printf("Invalid index. Please enter a valid index.\n");
        }
    } 
    while (selectedIndex < 1 || selectedIndex > studentCount);
    return selectedIndex - 1;
}


char DisplayMenu() {
    char menuOption;
    printf("\nPlease select the following:\n");
    printf("... P ... to Print the list of students and information onto the screen\n");
    printf("... O ... to Print the information about one student onto the screen\n");
    printf("... S ... to select the current student in the list for grade calculation\n");
    printf("... A ... to ADD the points for the current student\n");
    printf("... C ... to calculate and display the average of the current student\n");
    printf("... N ... to add a NEW student to the list\n");
    printf("... Q ... to QUIT:\n");
    printf("Enter your choice: ");
    scanf(" %c", &menuOption);  
    return menuOption;
}

void AddPoints(student list[], int index) {
    double pointsToAdd;
    printf("Enter the points to add for %s %s (Student ID: %d): ", list[index].firstName, list[index].lastName, list[index].ID);
    scanf("%lf", &pointsToAdd);
    list[index].pointsTotal += pointsToAdd;
    list[index].gradeCount++;
    printf("Points added successfully!\n");
}

void CalculateAverage(student list[], int index) {
    if (list[index].gradeCount > 0) {
        list[index].average = list[index].pointsTotal / list[index].gradeCount;
        printf("Average for %s %s (Student ID: %d): %.2f\n", list[index].firstName, list[index].lastName, list[index].ID, list[index].average);
    } 
    else {
        printf("Cannot calculate average. No grades entered for %s %s (Student ID: %d).\n", list[index].firstName, list[index].lastName, list[index].ID);
    }
}
