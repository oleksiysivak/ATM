#include <stdio.h>

int main() {

    int num;

    printf ("Please enter your number: ");
    scanf ("%d", &num);
    for (int i = 1; i <= num; i++){
    
    if (i % 15 == 0) {
            printf ("FIZZBUZZ\n");}

    else if (i % 5 == 0) {
            printf ("BUZZ\n");} 
    
    else if (i % 3 == 0) {
            printf ("FIZZ\n");}

    else 
            printf ("%d\n",i);
    }
return 0;
}