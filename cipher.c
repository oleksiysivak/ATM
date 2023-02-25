#include <stdio.h> 
#include <stdlib.h>

// Declarations
int getChoice();
void encrypt(const char *userName);
void decrypt();
int getCipherChoice();
void convertToUpperCase(char *input);

void ceasarEncrypt(char *);
void ceasarDecrypt(char *);
void getCeasarInfo(char *type, int *key);

void vigenereEncrypt(char *message, const char *key);
void vigenereDecrypt(char *message, char *key);

int main(int argc, char **argv) {

  // if user didn't enter any command line argument, print out the usage
  if (argc != 2) {
    printf("No valid username line argument\n");
    return 1;
  }
  // welcome message
  convertToUpperCase(argv[1]);
  printf("Welcome %s to the cipher app!\n\n", argv[1]);
  int choice = 0;
  do {
    choice = getChoice();
    if (choice == 1) {
      encrypt(argv[1]);
    } else if (choice == 2) {
      decrypt(argv[1]);
    } else if (choice == 3) {
      printf("Goodbye %s!\n", argv[1]);
    }
    printf("\n");

  } while (choice != 3);

  return 0;
}

// get first choice
int getChoice() {
  // main menu
  printf("What Would you like to do?\n");
  printf("1. Encode a message\n");
  printf("2. Decode a message\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");

  // input choice
  int choice;
  scanf("%d", &choice);

  // invalid choice
  while (choice < 1 || choice > 3) {
    printf("Invalid choice, please enter a number between 1 and 3: ");
    scanf("%d", &choice);
  }
  return choice;
}

void encrypt(const char *username) {

  // cipher choice menu
  int cipherChoice = getCipherChoice();

  char message[100];
  char key[100];
  printf("Enter the message to encrypt: ");
  // ignore a newline character
  getchar();
  scanf("%99[^\n]", message);

  convertToUpperCase(message);
  // Ceasar Cipher
  if (cipherChoice == 1) {
    ceasarEncrypt(message);
  }

  // Vigenere Cipher
  else if (cipherChoice == 2) {
    printf("Enter the key: ");
    scanf("%s", key);
    convertToUpperCase(key);
    vigenereEncrypt(message, key);
  }

  // Salted Ceasar
  else if (cipherChoice == 3) {
    ceasarEncrypt(message);
    vigenereEncrypt(message, username);
  }
  printf("Encrypted message: %s\n", message);
  char ch;
  printf("\nDo you want to decode or encode more messages(y/n): ");
  scanf(" %c", &ch);
  if(ch != 'y' && ch != 'Y') {
    printf("Goodbye %s!\n", username);
    exit(0);
  }
}

int getCipherChoice() {
  // print menu
  printf("What cipher would you like to use?\n");
  printf("1. Caesar Cipher\n");
  printf("2. Vigenere Cipher\n");
  printf("3. Salted Ceasar\n");
  printf("Enter your choice: ");

  // input choice
  int choice;
  scanf("%d", &choice);

  // invalid  choice
  while (choice < 1 || choice > 3) {
    printf("Invalid choice, please enter a number between 1 and 3: ");
    scanf("%d", &choice);
  }
  return choice;
}

void decrypt(char *username) {

  // Get the cipher use wants to use
  int cipherChoice = getCipherChoice();
  // get the mssage to decrypt
  char message[100];
  char key[100];
  printf("Enter the message to decrypt: ");
  getchar();
  scanf("%99[^\n]", message);

  // CAPs converter
  convertToUpperCase(message);

  // Cypher to use choice
  if (cipherChoice == 1) {
    ceasarDecrypt(message);
  } else if (cipherChoice == 2) {
    printf("Enter the key: ");
    scanf("%s", key);
    convertToUpperCase(key);
    vigenereDecrypt(message, key);
  } else if (cipherChoice == 3) {
    vigenereDecrypt(message, username);
    ceasarDecrypt(message);
  }
  printf("Decrypted message: %s\n", message);
  char ch;
  printf("\nDo you want to decode or encode more messages(y/n): ");
  scanf(" %c", &ch);
  if(ch != 'y' && ch != 'Y') {
    printf("Goodbye %s!\n", username);
    exit(0);
  }
}

void ceasarEncrypt(char *message) {
  char type;
  int offset;
  getCeasarInfo(&type, &offset);

  int i = 0;
  while (message[i] != '\0') {
    if (message[i] != ' ') {
      // if user wants to perform left encryption
      if (type == 'l' || type == 'L') {
        message[i] = (message[i] - offset);
        if (message[i] < 65) {
          message[i] += 26;
        }
      }
      // if user wants to perform right encryption
      else {
        message[i] = (message[i] + offset);
        // make sure that the input stays within small alphabets
        if (message[i] > 90) {
          message[i] -= 26;
        }
      }
    }
    i++;
  }
}

void ceasarDecrypt(char *message) {
  char type;
  int offset;
  getCeasarInfo(&type, &offset);

  int i = 0;
  while (message[i] != '\0') {
    if (message[i] != ' ') {
      // if user wants to perform left encryption
      if (type == 'l' || type == 'L') {
        message[i] = (message[i] + offset);
        if (message[i] > 90) {
          message[i] -= 26;
        }
      }
      // if user wants to perform right encryption
      else {
        message[i] = (message[i] - offset);
        if (message[i] < 65) {
          message[i] += 26;
        }
      }
    }
    i++;
  }
}

// ceasar cipher info and the offset
void getCeasarInfo(char *type, int *key) {
  printf("Would you like to choose left or right offset?(Enter l or r): ");
  scanf(" %c", type);

  // validate offset (working with numbers hit or miss)
  while (*type != 'l' && *type != 'L' && *type != 'r' && *type != 'R') {
    printf("Invalid choice, please enter l or r: ");
    scanf(" %c", type);
  }

  printf("Enter the offset: ");

  // input offset
  scanf("%d", key);
  *key = *key % 26;
}

void vigenereEncrypt(char *message, const char *key) {
  int i = 0;
  int j = 0;
  // iterate over the message
  while (message[i] != '\0') {
    if (message[i] != ' ') {
      // encrypth ith character
      message[i] = (message[i] + (key[j] - 'A'));

      // make sure that the input stays within small alphabetss
      if (message[i] > 90) {
        message[i] -= 26;
      }
      // increment counter

      j++;
      // end of key, start over
      if (key[j] == '\0') {
        j = 0;
      }
    }
    i++;
  }
}

void vigenereDecrypt(char *message, char *key) {
  int i = 0;
  int j = 0;
  // iterate over the message
  while (message[i] != '\0') {
    if (message[i] != ' ') {
      // encrypth ith character
      message[i] = (message[i] - (key[j] - 'A'));

      // make sure that the input stays within small alphabetss
      if (message[i] < 65) {
        message[i] += 26;
      }
      // increment counter

      j++;
      // reached end of key, start over
      if (key[j] == '\0') {
        j = 0;
      }
    }
    i++;
  }
}
//convert to CAPlock
void convertToUpperCase(char *input) {
  int i = 0;

  // capital converter
  while (input[i] != '\0') {

    // if i lower 
    if (input[i] >= 97 && input[i] <= 122) {
      input[i] -= 32;
    }
    i++;
  }
}


