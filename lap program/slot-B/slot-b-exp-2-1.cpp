#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char source[200], destination[200];
    char c;

    printf("Enter the filename to open for reading\n");
    scanf("%199s", source);

    fptr1 = fopen(source, "r");

    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", source);
        return 1;
    }

    printf("Enter the filename to open for writing\n");
    scanf("%199s", destination);

    fptr2 = fopen(destination, "w");

    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", destination);
        fclose(fptr1);
        return 1;
    }

    while ((c = fgetc(fptr1)) != EOF)
    {
        fputc(c, fptr2);
    }

    printf("\nContents copied to %s\n", destination);

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}
