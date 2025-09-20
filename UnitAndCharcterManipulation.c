/* 
*
*   Agustin Rebola Perricone
*   09/12/2023
*   Program that uses functions
*   to convert character to 
*   upper and lowercase, and convert
*   millimeters to inches and vice versa.
*
*/

#include <stdio.h>
#include <ctype.h>

void Greeting(void);
void InitialPractice(void);
void MillimetersToInches(void);
void InchesToMillimeters(void);

//calls each function
int main() 
{
    Greeting();
    InitialPractice();
    MillimetersToInches();
    InchesToMillimeters();
    return 0;
}

//greats the user to the program
void Greeting(void)
{
    printf("Welcome to program 3\n");
}

//asks the user to enter a character and then prints the 
//lowercase and uppercase version and the respective ascii values
void InitialPractice(void)
{
    char character_read;
    printf("\nEnter a character:\n");
    scanf(" %c", &character_read);
    character_read = tolower(character_read);
    printf("\nThe lowercase version of the letter is %c and its ascii value is %d \n", character_read,character_read);
    character_read = toupper(character_read);
    printf("The uppercasecase version of the letter is %c and its ascii value is %d \n", character_read,character_read);
}

//asks the user to enter the amount of millimeters to convert to inches
void MillimetersToInches(void)
{
    double millimeter, inch;
    printf("\nEnter mm to convert to inches:\n");
    scanf(" %lf", &millimeter);
    inch = millimeter * 0.03937;
    printf("The measurment you entered is %.3f and in inches is %.3f \n",millimeter,inch);
}

//asks the user to enter the amount of inches to convert to millimeters
void InchesToMillimeters(void)
{
    double inch, millimeter;
    printf("\nEnter inches to convert to mm:\n");
    scanf(" %lf", &inch);
    millimeter = inch * 25.4;
    printf("The measurment you entered is %.3f and in millimeters is %.3f",inch,millimeter);
}
