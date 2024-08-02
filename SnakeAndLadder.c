#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

// COLORS
#define RESET   "\033[0m"
#define BOLDRED "\033[1m\033[31m" // Bold Red for Player 1
#define BOLDBLUE "\033[1m\033[34m" // Bold Blue for Player 2

void Board(int LocationOfplayer1, int LocationOfplayer2) {
    int board[100];
    int cnt = 1;

    for (int i = 0; i < 100; ++i) {
        board[i] = i;
    }
    board[LocationOfplayer1] = -1;
    board[LocationOfplayer2] = -2;
    for (int i = 1; i < 100; ++i) {
        if (board[i] == -1) {
            printf(BOLDRED "P1\t" RESET);  // Indicate player 1's position
        } else if (board[i] == -2) {
            printf(BOLDBLUE "P2\t" RESET);  // Indicate player 2's position
        } else {
            printf("%d\t", board[i]);
        }

        cnt++;
        if (i % 10 == 0 || cnt % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");  // Add an extra newline for better readability
}

// board setup
void SnakeAndLadder() {
    // game logic
    int selection;
    int Position1 = 1;
    int Position2 = 1;

    // Seed the random number generator once
    srand(time(NULL));

    while (Position1 < 99 && Position2 < 99) {
        printf("Player1, press 1 to roll: ");
        scanf("%d", &selection);
        if (selection == 1) {
            printf("\nRolling the dice for Player 1...\n");
            sleep(2);
            int roll = rand() % 8 + 1;
            int ladder = rand() % 13 + 12;
            int snake = rand() % 13 + 12;

            if (roll != 7 && roll != 8) {
                Position1 += roll;
                if (Position1 > 99) Position1 = 99;  // Ensure it doesn't go past 99
                printf("Player1 rolled a %d and moved to position %d\n", roll, Position1);
            } else if (roll == 7 && Position1 < 99) {
                Position1 += ladder;
                if (Position1 > 99) Position1 = 99;  // Ensure it doesn't go past 99
                printf("Player1 rolled a %d and hit a LADDER for %d. Player1 has moved up to position %d\n", roll, ladder, Position1);
            } else if (roll == 8 && Position1 > snake) {
                Position1 -= snake;
                printf("WOMP WOMP! Player1 rolled a %d and hit a SNAKE for %d. Player1 has moved back to position %d\n", roll, snake, Position1);
            }
            Board(Position1, Position2);
        }

        // Player 2
        printf("Player2, press 2 to roll: ");
        scanf("%d", &selection);
        if (selection == 2) {
            sleep(2);
            int roll = rand() % 8 + 1;
            int ladder = rand() % 13 + 12;
            int snake = rand() % 13 + 12;

            if (roll != 7 && roll != 8) {
                Position2 += roll;
                if (Position2 > 99) Position2 = 99;  // Ensure it doesn't go past 99
                printf("Player2 rolled a %d and moved to position %d\n", roll, Position2);
            } else if (roll == 7 && Position2 < 99) {
                Position2 += ladder;
                if (Position2 > 99) Position2 = 99;  // Ensure it doesn't go past 99
                printf("Player2 rolled a %d and hit a LADDER for %d. Player2 has moved up to position %d\n", roll, ladder, Position2);
            } else if (roll == 8 && Position2 > snake) {
                Position2 -= snake;
                printf("WOMP WOMP! Player2 rolled a %d and hit a SNAKE for %d. Player2 has moved back to position %d\n", roll, snake, Position2);
            }
            Board(Position1, Position2);
        }
    }

    if (Position1 >= 99) {
        printf("Player 1 wins!\n");
    } else if (Position2 >= 99) {
        printf("Player 2 wins!\n");
    }
}

int main() {
    SnakeAndLadder();
    return 0;
}

