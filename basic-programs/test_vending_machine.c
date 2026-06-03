#include <stdio.h>

int main() 
{
    int total = 0;    
    int coins = 0;
    int price = 0;      
    int drink = 0;
    int addons = 0;

// Ask User To Enter Coins in The Vending Machine, The Vending Machine Only Accepts 5, 10, 25 Coins
    while (1) {
        printf("Enter coins (5/10/25). Enter 0 when done: ");
        scanf("%d", &coins);

        if (coins == 0) break;

        if (coins == 5 || coins == 10 || coins == 25) {
            total += coins;
        } else {
            printf("Invalid coin! Try again.\n");
        }
    }

    printf("Total Amount inserted: $%.2f\n", total / 100.0);

    printf("\nDrink Menu:\n");
    printf("1. Coffee ($0.25)\n");
    printf("2. Tea ($0.25)\n");
    printf("Enter choice: ");
    scanf("%d", &drink);

    while (drink != 1 && drink != 2) {
        printf("Invalid input! Please enter 1 or 2.\n");
        printf("Enter choice: ");
        scanf("%d", &drink);
    }

    price += 25;

    printf("\nAdd-ons Menu:\n");
    printf("1. Cream (+$0.05)\n");
    printf("2. Sugar (+$0.05)\n");
    printf("3. Extra Sugar (+$0.05)\n");
    printf("0. Done\n");

    while (1) {
        printf("Enter add-on: ");
        scanf("%d", &addons);

        if (addons == 0) {
            printf("Done adding add-ons.\n");
            break;
        }
        else if (addons == 1) {
            printf("Cream added.\n");
            price += 5;
        }
        else if (addons == 2) {
            printf("Sugar added.\n");
            price += 5;
        }
        else if (addons == 3) {
            printf("Extra sugar added.\n");
            price += 5;
        }
        else {
            printf("Invalid option! Please enter 0–3.\n");
        }
    }

    while (total < price) {
        printf("\nInsufficient funds! You need $%.2f more.\n", (price - total) / 100.0);

        printf("Enter coins (5/10/25): ");
        scanf("%d", &coins);

        if (coins == 5 || coins == 10 || coins == 25) {
            total += coins;
        } else {
            printf("Invalid coin!\n");
        }
    }
    
    int change = total - price;
    printf("\nDispensing your drink...\n");
    printf("Your change is: $%.2f\n", change / 100.0);

    return 0;
}