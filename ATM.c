#include <stdio.h>

int main() {
    char name[100];
    int withdraw, five = 0, ten = 0, twenty = 0, fifty = 0, hundred = 0;
    char repeat;

    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);

    do {
        printf("Please enter the amount you would like to withdraw: ");
        scanf("%d", &withdraw);

        if (withdraw >= 100) {
            hundred = withdraw / 100;
            withdraw %= 100;
        }
        if (withdraw >= 50) {
            fifty = withdraw / 50;
            withdraw %= 50;
        }
        if (withdraw >= 20) {
            twenty = withdraw / 20;
            withdraw %= 20;
        }
        if (withdraw >= 10) {
            ten = withdraw / 10;
            withdraw %= 10;
        }
        if (withdraw >= 5) {
            five = withdraw / 5;
            withdraw %= 5;
        }

        printf("You will receive %d $100 bill(s), %d $50 bill(s), %d $20 bill(s), %d $10 bill(s), and %d $5 bill(s).\n", hundred, fifty, twenty, ten, five);

        printf("Would you like to make another withdrawal? (y/n) ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    printf("Thank you for using our ATM. Have a good day, %s!\n", name);

    return 0;
}
