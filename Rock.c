#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void RPS()
{
  int opponent;
  int player;

  srand(time(NULL));
  opponent = rand()%3 +1;
  printf("Enter your option 1: rock, 2: paper, 3: Scissors");
  scanf("%d", &player);

  if(player == 1 && opponent == 2){
    printf("You used ROCK and the option used Paper. YOU LOSE!\n");
  } else if (player == 2 && opponent ==3) {
    printf("You used Paper and the opponent used Scissors. YOU LOSE!\n");

  }else if ( player == 3 && opponent == 1) {
    printf("You used Scissors and the opponent used Rock. YOU LOSE\n");

  }else if (player == opponent) {
    printf("The game ended in a TIE!\n");

  }else{
    printf("YOU WIN!\n");
    
  }  
}


  int main(){
  RPS();
  
 
  return 0;
}
