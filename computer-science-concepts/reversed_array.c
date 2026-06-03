#include <stdio.h>
#include <string.h>

int main()
{
    char name[5][50];
    int i;

    for(i = 0; i < 5; i++)
{
    printf("Enter name %d: ", i + 1);
    fgets(name[i], 50, stdin);
    
    for(int j = 0; name[i][j] != '\0'; j++)
    {
        if(name[i][j] == '\n')
        {
            name[i][j] = '\0';
            break;
        }
    }
}

    printf("\nOriginal string array:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%s\n", name[i]);
    }

    printf("\nModified string array in reverse:\n");
    for(i = 4; i >= 0; i--)
    {
        printf("%s\n", name[i]);
    }

    return 0;
}