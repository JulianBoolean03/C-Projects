#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool Login(char use[], char pass[]) {
    FILE *fptr;
    char file_username[255];
    char file_password[255];

    fptr = fopen("database.txt", "r");
    if (fptr == NULL) {
        printf("ERROR OPENING THE FILE\n");
        return false;
    }

    while (fscanf(fptr, "Username: %254s\nPassword: %254s\n", file_username, file_password) == 2) {
        if (strcmp(use, file_username) == 0 && strcmp(pass, file_password) == 0) {
            printf("Logged in successfully\n");
            fclose(fptr);
            return true;
        }
    }

    fclose(fptr);
    return false;
}

void Register() {
    FILE *fptr;
    char username[255] = "";
    char password[255] = "";

    fptr = fopen("database.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter a username: \n");
    scanf("%254s", username);  
    printf("\nEnter a password: \n");
    scanf("%254s", password); 

    fprintf(fptr, "Username: %s\nPassword: %s\n", username, password);  
    fclose(fptr);  
}

void BankAccount() {
    char username[255] = "";
    char password[255] = "";
    int balance = 500;
    int userbalance;
    int selection;

    printf("\nLogin press 1: Create Account Press 2: \n");
    scanf("%d", &selection);

    if (selection == 1) {
        printf("\nEnter your username: \n");
        scanf("%254s", username);  // 254 to leave space for null terminator

        printf("\nEnter your password: \n");
        scanf("%254s", password);  // 254 to leave space for null terminator

        if (Login(username, password)) {
            printf("YOU ARE NOW LOGGED IN!\n");

            printf("\nWould you like to deposit or withdraw money? 1: deposit 2: withdraw 3: check balance\n");
            scanf("%d", &selection);
            if (selection == 1) {
                printf("How much money would you like to deposit? \n");
                scanf("%d", &userbalance);
                balance += userbalance;
                printf("Your new balance is: %d\n", balance);
            } else if (selection == 2) {
                printf("How much money would you like to withdraw? \n");
                scanf("%d", &userbalance);
                if (userbalance > balance) {
                    printf("Insufficient funds! Your current balance is: %d\n", balance);
                } else {
                    balance -= userbalance;
                    printf("Your new balance is: %d\n", balance);
                }
            } else if (selection == 3) {
                printf("Your current balance is: %d\n", balance);
            } else {
                printf("Invalid selection!\n");
            }
        } else {
            printf("ERROR!\n");
        }
    } else {
        Register();
    }
}

int main() {
    BankAccount();
    return 0;
}

