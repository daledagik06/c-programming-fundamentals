/*
    Credits: Aldrei Helera
*/

#include <stdio.h>
#include <string.h>

#define MAX 100
#define CONSOLE_WIDTH 170

// ANSI colors
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"

#define CELL_WIDTH 6   // " %4d |"

// Center text
void centerText(const char *text) {
    int len = strlen(text);
    int padding = (CONSOLE_WIDTH - len) / 2;

    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s\n", text);
}

// Center input
void centerInput(const char *text) {
    int len = strlen(text);
    int padding = (CONSOLE_WIDTH - len) / 2;

    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s", text);
}

// Top/Bottom Border
void printBorder(int n) {
    int width = 1 + n * CELL_WIDTH;
    int padding = (CONSOLE_WIDTH - width) / 2;

    for (int i = 0; i < padding; i++) printf(" ");

    printf(CYAN "+");
    for (int i = 0; i < n; i++) {
        printf("------+");  // matches cell width
    }
    printf("\n" RESET);
}

// Array Row
void printArrayRow(int arr[], int n) {
    int width = 1 + n * CELL_WIDTH;
    int padding = (CONSOLE_WIDTH - width) / 2;

    for (int i = 0; i < padding; i++) printf(" ");

    printf(CYAN "|");
    for (int i = 0; i < n; i++) {
        printf(" %4d |", arr[i]);  // aligned numbers
    }
    printf("\n");
}

int main() {
    int arr[MAX], temp[MAX];
    int n, t;

    centerText(MAGENTA "========================================" RESET);
    centerText(MAGENTA "   ARRAY ROTATION PROGRAM (RIGHT SHIFT)" RESET);
    centerText(MAGENTA "========================================" RESET);

    // Input size
    centerInput(YELLOW "Enter number of elements: " RESET);
    scanf("%d", &n);

    printf("\n");
    centerText(YELLOW "Enter elements:" RESET);

    // Input elements
    for (int i = 0; i < n; i++) {
        char label[50];
        sprintf(label, "Element [%d]: ", i);
        centerInput(label);
        scanf("%d", &arr[i]);
    }

    printf("\n");

    // Input rotations
    centerInput(YELLOW "Enter number of rotations (T): " RESET);
    scanf("%d", &t);

    // Rotation logic (RIGHT SHIFT)
    t = t % n;
    for (int i = 0; i < n; i++) {
        temp[(i + t) % n] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("\n");
    centerText(GREEN "ROTATED ARRAY OUTPUT:" RESET);

    printBorder(n);
    printArrayRow(arr, n);
    printBorder(n);

    centerText(GREEN "Done!" RESET);

    return 0;
}