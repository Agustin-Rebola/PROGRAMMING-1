//C program that simulates a food purchasing app.
//Greets the user, and presents instructions on how to proceed 
//based on user's choices

//I have taken the liberty to start the program staight into picking the items
//instead of going into the selection menu first. That is what I understood from 
//the description given for the sample output and seems like the logic order
//in which the program should go. If this approach is wrong please let me know.

#include <stdio.h>

// Prototypes
void Greeting(void);                    								//welcomes the user and gives instructions
void MenuSelection(char *selectionPtr); 								//displays the menu and gets the character from the user
void OneItemOrder(double *totalPtr);    	    						//is used to call all subsequent item picking functions
int DisplayFoodSelections();            								//shows what item options are avialable
double SetPrice(int itemNumber);        								//returns price based on menu option
double AddQuantityToOrder(double price);								//multiplies price by quantity to get final price
double Checkout(double balance, double totalPrice);						//in charge of calling functions related to balance
int CheckForEnough(double balance, double totalPrice);					//checks if balance is enough for purchase
double Reload(double balance);          								//asks the user to add money to cover balance due

int main(){
    //Variables
    double balance = 0;
    double total;
    double totalPrice = 0;
    char selection;
    int menu_op = 0;
    
    //initialize File
    FILE *balanceFileIn, *balanceFileOut;
    balanceFileIn = fopen ("foodAccountBalance.txt","r");
    fscanf(balanceFileIn,"%lf",&balance);
    balanceFileOut = fopen ("foodAccountBalance.txt","w");
    printf("THE BALANCE IS: %f\n\n\n",balance);
    Greeting();
    OneItemOrder(&total);
    totalPrice += total;
    total = 0;
    
    //stays in menu until 'Q' is selected
    while(menu_op != 1){           
        MenuSelection(&selection);
        if(selection == 'A' || selection == 'a'){
            OneItemOrder(&total);
            totalPrice += total;
            printf("\nTHE TOTAL IS: $%.2lf",totalPrice);
            total = 0;
        }
        else if( selection == 'C' || selection == 'c'){
            balance = Checkout(balance, totalPrice);
            total = 0;
            totalPrice = 0;
        }
        else if(selection == 'N' || selection == 'n'){
            total = 0;
            totalPrice = 0;
            printf("The total balance has been reset to $0.00\n");
        }
        else if(selection == 'Q' || selection == 'q'){
            menu_op = 1;
            fprintf(balanceFileOut,"%.2f",balance);
            fclose(balanceFileOut);
            fclose(balanceFileIn);
        }
        else{
            printf("\n You have entered an invalid option. Please try again. \n");
        }
    }
    
    
    return 0;
}

//Greets the user and gives instruction for the app
void Greeting(void){
    printf("Welcome to the food purchasing app\n");
    printf("You will be presented with a list of items and your account balance. \n");
    printf("Please select the number for the item you wish to purchase, one at a time.\n");
    printf("You may add additional items to your order(A) before checking out (C).\n");
    printf("You may start over by selecting (N) and you edn the program by selecting (Q)).\n");
    printf("At checkout, if you do not have enough money to cover the purchase \n");
    printf("you will be asked to add money to your account until you have entered enough money to \n");
    printf("make the purchase\n");
}

//Displays and gets option to add, checkout or leave
void MenuSelection(char *selectionPtr){
    printf("\nPlease select from the following:\n");
    printf("A or a...to Add an item to your order.\n");
    printf("C or c...to Check out,\n");
    printf("N or n...to to start a New order\n");
    printf("Q or q...to Quit:\n");
    scanf(" %c",selectionPtr);
}

//Function in charge of calling other functions to get item, quantities and price
void OneItemOrder(double *totalPtr){
    int itemNumber = 0;
    double price = 0;
    
    itemNumber = DisplayFoodSelections();
    if(itemNumber !=0){
        price = SetPrice(itemNumber);
    printf("\nThe price is: $%.2f\n", price);
    *totalPtr = AddQuantityToOrder(price);
    printf("\nThe total is: $%.2f\n", *totalPtr);
    }
    
    
}

//Displays the item menu and gets user's selection
int DisplayFoodSelections(){
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
            printf("You have selected: The Box Combo");
            break;
        case 2:
            printf("You have selected: The Caniac Combo");
            break;
        case 3:
            printf("You have selected: The 3 Finger Combo");
            break;
        case 4:
            printf("You have selected: The Sandwich Combo");
            break;
        case 5:
            printf("You have selected: The kids Combo");
            break;    
        case 6:
            printf("You have selected: Drink only");
            break;
        case 7:
            printf("You have selected: Sandwich only");
            break;
        default:
            printf("\nYou have selected an invalid option\n");
            itemPicked = 0;
            return 0;
            break;
    }

    //returns item ID to main function
    return itemPicked;
}

//Returns item price based on item selected
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

//multiplies the prices by the quantity the user inputs
double AddQuantityToOrder(double price){
    double totalPriceF = 0;
    int quantity = 0;
    printf("\nHow many do you want to order:\n");
    scanf("%d", &quantity);
    return totalPriceF = price * quantity;
}

//Function responsible of calling functions involved in checkout
double Checkout(double balance, double totalPrice){
    int isEnough = 0;
    isEnough = CheckForEnough(balance, totalPrice);
    if(totalPrice != 0){
        while(isEnough == 0){
            printf("\nYou do not have money to cover the total\n");
            printf("\nTotal is: $%.2f and your balance is: $%.2f \n",totalPrice,balance);
            balance = Reload(balance);
            printf("\nYour new balance is: $%.2f \n", balance);
            isEnough = CheckForEnough(balance, totalPrice);
        } 
        balance = balance - totalPrice;
        printf("The transaction was succesfull, your remaining balance is: $%.2f\n", balance);
        printf("Enjoy your purchase and have a nice day!\n");
        printf("\nHave a great day!");
        return balance;
    }
    else{
        printf("\nYou have not entered any item.Please press 'A' to add an item.\n");
    }
}

//checks if balance is enough to cover the total cost
int CheckForEnough(double balance, double totalPrice){
    if(balance >= totalPrice){
        return 1;
    }
    
    else{
        return 0;
    }
}

//asks the user to add money to increase balance
double Reload(double balance){
    double addMoney;
    printf("\nHow much would you like to add?\n");
    scanf("%lf", &addMoney);
    balance = balance + addMoney;
    return balance;
}



