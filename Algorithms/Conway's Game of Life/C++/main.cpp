#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>
#include <cstdio>

enum sizes { ROW = 20, COL = 20 };

void cls(void)
{
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
     GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, TEXT(' '),
                   dwConSize, coordScreen, &cCharsWritten);

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
                               dwConSize, coordScreen, &cCharsWritten);

    SetConsoleCursorPosition(hConsole, coordScreen);
}

class Cell
{
    private:
        char pixel;
        int state;
        int positionX;
        int positionY;
        int neighborsAlive;
    public:
        Cell() {}
        int get_state() { return state; }
        int get_position_x() { return positionX; }
        int get_position_y() { return positionY; }
        char get_pixel() { return pixel; }
        int get_neighbors() { return neighborsAlive; }
        void set_state(int newState)
        {
            state = newState;
            if(state == 0)
                pixel = '#';
            else
                pixel = '@';
        }
        void set_position_x(int newPositionX) { positionX = newPositionX; }
        void set_neighbors(int newNeighbors) { neighborsAlive = newNeighbors; }
        void set_position_y(int newPositionY) { positionY = newPositionY; }
};


int Randomizer(int randomLimit)
{
	int randomNumber = rand() % randomLimit;
	return randomNumber;
}

void print_grid(Cell ** grid, size_t row, size_t col)
{
    cls();
    for(unsigned int i = 0; i < row; i++) {
        for(unsigned int j = 0; j < col; j++)
            std::cout << grid[i][j].get_pixel();
        std::cout << "" << std::endl;
    }
}

int alive_neighbors(Cell ** grid, size_t i, size_t j)
{
    int neighborsAlive = 0;
    if(grid[i-1][j-1].get_state() == 1)
        neighborsAlive++;
    if(grid[i-1][j].get_state() == 1)
        neighborsAlive++;
    if(grid[i-1][j+1].get_state() == 1)
        neighborsAlive++;
    if(grid[i][j-1].get_state() == 1)
        neighborsAlive++;
    if(grid[i][j+1].get_state() == 1)
        neighborsAlive++;
    if(grid[i+1][j-1].get_state() == 1)
        neighborsAlive++;
    if(grid[i+1][j].get_state() == 1)
        neighborsAlive++;
    if(grid[i+1][j+1].get_state() == 1)
        neighborsAlive++;
    return neighborsAlive;
}

void set_new_neighborhood(Cell ** grid)
{
    for(int i = 1; i < (ROW-1); i++)
        for(int j = 1; j < (COL-1); j++)
            grid[i][j].set_neighbors(alive_neighbors(grid, i, j));
}

void rules_set(Cell ** grid)
{
    //if one or less neighbors (cell dies)
    for(int i = 1; i < (ROW-1); i++)
        for(int j = 1; j < (COL-1); j++)
        {
            int alive = grid[i][j].get_neighbors();
            //cout << alive << endl;
            if(alive < 2 && grid[i][j].get_state() == 1)
            {
              grid[i][j].set_state(0);
            }
            else if(alive > 3 && grid[i][j].get_state() == 1)
            {
                grid[i][j].set_state(0);
            }
            else if(alive == 3 && grid[i][j].get_state() == 0)
            {
                grid[i][j].set_state(1);
            }
            else if((alive >= 2 || alive <= 3) && grid[i][j].get_state() == 1)
            {
                grid[i][j].set_state(1);
            }
        }
    set_new_neighborhood(grid);
    //print_grid(grid, ROW, COL);
    //cout << "" << endl;
}

Cell ** create_grid(size_t row, size_t col)
{
    Cell ** new_grid = new Cell*[row];

    for(unsigned int alloc = 0; alloc < col; alloc++)
        new_grid[alloc] = new Cell[col];

    srand((unsigned)time(NULL));

    for(unsigned int i = 0; i < row; i++)
        for(unsigned int j = 0; j < col; j++)
        {
            new_grid[i][j].set_state(0);
        }

    set_new_neighborhood(new_grid);

    return new_grid;
}

void free_grid(Cell ** grid, size_t row)
{
    for(unsigned int i = 0; i < row; i++)
        delete[] grid[i];
    delete[] grid;
}

int basic_interface(Cell ** grid)
{
    int generations;
    std::cout << "How many cells do you want to add: ";
    int h;
    scanf("%d", &h);
    int k = 0;
    while(k < h)
    {
        std::cout << "Input the row and column you want to position your cell: ";
        int X, Y;
        scanf("%d %d", &X, &Y);
        grid[X][Y].set_state(1);
        k++;
    }
    set_new_neighborhood(grid);
    std::cout << "How many generation do you wish to see evolving: ";
    scanf("%d", &generations);
    return generations;
}

int main()
{
    Cell ** grid = create_grid(ROW, COL);
    int generations = basic_interface(grid);
    int n = 0;
    while(n < generations)
    {
        Sleep(1000);
        rules_set(grid);
        print_grid(grid, ROW, COL);
        n++;
    }
    free_grid(grid, ROW);
    char out;
    std::cout << "Press enter to leave the program.";
    std::cin >> &out;
    return 0;
}
