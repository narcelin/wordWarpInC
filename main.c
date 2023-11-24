#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include <stdio.h> //for printf and scanf
#include <string.h> //for strlen and strcmp functions
#include <ctype.h> //for tolower and toupper functions
#define SIZE 25 //size of the character arrays is 25

//function prototypes
void Instructions();
//Welcome the user and display the instructions on how to play the game.
void PlayOneGame(char jumbled[], char solution[]);
//input: solution word and scrambled word
//plays one round ot the game
void PlayAgain(char* againPtr);
//input: character (input/ouptput) parameter
//determines if the player would like to play again.
void UppercaseWord(char word[]);
//input: a character array with a null character (string)
//sets all of the characters in a word to uppercase letters
void WinOrLose(int win);
//input a 1 or a 0
//tells the user they won if the input is 1 and they lost if the input is 0

int main(){
    char again, jumbledWord[SIZE], solutionWord[SIZE], guessWord[SIZE];
    FILE *in_JumbledWordsPntr;
    in_JumbledWordsPntr = fopen("./jumbledWords.txt", "r");
        if(in_JumbledWordsPntr == NULL){
            printf("ERROR IMPORTING FILE");
            return 1;
        };
    do {
        fscanf(in_JumbledWordsPntr, "%s", jumbledWord); //First Line
        fscanf(in_JumbledWordsPntr, "%s", solutionWord); //Second Line

        UppercaseWord(jumbledWord);
        UppercaseWord(solutionWord);
        

        // printf("\nJUMBLED WORD: %s \n\n", jumbledWord);
        // printf("\nSOLUTION WORD: %s \n\n", solutionWord);

        Instructions();
        PlayOneGame(jumbledWord, solutionWord);

        PlayAgain(&again);
    } while (again == 'Y' || again == 'y');

    printf("Thank you for playing!");
    fclose(in_JumbledWordsPntr);

    return 0;
}

void Instructions(){

    printf("Welcome to JUMBLED WORD! \nYour mission is the decifer the scrambled word. You will be given 3 tries. Good luck!\n");
};

void PlayOneGame(char jumbled[], char solution[]){
        char userGuess[SIZE];
        int attempt = 1;
        int solutionLen = strlen(solution);
    //input: solution word and scrambled word
    //plays one round ot the game

    

    printf("There are %d letters in the word\n", solutionLen);
    printf("JUMBLED WORD: %s", jumbled);
    do{
        if(attempt > 1){
            printf("%s is not correct\n", userGuess);
            printf("First and last letter are %c, %c respectivley", solution[0], solution[solutionLen-1]);
        } 

        printf("\nAttempt %d. Input Guess: ", attempt); 
        scanf("%s", userGuess);
        UppercaseWord(userGuess);

        attempt++;
    } while (strcmp(userGuess, solution) !=0 && attempt != 4);

    if(strcmp(userGuess, solution) == 0){ 
        WinOrLose(1);
        } else {
            WinOrLose(0);
        };
    // printf("USER GUESS %s", userGuess);

};

void PlayAgain(char* againPtr){
    //input: character (input/ouptput) parameter
    //determines if the player would like to play again.
    printf("\nWould you like to play again (y or n)? : ");
    scanf(" %c", againPtr);
};

void UppercaseWord(char word[]){
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        word[i] = toupper(word[i]); //arrays are pointers
    }
    //input: a character array with a null character (string)
    //sets all of the characters in a word to uppercase letters
};

void WinOrLose(int win){

    //input a 1 or a 0
    //tells the user they won if the input is 1 and they lost if the input is 0
    if(win == 1){
        printf("Congradulations! You have won.");
    } else if (win == 0) {
        printf("You did not win");
    }else {
        printf("ERROR");
    };
};