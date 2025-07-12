#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    char line[1000];
    printf("Enter text to write (end with ~ on a new line):\n");

    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '~')
            break;
        fputs(line, file);
    }

    printf("Data written to file.\n");
    fclose(file);
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    char line[1000];
    printf("Enter text to append (end with ~ on a new line):\n");

    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '~')
            break;
        fputs(line, file);
    }

    printf("Data appended to file.\n");
    fclose(file);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char ch;
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main() {
    char filename[100];
    int choice;

    printf("Enter filename: ");
    scanf("%s", filename);
    getchar();

    while (1) {
        printf("\nFile Handling Menu\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Append to File\n");
        printf("4. Read File\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                readFile(filename);
                break;
            case 5:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

