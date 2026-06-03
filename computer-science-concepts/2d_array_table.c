#include <stdio.h>
#include <time.h>

#define LIME "\033[92m"
#define RESET "\033[0m"

// ---------------- DELAY FUNCTION ----------------
void delay(int ms) {
    clock_t start = clock();
    while (clock() < start + ms * (CLOCKS_PER_SEC / 1000));
}

// ---------------- HELPER: PRINT SPACES ----------------
void printSpaces(int n) {
    for (int i = 0; i < n; i++) printf(" ");
}

// ---------------- PROBLEM 3 FUNCTION ----------------
void problem3() {
    int array[5][6];
    int r, c;
    int padding = 8; // adjust for centering

    // Fill array (multiplication pattern)
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 6; c++) {
            array[r][c] = (r + 1) * (c + 1);
        }
    }

    printf("\n");

    // ===== COLUMN HEADERS =====
    printSpaces(padding + 8);
    for (c = 0; c < 6; c++) {
        printf(LIME "[Col %d] " RESET, c);
    }
    printf("\n");

    // ===== ROWS + VALUES =====
    for (r = 0; r < 5; r++) {
        printSpaces(padding);
        printf(LIME "Row[%d]  " RESET, r);

        for (c = 0; c < 6; c++) {
            printf(LIME "%6d " RESET, array[r][c]);
            delay(50);  // tiny animation effect
        }
        printf("\n");
    }

    printf("\nPress Enter to return...");
    getchar(); // wait for enter
    getchar(); // clear buffer if needed
}

// ---------------- MAIN ----------------
int main() {
    problem3();
    return 0;
}