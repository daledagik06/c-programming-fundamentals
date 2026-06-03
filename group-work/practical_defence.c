#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>   // for Sleep()

#define BLUE  "\033[34m"
#define RESET "\033[0m"

#define SCREEN_W 100
#define BOX_W 36
#define BOX_H 11

// ===== MENU FUNCTIONS =====
int centerX(int w){
    return (SCREEN_W - w) / 2;
}

void clearScreen(){
    system("cls");   /* use "clear" on Linux */
}

void printCenteredLine(int y, int x, const char *text){
    int len = 0, i;
    while(text[len]) len++;

    printf("\033[%d;%dH#", y, x);

    int space = (BOX_W - 2 - len) / 2;
    for(i=0;i<space;i++) printf(" ");
    printf("%s", text);
    for(i=0;i<BOX_W - 2 - space - len;i++) printf(" ");

    printf("#");
}

void drawMenu(){
    int x = centerX(BOX_W);
    int y = 4;
    int i;

    clearScreen();
    printf(BLUE);

    printf("\033[%d;%dH", y, x);
    for(i=0;i<BOX_W;i++) printf("#");

    printCenteredLine(y+1, x, "");
    printCenteredLine(y+2, x, "MAIN MENU");
    printCenteredLine(y+3, x, "");

    printCenteredLine(y+4, x, "1. Teletype");
    printCenteredLine(y+5, x, "2. Guessing Game");
    printCenteredLine(y+6, x, "3. Number Tricks");
    printCenteredLine(y+7, x, "4. Racing Game");

    printCenteredLine(y+8, x, "");
    printCenteredLine(y+9, x, "0. Exit");

    printf("\033[%d;%dH", y+10, x);
    for(i=0;i<BOX_W;i++) printf("#");

    printf(RESET);

    printf("\033[%d;%dH", y+13, centerX(22));
    printf(BLUE "Enter your choice: " RESET);
}

// ===== SPLASH FUNCTIONS =====
void delay(int ms) {
    usleep(ms * 1000);
}

const char *G[] = {
    "  ####  ",
    " #    # ",
    " #      ",
    " #  ### ",
    " #    # ",
    "  ####  "
};

const char *R[] = {
    " #####  ",
    " #    # ",
    " #####  ",
    " #   #  ",
    " #    # ",
    " #     #"
};

const char *O[] = {
    "  ###  ",
    " #   # ",
    " #   # ",
    " #   # ",
    " #   # ",
    "  ###  "
};

const char *U[] = {
    " #    # ",
    " #    # ",
    " #    # ",
    " #    # ",
    " #    # ",
    "  ####  "
};

const char *P[] = {
    " ##### ",
    " #    #",
    " ##### ",
    " #     ",
    " #     ",
    " #     "
};

const char *THREE[] = {
    "  ###  ",
    "     # ",
    "  ##   ",
    "     # ",
    "  ###  ",
    "       "
};

void printBoxCentered(const char *text, int padding, int boxWidth) {
    int len = 0;
    while (text[len]) len++;

    int space = (boxWidth - 2 - len) / 2;

    for (int i = 0; i < padding; i++) printf(" ");
    printf("#");

    for (int i = 0; i < space; i++) printf(" ");
    printf("%s", text);
    for (int i = 0; i < boxWidth - 2 - space - len; i++) printf(" ");

    printf("#\n");
}

void printGroup3(int padding, int boxWidth) {
    const char **letters[] = {G, R, O, U, P, THREE};
    int letterCount = 6;

    int totalLen = 0;
    for (int i = 0; i < letterCount; i++) {
        int len = 0;
        while (letters[i][0][len]) len++;
        totalLen += len;
    }
    totalLen += (letterCount - 1);

    int sideSpace = (boxWidth - 2 - totalLen) / 2;

    for (int row = 0; row < 6; row++) {
        for (int i = 0; i < padding; i++) printf(" ");
        printf("#");

        for (int i = 0; i < sideSpace; i++) printf(" ");

        printf(BLUE);
        for (int i = 0; i < letterCount; i++) {
            printf("%s", letters[i][row]);
            if (i < letterCount - 1) printf(" ");
        }
        printf(RESET);

        for (int i = 0; i < boxWidth - 2 - sideSpace - totalLen; i++) printf(" ");
        printf("#\n");

        delay(150);
    }
}

void splashScreen() {
    int consoleWidth = 120;
    int boxWidth = 80;
    int padding = (consoleWidth - boxWidth) / 2;

    system("cls");

    for (int i = 0; i < padding; i++) printf(" ");
    for (int i = 0; i < boxWidth; i++) printf("#");
    printf("\n");

    printBoxCentered("", padding, boxWidth);
    printBoxCentered("WELCOME TO OUR SYSTEM", padding, boxWidth);
    printBoxCentered("Course: Programming 2", padding, boxWidth);
    printBoxCentered("", padding, boxWidth);

    printGroup3(padding, boxWidth);

    printBoxCentered("", padding, boxWidth);

    for (int i = 0; i < padding; i++) printf(" ");
    for (int i = 0; i < boxWidth; i++) printf("#");
    printf("\n\n");

    printf("Press Enter to continue...");
    getchar();
}

// ===== GUESSING GAME FUNCTION =====
void guessingGame() {
    int secretNumber, userGuess = 0, attempts = 0, score = 0;
    const int maxTries = 10;

    srand((unsigned int)time(NULL));
    secretNumber = rand() % 100 + 1; // 1-100

    system("cls");
    printf("==========================================\n");
    printf("      WELCOME TO THE GUESSING GAME        \n");
    printf("   I'm thinking of a number (1-100)       \n");
    printf("   You have 10 tries to get it right!     \n");
    printf("==========================================\n");

    while (attempts < maxTries) {
        printf("\nAttempt %d/%d: Enter your guess: ", attempts + 1, maxTries);
        scanf("%d", &userGuess);
        attempts++;

        if (userGuess == secretNumber) {
            score = 110 - (attempts * 10);
            printf("\nCONGRATULATIONS! You found it in %d tries.\n", attempts);
            printf("YOUR SCORE: %d points!\n", score);
            break;
        } else if (userGuess < secretNumber) {
            printf("Too LOW! Try again.\n");
        } else {
            printf("Too HIGH! Try again.\n");
        }

        if (attempts == maxTries) {
            printf("\nGAME OVER! You've run out of tries.\n");
            printf("The number was: %d\n", secretNumber);
            printf("YOUR SCORE: 0 points.\n");
        }
    }

    printf("\nPress Enter to return to menu...");
    getchar(); // clear leftover newline from scanf
    getchar(); // wait for Enter
}

// ===== NUMBER TRICK FUNCTION =====
void numberTrick() {
    int original, current;
    int i, choice, randNum;

    srand(time(NULL));

    system("cls");
    printf("NUMBER TRICK PROGRAM\n");
    printf("====================\n\n");

    printf("Think of any number.\n");
    printf("Enter your number here: ");
    scanf("%d", &original);

    current = original;

    /* ----- STATIC OPERATIONS ----- */
    current = current * 2;
    printf("\nStep 1: Double your number ? %d\n", current);

    current = current + 10;
    printf("Step 2: Add 10 ? %d\n", current);

    current = current / 2;
    printf("Step 3: Divide by 2 ? %d\n", current);

    current = current - original;
    printf("Step 4: Subtract original number ? %d\n", current);

    /* ----- DYNAMIC RANDOM OPERATIONS ----- */
    printf("\nNow for the random operations...\n\n");

    for (i = 1; i <= 5; i++) {
        choice = rand() % 5;
        randNum = rand() % 9 + 2;

        printf("Random Step %d: ", i);

        switch (choice) {
            case 0:
                printf("Add %d\n", randNum);
                current += randNum;
                break;

            case 1:
                printf("Subtract %d\n", randNum);
                current -= randNum;
                break;

            case 2:
                printf("Multiply by %d\n", randNum);
                current *= randNum;
                break;

            case 3:
                printf("Divide by %d\n", randNum);
                if (randNum != 0)
                    current /= randNum;
                break;

            case 4:
                printf("Add 5\n");
                current += 5;
                break;
        }

        printf("Current value: %d\n\n", current);
    }

    /* ----- FINAL RESULT ----- */
    printf("FINAL RESULT\n");
    printf("============\n");
    printf("The result of the entire operation is: %d\n", current);
    printf("Did it flip your mind? ??\n");

    printf("\nPress Enter to return to menu...");
    getchar(); // clear leftover newline from scanf
    getchar(); // wait for Enter
}

// ===== RACING GAME FUNCTION =====
void racingGame() {
    const int CARS = 5;
    const int FINISH = 50;

    char car_name[CARS] = {'A', 'B', 'C', 'D', 'E'};
    int pos[CARS] = {0, 0, 0, 0, 0};
    int finished[CARS] = {0, 0, 0, 0, 0};
    char ranking[CARS];
    int finish_count = 0;

    srand(time(NULL));

    system("cls");
    printf("WELCOME TO THE RACING GAME!\n");
    printf("Cars: A  B  C  D  E\n");
    printf("Press Enter to start...");
    getchar();

    // race loop
    while (finish_count < CARS) {
        system("cls");

        for (int i = 0; i < CARS; i++) {
            if (finished[i] == 0) {
                pos[i] += rand() % 2 + 1;  // move 1-2 spaces randomly
                if (pos[i] >= FINISH) {
                    pos[i] = FINISH;
                    finished[i] = 1;
                    ranking[finish_count] = car_name[i];
                    finish_count++;
                }
            }

            for (int space = 0; space < pos[i]; space++) printf(" ");
            printf("%c\n", car_name[i]);
        }

        Sleep(300);
    }

    printf("\nRACE RESULTS\n");
    printf("Champion: %c\n", ranking[0]);
    printf("1st: %c\n", ranking[1]);
    printf("2nd: %c\n", ranking[2]);

    printf("\nPress Enter to return to menu...");
    getchar();
}

// ===== MAIN =====
int main(){
    int choice;

    splashScreen(); // FIRST SPLASH

    while(1){
        drawMenu();
        scanf("%d", &choice);
        getchar(); // clear newline

        if(choice == 0)
            break;

        if(choice == 1){
            splashScreen(); // SPLASH AGAIN
            continue;
        }
        else if(choice == 2){
            guessingGame(); // GUESSING GAME
            continue;
        }
        else if(choice == 3){
            numberTrick(); // NUMBER TRICK
            continue;
        }
        else if(choice == 4){
            racingGame(); // RACING GAME
            continue;
        }

        clearScreen();
        printf(BLUE "\n\n\tYou selected option %d\n" RESET, choice);
        printf("\n\tPress Enter to continue...");
        getchar();
    }

    clearScreen();
    return 0;
}
