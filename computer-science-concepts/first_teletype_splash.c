#include <stdio.h>
#include <unistd.h>

void delay(int ms) {
    usleep(ms * 1000);
}

// 14-ROW LETTER P
const char *P[] = {
    "  ######   ",
    "  ######   ",
    "  ##    ## ",
    "  ##    ## ",
    "  ##    ## ",
    "  ######   ",
    "  ######   ",
    "  ##        ",
    "  ##        ",
    "  ##        ",
    "  ##        ",
    "  ##        ",
    "  ##        ",
    "            "
};

// 14-ROW LETTER D
const char *D[] = {
    "      ######    ",
    "      #######   ",
    "      ##    ##  ",
    "      ##     ## ",
    "      ##     ## ",
    "      ##     ## ",
    "      ##     ## ",
    "     ##     ## ",
    "     ##     ## ",
    "     ##     ## ",
    "     ##     ## ",
    "     ##    ##  ",
    "     #######   ",
    "     ######    "
};

// 14-ROW LETTER S
const char *S[] = {
    "        #######  ",
    "       ########  ",
    "       ##         ",
    "       ##         ",
    "       ##         ",
    "        ######    ",
    "         #######   ",
    "              ##   ",
    "               ##  ",
    "               ##  ",
    "               ##  ",
    "       ##     ##   ",
    "        ########    ",
    "         #######    "
};

void printInitials() {

    const char **letters[] = {P, D, S};
    int letterCount = 3;

    for (int row = 0; row < 14; row++) {

        for (int i = 0; i < letterCount; i++) {
            printf("%s ", letters[i][row]);
        }

        printf("\n");
        delay(150);   // animation speed
    }
}

int main() {

    printf("\n\n");
    printf("==========================================\n\n");

    printInitials();

    printf("\n==========================================\n\n");

    printf("Press Enter to continue...");
    getchar();

    return 0;
}