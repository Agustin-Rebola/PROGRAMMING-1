/*
*
*   Agustin Rebola Perricone
*   09/05/2023
*   Brief program that reads 
*   character and numeric inputs
*   and manipulates them to 
*   practice scanf() and printf().
*
*/

#include <stdio.h>
#include <ctype.h>


int main(){
    //declare all variables 
    char user_input1, lowercase, user_input2, uppercase; 
    int user_integer;
    double user_double, multiplication_result, division_result, subtract_result;
    
    printf("Hello, my name is Agustin\n");  
    printf("enter a character:\n");                                             //asks for a character.
    scanf(" %c",&user_input1);                                                  //reads char and assignes to variable user_input1.
    lowercase = tolower(user_input1);                                           //converts char to lowercase in case user inputed uppercase char.
    printf("\nYou have entered: %c and lowercase is: %c \n",user_input1,lowercase);
    
    printf("\nenter a second character:\n");                                    //asks for a second character.
    scanf(" %c",&user_input2);                                                  //reads char and assignes to variable user_input2.
    uppercase = toupper(user_input2);                                           //converts char to uppercase in case user inputed lowercasecase char.
    printf("\nYou have entered: %c and uppercase is : %c \n",user_input2,uppercase);
    
    
    printf("\nenter an integer:\n");                                            //asks for an integer.
    scanf(" %d",&user_integer);                                                 //reads integer and assignes to variable user_integer.
    printf("enter a double:\n");                                                //asks for a double.
    scanf(" %lf",&user_double);                                                 //reads double and assignes to variable user_double.
    multiplication_result=(double)user_integer*user_double;                     //multiplies both numbers and assignes to multiplication_result.
    division_result=(double)user_double/user_integer;                           //divides both numbers and assignes to division_result.
    subtract_result=(double)user_integer-user_double;                           //subtracts both numbers and assignes to subtract_result.
    printf("the product of the these numbers is: %.3f\n",multiplication_result);//prints the result of multiplication
    printf("the quotient of the these numbers is: %.3f\n",division_result);     //prints the result of division
    printf("the subtraction of the these numbers is: %.3f\n",subtract_result);  //prints the result of subtraction
    
    return 0;
}
