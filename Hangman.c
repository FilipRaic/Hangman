#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ClearScreen();
void printWord (char* text);
void printHang (char** hang);

int main()
{
    char choice;
    char textBase[6][15] = {"anticipate", "programing", "example", "advice", "approach", "cater"};
    char text[15];
    char* tmpTxt;
    char** hang;
    int repeat = 1, tmpMistakes = 0, mistakes = 0;

    time_t t;
    srand(time(&t));
    int tmp = rand() % 6;

    strcpy(text, textBase[tmp]);

    hang = (int**)calloc(8+1, sizeof(int*));
    for (int i = 0; i < 10; i++)
        hang[i] = (int*)calloc(10+1, sizeof(int));

    tmpTxt = (char*)calloc(strlen(text), sizeof(char));
    printHang(hang);

    for (int i = 0; i < strlen(text); i++)
        tmpTxt[i] = '_';


    do {
        ClearScreen();
        tmpMistakes = 0;

        switch (mistakes)
        {
            case 1:
                hang[2][4] = 'O';
                break;
            case 2:
                hang[3][4] = '|';
                break;
            case 3:
                hang[3][3] = '/';
                break;
            case 4:
                hang[3][5] = '\\';
                break;
            case 5:
                hang[4][3] = '/';
                break;
            case 6:
                system("cls");
                printf("GAME OVER!");
                printWord(text);
                goto end;
        }
        printHang(hang);

        printf("\n");
        for (int i = 0; i < strlen(text); i++)
            printf("%c ", tmpTxt[i]);

        printf("\n\nEnter character: ");
        scanf(" %c", &choice);

        for (int i = 0; i < strlen(text); i++)
        {
            if (choice == text[i])
                tmpTxt[i] = choice;
            else
                tmpMistakes++;
        }

        if (tmpMistakes == strlen(text))
            mistakes++;

        else if (strstr(tmpTxt, text))
        {
            system("cls");
            printf("YOU WIN!");
            printWord(text);
            goto end;
        }

    } while (repeat);

    end:
    free(tmpTxt);
    for(int i = 0; i < 10; i++)
        free(hang[i]);
    free(hang);

    return 0;
}

void printWord (char* text)
{
    printf("\nThe word was: ");
        for (int i = 0; i < strlen(text); i++)
            printf("%c", text[i]);
}

void printHang (char** hang)
{
    printf("How to play:\nYou have to find the word that is set randomly, you can miss 6 times. After that, the game is over!\nUse only lowercase characters, good luck!\n\n");
    for (int j = 0; j < 10; j++)
        hang[7][j] = '_';

    for (int i = 1; i < 8; i++)
        hang[i][8] = '|';

    for (int j = 4; j < 8; j++)
        hang[0][j] = '_';
    hang[1][4] = '|';

    for (int i = 0; i < 8; i++, printf("\n"))
            for (int j = 0; j < 10; j++)
                printf("%c", hang[i][j]);
}

void ClearScreen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
