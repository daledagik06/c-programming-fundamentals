#include <stdio.h>
#include <unistd.h>


#define LIME "\033[92m"
#define WHITE "\033[97m"
#define RESET "\033[0m"

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void delay(int ms) {
    usleep(ms * 1000);
}

// splash function
void splashScreen() {

    int pad = 22; // adjust for centering

    // PDS letters (bigger + cleaner)
    const char *P[7] = {
   " #####  ",
        " #    # ",
        " #    # ",
        " #####  ",
        " #      ",
        " #      ",
        " #      "
    };

    const char *D[7] = {
        "           #####  ",
        "           #    # ",
        "           #     #",
        "           #     #",
        "           #     #",
        "           #    # ",
        "           #####  "
    };

    const char *S[7] = {
        "             ####  ",
        "            #    # ",
        "            #      ",
        "             ####  ",
        "                 # ",
        "            #    # ",
        "             ####  "
    };

    printf("\n\n");

    // top border
    printSpaces(pad);
    printf(WHITE "=================================================\n" RESET);

    printSpaces(pad);
    printf(LIME "        G    R     O     U     P     3          \n" RESET);

    printSpaces(pad);
    printf(WHITE "=================================================\n\n" RESET);

    for (int row = 0; row < 7; row++) {
        printSpaces(pad);
        printf(LIME "%s  %s  %s\n" RESET, P[row], D[row], S[row]);
        delay(100); 
    }

    printf("\n");

    printSpaces(pad);
    printf(WHITE "=================================================\n" RESET);

    printSpaces(pad);
    printf(WHITE "        Press Enter to continue...\n" RESET);

    getchar();
}

int main() {
    splashScreen();
    return 0;
}