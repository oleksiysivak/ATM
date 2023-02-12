#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

void caesar_encode(char message[], char direction, int offset);
void caesar_decode(char message[], char direction, int offset);
void vigenere_encode(char message[], char key[]);
void vigenere_decode(char message[], char key[]);
void salted_caesar_encode(char message[], char direction, int offset, char username[]);
void salted_caesar_decode(char message[], char direction, int offset, char username[]);

int main(int argc, char *argv[]) {
  // check if the user provided a username
  if (argc != 2) {
    printf("Error: Please provide a username as an argument\n");
    return 1;
  }

  // check if the username is alphabetic only 
  int len = strlen(argv[1]);
  for (int i = 0; i < len; i++) {
    if (!isalpha(argv[1][i])) {
      printf("Error: The username can only contain alphabetic characters\n");
      return 1;
    }
  }

  char username[MAX_LEN];
  strcpy(username, argv[1]);

  // welcome the user and output the username
  printf("Welcome, %s!\n", username);

  char choice;
  char message[MAX_LEN];
  char direction;
  int offset;
  char key[MAX_LEN];

  while (1) {
    // query the user on whether they want to encode or decode a message
    printf("Do you want to encode or decode a message? (e/d)\n");
    scanf(" %c", &choice);

    // ask for the method if the user wants to decode a message
    if (choice == 'd') {
      printf("Which method do you want to use? (c/v/s)\n");
      scanf(" %c", &choice);

      // ask for the method specific information
      if (choice == 'c') {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        caesar_decode(message, direction, offset);
      } else if (choice == 'v') {
        printf("Key?\n");
        scanf("%s", key);
        vigenere_decode(message, key);
      } else if (choice == 's') {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        salted_caesar_decode(message, direction, offset, username);
      }
    } else if (choice == 'e') {
      printf("Which method do you want to use? (c/v/s)\n");
      scanf(" %c", &choice);
      // ask for the method specific information
      if (choice == 'c') {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        caesar_decode(message, direction, offset);
      } else if (choice == 'v') {
        printf("Key?\n");
        scanf("%s", key);
        vigenere_decode(message, key);
      } else if (choice == 's') {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        salted_caesar_decode(message, direction, offset, username);
         
         return 1; }
  for ()
    