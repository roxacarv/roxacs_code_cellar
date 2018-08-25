#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

typedef struct
{
	char number[5];
} Cell;

typedef struct
{
	Cell * cells;
	Cell * solvedPuzzle;
	int rows;
	int cols;
	int size;
	int posP[2];
} Table;

void cls(void);
Table * createTable(int rowSize, int colSize);
Table * fillCells(Table * table);
void freeTable(Table * table);
int randGenerator(int n);

void cls(void)
{
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, TEXT(' '),
                   dwConSize, coordScreen, &cCharsWritten);

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
                               dwConSize, coordScreen, &cCharsWritten);

    SetConsoleCursorPosition(hConsole, coordScreen);
}

Table * createTable(int rowSize, int colSize)
{
	Table * newTable = (Table*)malloc(sizeof(Table));
	newTable->cells = (Cell*)malloc((rowSize * colSize) * sizeof(Cell));
	newTable->rows = rowSize;
	newTable->cols = colSize;
	newTable->size = rowSize * colSize;
	return newTable;
}

Table * fillCells(Table * table)
{
	srand(time(NULL));
	Cell * matrix = (Cell*)malloc(table->size * sizeof(Cell));
	Cell * result = (Cell*)malloc(table->size * sizeof(Cell));
	int i, j;
	for(i = 0; i < table->size; i++)
    {
        char temp[5];
        sprintf(temp, "%d", (i+1));
        strcpy(matrix[i].number, temp);
        strcpy(result[i].number, temp);
    }

    strcpy(matrix[table->size - 1].number, "*");
    table->solvedPuzzle = result;
    int k, t, r;
	for(k = 0; k < table->rows; k++)
	{
	    for(t = 0;  t < table->cols; t++)
        {
            r = randGenerator(t);
            char temp[5];
            strcpy(temp, matrix[k * table->cols + t].number);
            strcpy(matrix[k * table->cols + t].number, matrix[k * table->cols + r].number);
            strcpy(matrix[k * table->cols + r].number, temp);
        }
	}
	int n, m;
	for(n = 0; n < table->rows; n++) {
		for(m = 0; m < table->cols; m++)
        {
            if(strcmp(matrix[n * table->cols + m].number, "*") == 0)
            {
                table->posP[0] = n;
                table->posP[1] = m;
            }
        }
	}
	table->cells = matrix;
	return table;
}

int checkResult(Table * table)
{
    int j, k, isDone;
    Cell * result = table->solvedPuzzle;
    Cell * game = table->cells;
    j = 0;
    k = 0;
    isDone = 0;
    while((j < table->size) || (k < table->size))
    {
        if(j >= (table->size-1) || k >= (table->size-1))
            break;
        if(strcmp(game[j].number, "*") == 0)
        {
            j++;
            continue;
        }
        if(strcmp(result[k].number, "*") == 0)
        {
            k++;
            continue;
        }
        if(strcmp(game[j].number, result[k].number) == 0)
        {
            isDone = 1;
            j++;
            k++;
        }
        else
        {
            isDone = 0;
            break;
        }
    }
    return isDone;
}


int randGenerator(int n)
{
	int randNumber = rand() % (n + 1);
	return randNumber;
}

void freeTable(Table * table)
{
	free(table);
}

void printTable(Table * table)
{
	int i, j;
	cls();
	for(i = 0; i < table->rows; i++) {
		for(j = 0; j < table->cols; j++)
			printf("%s ", table->cells[i * table->cols + j].number);
		printf("\n");
	}
	printf("\n");
}

void printLine(Table * table)
{
    int i;
    for(i = 0; i < table->size; i++)
        printf("%s ", table->cells[i].number);
}


void Game(Table * table)
{
    int isGaming = 1;
    int col = table->cols;
    int xN = table->posP[0];
    int xM = table->posP[1];
    while(isGaming == 1)
    {
        getch();
        int keyPressed = getch();

        if(keyPressed == 72)
        {
            //go up
            int oldIndex = xN * col + xM;
            int newIndex = ((xN - 1) * col) + xM;
            if(xN > 0)
            {
                char temp[5];
                strcpy(temp, table->cells[oldIndex].number);
                strcpy(table->cells[oldIndex].number, table->cells[newIndex].number);
                strcpy(table->cells[newIndex].number, temp);
                xN--;
                printTable(table);
            }
            else
            {
                printf("Movimento nao permitido!");
            }
        }

        if(keyPressed == 80)
        {
            //down
            int oldIndex = xN * col + xM;
            int newIndex = ((xN + 1) * col) + xM;
            if(xN < (table->rows-1))
            {
                char temp[5];
                strcpy(temp, table->cells[oldIndex].number);
                strcpy(table->cells[oldIndex].number, table->cells[newIndex].number);
                strcpy(table->cells[newIndex].number, temp);
                xN++;
                printTable(table);
            }
            else
            {
                printf("Movimento nao permitido!");
            }
        }

        if(keyPressed == 75)
        {
            //left
            int oldIndex = xN * col + xM;
            int newIndex = xN * col + (xM - 1);
            if(xM > 0)
            {
                char temp[5];
                strcpy(temp, table->cells[oldIndex].number);
                strcpy(table->cells[oldIndex].number, table->cells[newIndex].number);
                strcpy(table->cells[newIndex].number, temp);
                xM--;
                printTable(table);
            }
            else
            {
                printf("Movimento nao permitido!");
            }
        }

        if(keyPressed == 77)
        {
            //right
            int oldIndex = xN * col + xM;
            int newIndex = xN * col + (xM + 1);
            if(xM < (table->cols-1))
            {
                char temp[5];
                strcpy(temp, table->cells[oldIndex].number);
                strcpy(table->cells[oldIndex].number, table->cells[newIndex].number);
                strcpy(table->cells[newIndex].number, temp);
                xM++;
                printTable(table);
            }
            else
            {
                printf("Movimento nao permitido!");
            }
        }

        int r = checkResult(table);
        if(r == 1)
        {
            printf("Jogo terminado!");
            break;
        }

        if(keyPressed == 27)
        {
            break;
        }
    }
}

int main()
{
	Table * table = createTable(3, 2);
	table = fillCells(table);
    printTable(table);
    Game(table);
	freeTable(table);
	return 0;
}
