/*
    Dale Sobrevinas
    Group Activity
    Problem:
    Problem 4 — Racing Game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>   

#define CARS 5
#define FINISH 40

int main() {
    char car_name[CARS] = {'A', 'B', 'C', 'D', 'E'};
    int pos[CARS] = {0, 0, 0, 0, 0};
    int finished[CARS] = {0, 0, 0, 0, 0};
    char ranking[CARS];
    
    int finish_count = 0;

    srand(time(NULL));  

    printf("WELCOME TO THE RACING GAME!\n");
    printf("Cars: A  B  C  D  E\n");
    printf("Click 'Enter'");
    getchar();

    // race loop
    while (finish_count < CARS) {

        system("cls");   
        
        for (int i = 0; i < CARS; i++) {

            if (finished[i] == 0) {
                pos[i] += rand() % 2 + 1;  

                if (pos[i] >= FINISH) {
                    pos[i] = FINISH;
                    finished[i] = 1;
                    ranking[finish_count] = car_name[i];
                    finish_count++;
                }
            }

            
            for (int space = 0; space < pos[i]; space++) {
                printf(" ");
            }
            printf("%c\n", car_name[i]);
        }

        Sleep(300);   
    }

    
    printf("\nRACE RESULTS\n");
    printf("Champion: %c\n", ranking[0]);
    printf("1st: %c\n", ranking[1]);
    printf("2nd: %c\n", ranking[2]);

    return 0;
}