#include <stdio.h>

int main() {
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

    int a = 22;
    int b = 13;

    printf("13 + 22 = %d\n", a + b);
    printf("22 - 13 = %d\n", a - b);
    printf("22 * 13 = %d\n", a * b);
    printf("22 / 13 = %f\n", (float)a / b);
    printf("22 %% 13 = %d\n", a % b);

    return 0;
}