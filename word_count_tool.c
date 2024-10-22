///////(2)///////////// C program for word count tool
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int characters = 0, words = 0, lines = 0;
    int in_word = 0;

 printf("Enter the filename: ");
 scanf("%s", filename);

 file = fopen(filename, "r");
    
 if (file == NULL) {
     printf("Error: Could not open file %s\n", filename);
    return 1;
 }

while ((ch = fgetc(file)) != EOF) {
        characters++;

    
    if (ch == '\n') {
            lines++;
        }

     if (isspace(ch)) {
            in_word = 0;  // End of a word
        } else if (!in_word) {
            in_word = 1;  // Start of a word
            words++;
        }
    }

    fclose(file);

    printf("Total Characters: %d\n", characters);
    printf("Total Words: %d\n", words);
    printf("Total Lines: %d\n", lines);

    return 0;
}
