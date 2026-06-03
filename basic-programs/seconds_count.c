/*
    Assignment #1.3
    Created by: Prince Dale Sobreviñas
    Fundamentals of Programming
    Class #470, CC 1101
    Created on: Oct. 21, 2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int s, h, m;

    s = 0;
    h = 0;
    m = 0;

    system("cls");

    printf("Input seconds: ");
    scanf("%d", &s);

    h = s / 3600;
    s = s % 3600;
    m = s / 60;
    s = s % 60;

    printf("There are:\\n");
    printf("H:M:S - %d:%d:%d\\n", h, m, s);

    return 0;
}