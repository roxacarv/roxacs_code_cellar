#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>

#define ROW 20
#define COL 20

using namespace std;

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
            cout << grid[i][j].get_pixel();
        cout << "" << endl;
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

    new_grid[3][3].set_state(1);
    new_grid[2][3].set_state(1);
    new_grid[4][3].set_state(1);

    new_grid[10][10].set_state(1);
    new_grid[9][10].set_state(1);
    new_grid[11][10].set_state(1);
    new_grid[11][12].set_state(1);
    new_grid[9][11].set_state(1);

    new_grid[18][18].set_state(1);

    set_new_neighborhood(new_grid);

    return new_grid;
}

void free_grid(Cell ** grid, size_t row)
{
    for(unsigned int i = 0; i < row; i++)
        delete[] grid[i];
    delete[] grid;
}

int main()
{
    char in;
    cin >> &in;
    Cell ** grid = create_grid(ROW, COL);
    int n = 0;
    while(n < 20)
    {
        Sleep(800);
        rules_set(grid);
        print_grid(grid, ROW, COL);
        n++;
    }
    free_grid(grid, ROW);
    char out;
    cin >> &out;
    return 0;
}
