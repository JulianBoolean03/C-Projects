#include <stdio.h>
#include <string.h>

void Main_File_Search(const char *word) {
    // Asking for user input for file name
    char FileName[256];
    FILE *fp;
    char buffer[256];

    printf("Type a file name: \n");
    scanf("%255s", FileName);   

    // Opening the file
    fp = fopen(FileName, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", FileName);
        return;
    }

    // Searching for the word
    int found = 0;
    while (fscanf(fp, "%255s", buffer) == 1) {
        if (strcmp(buffer, word) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("The word '%s' was found in the file %s\n", word, FileName);
    } else {
        printf("The word '%s' was not found in the file %s\n", word, FileName);
    }
}

int main() {
    Main_File_Search("Word");
    return 0;
}

