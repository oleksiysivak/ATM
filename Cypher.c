#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char *caesar_decode(char *message, int offset, char direction) {
  return caesar_encode(message, offset, direction == 'r' ? 'l' : 'r');
}

// Vigenère cipher implementation
char *vigenere_encode(char *message, char *key) {
  int i, j;
  int message_len = strlen(message);
  int key_len = strlen(key);
  char *encoded = malloc(message_len + 1);
  for (i = 0; i < message_len; i++) {
    encoded[i] = message[i] + key[i % key_len];
  }
  encoded[i] = '\0';
  return encoded;
}

char *vigenere_decode(char *message, char *key) {
  int i, j;
  int message_len = strlen(message);
  int key_len = strlen(key);
  char *decoded = malloc(message_len + 1);
  for (i = 0; i < message_len; i++) {
    decoded[i] = message[i] - key[i % key_len];
  }
  decoded[i] = '\0';
  return decoded;
}

// Salted Caesar cipher implementation
char *salted_caesar_encode(char *message, int offset, char direction, char *salt) {
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

char *salted_caesar_decode(char *message, int offset, char direction, char *salt) {
  int i;
  int message_len = strlen(message) - strlen(salt);
  int salt_len = strlen(salt);
  char *decoded = malloc(message_len + 1);
  for (i = 0; i < message_len; i++) {
    decoded[i] = message[i] - (direction == 'r' ? offset : -offset) - salt[i% salt_len];
  }
  strcpy(decoded + message_len, salt);
  decoded[message_len - salt_len] = '\0';
  return decoded;
}