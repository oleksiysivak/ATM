#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Cypr.h"
#define MAX_LEN 100

char caesar_encode(char message[], char direction, int offset);
char caesar_decode(char message[], char direction, int offset);
char vigenere_encode(char message[], char key[]);
char vigenere_decode(char message[], char key[]);
//char salted_caesar_encode(char message, char direction, int offset, char salt);
//salted_caesar_decode(char message, char direction, int offset, char salt);

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
    if (choice == 'd') 
    {
      printf("Which method do you want to use? (c/v/s)\n");
      scanf(" %c", &choice);

      // ask for the method specific information
      if (choice == 'c') 
    {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        caesar_decode(message, direction, offset);
    } 
      else if (choice == 'v') 
    {
        printf("Key?\n");
        scanf("%s", key);
        vigenere_decode(message, key);
    } 
      else if (choice == 's')
      {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        salted_caesar_decode(message, direction, offset, username);
      }
while (2) 
    // query the user on whether they want to encode or decode a message
    printf("Do you want to encode or decode a message? (e/d)\n");
    scanf(" %c", &choice);
    
    // ask for the method if the user wants to encode a message
    if (choice == 'e') 
    {
      printf("Which method do you want to use? (c/v/s)\n");
      scanf(" %c", &choice);
    }
      // if the selection is to encode a message
      if (choice == 'c') 
    {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        caesar_encode(message, direction, offset);
    } 
      else if (choice == 'v') 
    {
        printf("Key?\n");
        scanf("%s", key);
        vigenere_encode(message, key);
    } 
      else if (choice == 's') 
    {
        printf("Left or Right? (l/r)\n");
        scanf(" %c", &direction);
        printf("Offset?\n");
        scanf("%d", &offset);
        salted_caesar_decode(message, direction, offset, username);
    }
// Caesar cipher implementation
char *caesar_encode(char *message, int offset, char direction) {
  int i;
  char *encoded = malloc(strlen(message) + 1);
  for (i = 0; message[i]; i++) {
    encoded[i] = message[i] + (direction == 'r' ? offset : -offset);
  }
  encoded[i] = '\0';
  return encoded;
  }
char *caesar_decode(char message, int offset, char direction) 
{
  return caesar_encode(message, offset, direction == 'r' ? 'l' : 'r');
}

// Vigenère cipher implementation
char vigenere_encode(char message, char *key) {
  int i, j;
  int message_len = strlen(message);
  int key_len = strlen(key);
  char encoded = malloc(message_len + 1);
  for (i = 0; i < message_len; i++) {
    encoded[i] = message[i] + key[i % key_len];
  }
  encoded[i] = '\0';
  return encoded;
}

char vigenere_decode(char message, char key) {
  int i, j;
  int message_len = strlen(message);
  int key_len = strlen(key);
  char decoded = malloc(message_len + 1);
  for (i = 0; i < message_len; i++) {
    decoded[i] = message[i] - key[i % key_len];
  }
  decoded[i] = '\0';
  return decoded;
}

// Salted Caesar cipher implementation
char salted_caesar_encode(char message, int offset, char direction, char salt) {
  int i;
  int message_len = strlen(message);
  int salt_len = strlen(salt);
  char *encoded = malloc(message_len + salt_len + 1);
  for (i = 0; i < message_len; i++) {
    encoded[i] = message[i] + (direction == 'r' ? offset : -offset) + salt[i % salt_len];
  }
  strcpy(encoded + message_len, salt);
  encoded[message_len + salt_len] = '\0';
  return encoded;
}
char salted_caesar_decode(char message[], int offset, char direction, char salt)
 {
  int i;
  int message_len = strlen(message) - strlen(salt);
  int salt_len = strlen(salt);
  char decoded = malloc(message_len + 1);
  for (i = 0; i < message_len; i++) 
  {
    decoded[i] = message[i] - (direction == 'r' ? offset : -offset) - salt[i% salt_len];
  }
  strcpy(decoded + message_len, salt);
  decoded[message_len - salt_len] = '\0';
  return decoded;
}

