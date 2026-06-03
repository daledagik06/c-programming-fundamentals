/*
    PROGRAM DEFENCE
    Group 13
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

int main()
{
    int total = 0;
    int user = 0;
    int add_coins = 0;
    int amount = 0;
    char choice;
    bool user_insert = true, user_choice = true;
    bool valid_cream = true, valid_sugar = true, valid_extra_sugar = true;
   
    //Accept coins
    while (user_insert)
    {
        printf("Insert coin (5, 10 or 25): ");
        scanf("%d", &user);

        if (user == 0)
        {
            user_insert = false;
        }

        else if (user == 5)
        {
            total += 5;
        }

        else if (user == 10)
        {
            total += 10;
        }

        else if (user == 25)
        {
            total += 25;
        }

        else
        {
            printf("Invalid\n");
        }
    }

        printf("You inserted: %.2f\n", total/100.0);
        printf("\n");
        fflush(stdin);
        getchar();
        
        
        //Give drink choice
        printf("Choose drink:\n");
        printf("        1. Coffee\n");
        printf("        2. Tea\n");
   while(user_choice){
        printf("Enter Choice: ");
        scanf("%d", &user);

        if (user == 1)
        {
            amount = amount + 25;
            user_choice = false;
        }
        else if (user == 2)
        {
            amount = amount + 25;
            user_choice = false;
        }
        else
        {
            printf("Invalid\n");
            
        }
   }
        printf("Amount: %.2f\n", amount/100.0);
        fflush(stdin);
        getchar();
        
    //Ask extra
    while (valid_cream) {
       printf("Add cream (y/n)? ");
       scanf("%c", &choice);
       
       switch (choice){
           case 'y':
               amount += 5;
               while (getchar() != '\n');
               continue;
           case 'n':
               while (getchar() != '\n');
               valid_cream = false;
               break;
           default:
               printf("Invalid");
               continue;
       }
    }
       fflush(stdin);
       
    while (valid_sugar) {
       printf("Add sugar (y/n)? ");
       scanf("%c", &choice);
       
       switch (choice){
           case 'y':
               amount += 5;
               while (getchar() != '\n');
               continue;
           case 'n':
               while (getchar() != '\n');
               valid_sugar = false;
               break;
           default:
               printf("Invalid");
               continue;
       }
    }
    
    fflush(stdin);
    
       while (valid_extra_sugar) {
       printf("Add extra sugar (y/n)? ");
       scanf("%c", &choice);
       
       switch (choice){
           case 'y':
               amount += 5;
               while (getchar() != '\n');
               continue;
           case 'n':
               while (getchar() != '\n');
               valid_extra_sugar = false;
               break;
           default:
               printf("Invalid");
               continue;
       }
       
    }
    
        fflush(stdin);
        getchar();
       
        printf("Amount: %.2f\n", amount/100.0);
        fflush(stdin);
        getchar();
       
    //Compute values
    float balance = total - amount;

    // Display balance and check if sufficient

        // Go back to inserting coins     
        while (total < amount) {
        printf("\nInsufficient funds! You need $%.2f more.\n", (amount - total) / 100.0);

        printf("Enter coins (5/10/25): ");
        scanf("%d", &add_coins);

        if (add_coins == 5 || add_coins == 10 || add_coins == 25) {
            total += add_coins;
        } else {
            printf("Invalid coin!\n");
        }

        // After adding more coins, recalculate balance
        balance = total - amount;
        printf("\nNew total inserted: %.2f\n", total);
        printf("Final balance (change): %.2f\n", balance);
    }

    //test
    printf("\nThank you!\n");
    fflush(stdin);
    getchar();

    return 0;
}

/*

    1. Accept coins from user.
    2. Give a choice for coffe or Tea.
    3. Then ask cream, sugar or extra sugar.
    4. Compute the values.
    5. Display balance and change if it is exact or suffient, else add more coin.

*/