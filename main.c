#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf and scanf
#include<string.h> //for strlen and strcmp functions
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
    char jumbledWord[SIZE], solutionWord[SIZE], guessWord[SIZE];

    FILE *in_JumbledWordsPntr;
    in_JumbledWordsPntr = fopen("./jumbledWords.txt", "r");
        if(in_JumbledWordsPntr == NULL){
            printf("ERROR IMPORTING FILE");
            return 1;
        };
    fscanf(in_JumbledWordsPntr, "%s", jumbledWord); //First Line
    fscanf(in_JumbledWordsPntr, "%s", solutionWord); //Second Line
    fclose(in_JumbledWordsPntr);

    // printf("\nJUMBLED WORD: %s \n\n", jumbledWord);
    // printf("\nSOLUTION WORD: %s \n\n", solutionWord);

    Instructions();

    return 0;
}

void Instructions(){

    printf("Welcome to JUMBLED WORD! \nYour mission is the decifer the scrambled word. You will be given 3 tries. Good luck!\n");
};

void PlayOneGame(char jumbled[], char solution[]){
//input: solution word and scrambled word
//plays one round ot the game

};

void PlayAgain(char* againPtr){

//input: character (input/ouptput) parameter
//determines if the player would like to play again.
};

void UppercaseWord(char word[]){

//input: a character array with a null character (string)
//sets all of the characters in a word to uppercase letters
};

void WinOrLose(int win){

//input a 1 or a 0
//tells the user they won if the input is 1 and they lost if the input is 0
};