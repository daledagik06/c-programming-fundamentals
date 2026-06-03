/*
    Hands_on activty problem 1
    Prince Dale M. Sobreviñas
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
    int month;
    bool run = true;
    
  while(run) 
  {
        printf("Enter a number from 1—12 (0 to quit): ");
        scanf("%d", &month);
        
    switch (month) {
        case 0:
           while(getchar() != '\n');
           run = false;
           break;
        case 1:
            printf("January\n");
            continue;
        case 2:
            printf("february\n");
            continue;
        case 3:
            printf("March\n");
            continue;
        case 4:
            printf("April\n");
            continue;
        case 5:
            printf("May\n");
            continue;
        case 6:
            printf("June\n");
            continue;
        case 7:
            printf("July\n");
            continue;
        case 8:
            printf("August\n");
            continue;
        case 9:
            printf("September\n");
            continue;
        case 10:
            printf("October\n");
            continue;
        case 11:
            printf("November\n");
            continue;
        case 12:
            printf("December\n");
            continue;
        default:
            printf("Invalid number!\n");
            continue;
    }
  }
    
    return 0;
}













