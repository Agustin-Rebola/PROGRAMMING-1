#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include <stdlib.h> used to debug with system("pause") in windows

//program that simulates jumbled word game. Two files(jumbled and solution) are read,
//then the user is displayed the jumbled word and is asked what the word is.
//The program will compare them and decide based on the answer the user can get another attempt,
//win or lose. Lastly the user is asked if he wants to play again.

// Prototypes provided by instructor
void Instructions();                    			
void PlayOneGame(char jumbled[], char solution[]);	
void PlayAgain(char* againPtr);         	    	
void UppercaseWord(char word[]);          			
void WinOrLose(int win);                			

int main(){
    //main variables = both arrays that hold the solution and jumbled words
    char solution[50];
    char jumbled[50];
    char again;
    
    //initialize both files and fetch first words from each
    FILE *jumbledIn, *solutionIn;
    solutionIn = fopen("SOLUTION.txt", "r");
    if (solutionIn == NULL) {
        printf("Error! Solution file cannot be opened.");
        return 1; //return one means that the program ended because the file could not be opened
    }
    jumbledIn = fopen("JUMBLED.txt", "r");
    if (jumbledIn == NULL) {
        printf("Error! Jumbled file cannot be opened.");
        return 1;
    }

    //read from files and write to arrays
    Instructions();

    //Uppercase both arrays, start them game and determine if the user wants to play again
    do {
        fscanf(solutionIn,"%s",solution);
        fscanf(jumbledIn,"%s",jumbled);
        UppercaseWord(jumbled);
        UppercaseWord(solution);
        PlayOneGame(jumbled, solution);
        PlayAgain(&again);
    } while (again == 'Y'|| again == 'y');

    //thank the user and close both files
    printf("\nThanks for playing the jumbled game!!\n");
    fclose(solutionIn);
    fclose(jumbledIn);

    return 0;
}

//Display game instructions to user
void Instructions(){
    printf("Welcome to the JUMBLED game\n");
    printf("You will see the word in scrambled form.\n");
    printf("The jumbled word will be displayed.\n");
    printf(". . . Next you guess the word . . .\n");
    printf("If you do not guess the word on the first try\n");
    printf("The first and last letters will be displayed\n");
    printf("\nYou will have three guesses to figure it out!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//read users guess,compare to the solution array and execute based on this
void PlayOneGame(char jumbled[], char solution[]) {
    int attempts = 1;
    char guess[50];
    int ammountLetters = 0;
    ammountLetters = strlen(solution);
    int win = 0;

    while(attempts < 4){
        printf("There are %d letters in the word\n",ammountLetters);
        printf("Guess this word: %s\n", jumbled);
        scanf("%s", guess);
        UppercaseWord(guess);
        if(strcmp(guess, solution) == 0) {
            printf("The word was %s \n", solution);
            win = 1;
            WinOrLose(win);
            attempts = 4;
        }
        //loops until user guesses or no more available attempts
        else{
            printf("--%s is not the word \n", guess);
            printf("--that was guess number %d \n", attempts);
            printf("--Here is the first letter: %c \n", solution[0]);
            printf("--Here is the last letter: %c \n", solution[strlen(solution) - 1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            attempts ++;
            if(win == 0 && attempts == 4){
                printf("The word was %s \n", solution);
                WinOrLose(win);
            }
        }
    }
    
}

//asks play if he wants to play another round
void PlayAgain(char *againPtr) {
    printf("\nDo you want to play again? (Y/N): ");
    scanf(" %c", againPtr);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//go through each letter of the array and applys the uppercase letter to each
void UppercaseWord(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = toupper(word[i]);
    }
}

void WinOrLose(int win) {
    if (win == 1) {
        printf("Yay -- you won :)\n");
    } else {
        printf("\nSorry you did not win this round\n");
    }
}
