#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void MainGame() {
    const char *WordBank[] = {"able", "about", "box", "mouse", "computer", "car", "government"};
    int tries = 7;
    int correct = 0;

    int gen = rand() % 7;
    const char *Word = WordBank[gen];
    int hide = strlen(Word);

    for (int i = 0; i < hide; ++i) {
        printf("x");
    }
    printf("\n");

    while (tries != 0) {
        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        // Clear the input buffer
        while (getchar() != '\n');

        int found = 0;
        for (int i = 0; i < hide; ++i) {
            if (guess == Word[i]) {
                printf("That letter is in the word\n");
                correct++;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("You lost a body part\n");
            tries--;
        }

        if (tries == 0) {
            printf("You lose!\n");
        } else if (correct == hide) {
            printf("You win!\n");
            break;
        }
    }
}

/// revamo
///
void HangManGame(){
  
  const char *Bank[] = {"cat", "dog", "rat"};
  int tries = 7;
  int correct = 0;
  
  int gen = rand()% 3;
  const char *word = Bank[gen];
  int len = strlen(word);
  
  while(tries != 0){

    //printing out blank word
    for(int i =0; i < len; ++i){
      printf("x");
    }
    printf("\n");
    char UserInput;
    
    printf("Guess a word \n");
    scanf("%c", &UserInput);
    while(getchar() != '\n');

    int found = 0;
    for(int i = 0; i < len; ++i){
      if(UserInput == word[i]){
        printf("%c Congrats the letter is in: ", word[i]);
        correct ++;
        found = 1;
        break;
      }
    }
    if(found != 1){
      printf("WRONG... You just lost a life..");
      tries--;

    }
    if(tries == 0){
      printf("YOU LOSE WOMP WOMP ");
      break;
    }
    if(correct == len){
      printf("YOU WIN! YOU GUSSED ALL THE CORRECT LETTERS");
      break;
    }
    
  }

}

int main() {
    srand(time(NULL) ^ (getpid() << 16));
    usleep(1000);
    //MainGame();
    HangManGame();
    return 0;
}

