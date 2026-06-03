/*
    Assignment #1.4
    Created by: Prince Dale Sobreviñas
    Fundamentals of Programming
    Class #470, CC 1101
    Created on: Oct. 21, 2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 0;

    system("cls");

    printf("Input an integer: ");
    scanf("%d", &num);

    if (num < 0 || num > 80)
        printf("Error: Number out of range.\n");
    else if (num <= 20)
        printf("Range [0, 20]\n");
    else if (num <= 40)
        printf("Range [21, 40]\n");
    else if (num <= 60)
        printf("Range [41, 60]\n");
    else
        printf("Range [61, 80]\n");

    return 0;
}