/*
    Assignment #1.1
    Created by: Prince Dale Sobreviñas
    Fundamentals of Programming
    Class #470, CC 1101
    Created on: Oct. 21, 2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int d, y, w;

    d = 0;
    y = 0;
    w = 0;

    printf("Enter number of days: ");
    scanf("%d", &d);

    y = d / 365;
    d = d % 365;
    w = d / 7;
    d = d % 7;

    printf("Years: %d\n", y);
    printf("Weeks: %d\n", w);
    printf("Days: %d\n", d);
    

    return 0;
}
