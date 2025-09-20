#include<stdio.h>
#include<ctype.h>

void Greeting(void);                            //greets user

char InitializeMenu(void);                          //displays menu, scans menu option

double AddPoints(double points, int studentID); //calculates total points

void CalculateAverage(double points, int count, int studentID); //calculate and display average

int main(void){
    char menu;                      //menu selection char
    int count = 0;                  //total ammount of points counted
    double points = 0;              //total assessment points
    int studentID = 0;              //stores student's ID
    int menu_op = 0;                //var used to keep menu running until 'Q'
    Greeting();
    printf("\nPlease enter the ID (must be an integer) for the current student:");
    scanf("%d", &studentID);
    while(menu_op != 1){            //stays in menu until q is selected
        menu = InitializeMenu();
        if( menu == 'A' || menu == 'a'){
            points = AddPoints(points, studentID);
            count++;
            printf("\nTOTAL COUNT: %d \n",count);
        }
        else if(menu == 'C' || menu == 'c'){
            CalculateAverage(points, count, studentID);
        }
        else if(menu == 'N' || menu == 'n'){
            count = 0;
            points = 0;
            studentID = 0;
            printf("\nPlease enter new studentID\n");
            scanf("%d", &studentID);
        }
        else if(menu == 'Q' || menu == 'q'){
            menu_op = 1;
        }
    }
}

//Greets the user and shows menu options
void Greeting(void){
    printf("Welcome to the grade calculator.\n");
    printf("\n-- All assessments must have a minimum of 0 and a maximum of 100 point value");
    printf("\n-- All assessments have the same weight\n");
    printf("\nSelect 'A' to enter points");
    printf("\nSelect 'C' to display the current average");
    printf("\nSelect 'N' to start over with a NEW student");
    printf("\nSelect 'Q' on the menu to QUIT the program.");
    printf("\n*********************************************\n");
}

//displays menu, gets the selected option and returns the corresponding char
char InitializeMenu(void){
    printf("\nPlease select from the following:\n");
    printf("A or a...to ADD the points for the current student\n");
    printf("C or c...to calculate and display the average of the current student\n");
    printf("N or n...to reset and start over with a NEW studen\n");
    printf("Q or q...to QUIT:\n");
    char menu_option;
    scanf(" %c",&menu_option);
    return menu_option;
}

//gets points of assessment, adds to current points
double AddPoints(double points, int studentID){
    double read_points = 0;
    printf("\nEnter points for the assessment for student ID(%d)\n",studentID);
    scanf("%lf",&read_points);
    while(read_points > 100 || read_points <0){ //repeat until valid points
        printf("\nEnter points for the assessment for student ID(%d)\n",studentID);
        scanf("%lf",&read_points);
    }
    points = points + read_points;  //adds total points
    return points;
}

//determines if count != 0 and later calculates and displays average of points
void CalculateAverage(double points, int count, int studentID){
    if(count == 0){
        printf("\nYou have not entered any points, select 'A' from the menu.\n");
    }
    else if( count != 0){
        double average_result = 0;
        average_result = points / count;
        printf("\nThe student ID (%d),total points are %.2f and the count of assessments is %.0d",studentID,points,count);
        printf("\nIf you have more points to add, select 'A', you will not need to start over!");
        printf("\nIf you want to start over, select 'N' from the menu.\n");
        printf("\nThe average is: %.2f\n",average_result);
    }
}
