#include <math.h>
#include <stdio.h>
#include <stdbool.h>

void MyApp(){
  bool OFF = false;
  int selection;
  int storage;

  while(OFF == false){

    printf("What would you like to do?  1: Multiply, 2: divide, 3: subtract, 4: add, 5: Exit\n");
    scanf("%d", &selection);

    if(selection == 1){
      int temp;
      int sectionResult = 0;
      printf("Multiply Enter a number");
      scanf("%d", &storage);
      printf("Enter another number: ");
      scanf("%d", &temp);
      sectionResult = storage * temp;
      printf("%d", sectionResult );
  
    }

    if(selection == 2){
      int temp;
      int selectionResult = 0;
      printf("Divide Enter a number");
      scanf("%d", &storage );
      printf("Enter another number");
      scanf("%d", &temp);
      if(temp != 0){
          selectionResult = storage / temp;
          printf("%d", selectionResult);
      }else {
        printf("ERROR: Division by zero is not allowed. \n");
      }
    }

    if(selection == 3){
      int temp;
      int selectionResult = 0;
      printf("Subtract Enter a number");
      scanf("%d", &storage );
      printf("Enter another number");
      scanf("%d", &temp);
      selectionResult = storage - temp;
      printf("%d", selectionResult);
    }
    if( selection == 4){
      int temp;
      int selectionResult = 0;
      printf("Add Enter a number");
      scanf("%d", &storage );
      printf("Enter another number");
      scanf("%d", &temp);
      selectionResult = storage + temp;
      printf("%d", selectionResult);
    }

    if (selection == 5){
      OFF = true;

    }

  }
  printf("GOODBYE!");
      
}

int main(){
 MyApp(); 

  return 0;
}
