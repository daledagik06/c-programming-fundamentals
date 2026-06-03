/*
    Assignment #1.2
    Created by: Prince Dale Sobreviñas
    Fundamentals of Programming
    Class #470, CC 1101
    Created on: Oct. 21, 2025
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int amount;
    int thousand, five_hundred, two_hundred, hundred, fifty, twenty, ten, five, one;

    amount = 0;
    thousand = five_hundred = two_hundred = hundred = fifty = twenty = ten = five = one = 0;

    system("cls");

    printf("Input the amount: ");
    scanf("%d", &amount);

    thousand = amount / 1000; amount %= 1000;
    five_hundred = amount / 500; amount %= 500;
    two_hundred = amount / 200; amount %= 200;
    hundred = amount / 100; amount %= 100;
    fifty = amount / 50; amount %= 50;
    twenty = amount / 20; amount %= 20;
    ten = amount / 10; amount %= 10;
    five = amount / 5; amount %= 5;
    one = amount;

    printf("There are:\n");
    printf("%d pcs of 1000.00 bills\n", thousand);
    printf("%d pcs of 500.00 bills\n", five_hundred);
    printf("%d pcs of 200.00 bills\n", two_hundred);
    printf("%d pcs of 100.00 bills\n", hundred);
    printf("%d pcs of 50.00 bills\n", fifty);
    printf("%d pcs of 20.00 bills\n", twenty);
    printf("%d pcs of 10.00 coins\n", ten);
    printf("%d pcs of 5.00 coins\n", five);
    printf("%d pcs of 1.00 coins\n", one);

    return 0;
}