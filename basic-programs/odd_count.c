/*
    Assignment #1.5
    Created by: Prince Dale Sobreviñas
    Fundamentals of Programming
    Class #470, CC 1101
    Created on: Oct. 21, 2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 0;
    int sum = 0;
    int i;

    system("cls");

    for (i = 1; i <= 5; i++) {
        printf("Input number %d: ", i);
        scanf("%d", &num);

        if (num % 2 != 0) {
            sum = sum + num;
        }
    }

    printf("Sum of all odd numbers: %d\n", sum);

    return 0;
}