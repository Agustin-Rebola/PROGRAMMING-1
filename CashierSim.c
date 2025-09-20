/* 
*
*   Agustin Rebola Perricone
*   09/25/2023
*   Program that simulates a 
*   food purchasing app implementing 
*   various user made functions and  
*   conditional functions
*
*/

#include <stdio.h>
void Greeting(void);
int DisplayFoodSelections();
double SetPrice(int itemNumber);
double AddQuantityToOrder(double price);
double Checkout(double balance, double totalPrice);
int CheckForEnough(double balance, double totalPrice);
double Reload(double balance);


int main(){
    double balance = 20;
    int itemNumber = 0;
    double price = 0;
    double totalPrice = 0;
    double remainingBalance = 0;
    
    //greets the user
    Greeting();
    
    //shows the current balance
    printf("\nThe current balance in your account is $%.2f\n", balance);
    printf("---------------------------------------------");
    
    //gets product ID of selection
    itemNumber = DisplayFoodSelections();
    
    //closes program if selection is invalid
    if(itemNumber == 0  || itemNumber > 7) { return 0; }
    
    //gets price based on product ID
    price = SetPrice(itemNumber);
    printf(" the price is: $%.2f\n", price);
    
    //calculates total price based on quantity
    totalPrice = AddQuantityToOrder(price);
    printf("\nThe total is: $%.2f\n", totalPrice);
    
    //checks balance, adds if needed and returns remaining balance
    remainingBalance = Checkout(balance, totalPrice);
    
    return 0;
}
 
void Greeting(void){
    printf("Welcome to the food purchasing app\n");
    printf("You will be presented with a list of items and your account balance. \n");
    printf("Please select the number for the item you wish to purchase, one at a time.\n");
    printf("At checkout, if you do not have enough money to cover the purchase \n");
    printf("you will be asked to add money to your account until you have entered enough money to \n");
    printf("make the purchase. \n");
}

int DisplayFoodSelections()
{
    //displays menu
    printf("\nHere are the food options:\n ");
    printf("   (1) The Box Combo - $11.39\n ");
    printf("   (2) The Caniac Combo - $16.35\n ");
    printf("   (3) The 3 Finger Combo – $9.79\n ");
    printf("   (4) The Sandwich Combo – $9.99\n ");
    printf("   (5) The kids Combo – $6.49\n ");
    printf("   (6) Drink only – $2.99\n ");
    printf("   (7) Sandwich only – $7.99\n ");
    
    //reads menu option and displays selection name
    printf("\nEnter your selection (1-7) :");
    int itemPicked;
    scanf("%d", &itemPicked);
    switch(itemPicked){
        case 1:
            printf("You have selected: The Box Combo,");
            break;
        case 2:
            printf("You have selected: The Caniac Combo,");
            break;
        case 3:
            printf("You have selected: The 3 Finger Combo,");
            break;
        case 4:
            printf("You have selected: The Sandwich Combo,");
            break;
        case 5:
            printf("You have selected: The kids Combo,");
            break;    
        case 6:
            printf("You have selected: Drink only,");
            break;
        case 7:
            printf("You have selected: Sandwich only,");
            break;
        default:
            printf("You have selected an invalid option");
            itemPicked = 0;
            break;
    }
    
    //returns item ID to main function
    return itemPicked;
}

double SetPrice(int itemNumber){
    double priceF = 0;
    
    //receives item ID and assignes the price
    switch(itemNumber){
        case 1:
            priceF = 11.39;
            break;
        case 2:
            priceF = 16.35;
            break;
        case 3:
            priceF = 9.79;
            break;
        case 4:
            priceF = 9.99;
            break;
        case 5:
            priceF = 6.49;
            break;    
        case 6:
            priceF = 2.99;
            break;
        case 7:
            priceF = 7.99;
            break;
        
    }
    
    //returns price to main function 
    return priceF;
}

double AddQuantityToOrder(double price){
    double totalPriceF = 0;
    int quantity = 0;
    printf("How many do you want to order:\n");
    scanf("%d", &quantity);
    return totalPriceF = price * quantity;
}

double Checkout(double balance, double totalPrice){
    int isEnough = 0;
    isEnough = CheckForEnough(balance, totalPrice);
    if(isEnough == 1){
        balance = balance - totalPrice;
        printf("The transaction was succesfull, your remaining balance is: $%.2f\n", balance);
        printf("Enjoy your purchase and have a nice day!\n");
        printf("\nHave a great day!");
    }
    if(isEnough == 0){
        printf("\nYou do not have money to cover the total");
        printf("\nTotal is: $%.2f and your balance is: $%.2f",totalPrice,balance);
        balance = Reload(balance);
        printf("Your new balance is: $%.2f \n", balance);
        printf("Enjoy your purchase and have a nice day!\n");
        balance = balance - totalPrice;
        printf("The current balance in your account is: $%.2f", balance);
        printf("\nHave a great day!");
    }
}

int CheckForEnough(double balance, double totalPrice){
    if(balance >= totalPrice){
        return 1;
    }
    
    else{
        return 0;
    }
}

double Reload(double balance){
    double addMoney;
    printf("\nHow much would you like to add?\n");
    scanf("%lf", &addMoney);
    balance = balance + addMoney;
    return balance;
}

