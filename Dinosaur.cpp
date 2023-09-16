#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
const int RED = 12; // Red color code
const int GREEN = 10; // Green color code
const int DEFAULT_COLOR = 7; // Default console color code
char BOARD[6][10000];
int x = 5, y, counter, passedObstacles, eatenFood;
void PrintBoard()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get console handle

    std::cout << "score: " << y + 10 * passedObstacles + 20 * eatenFood << "\n"
              << "passed destination: " << y << "  \neaten food: " << eatenFood << "  \npassed obstacles: " << passedObstacles << "\n";
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = y; j < y + 125; j++)
        {
            switch (BOARD[i][j])
            {
            case '^':
                SetConsoleTextAttribute(hConsole, GREEN);
                break;
            case '#':
                SetConsoleTextAttribute(hConsole, RED);
                break;
            default:
                SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
            }
            std::cout << BOARD[i][j];
        }
        std::cout << "\n";
    }
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR); // Reset console color to default
}
void updatePassedObstacles()
{
    for (int i = 5; BOARD[i][y] == '#'; i--)
    {
        passedObstacles++;
    }
}
void updateEatenFood()
{
    eatenFood += (BOARD[x][y] == '^');
}
void initialization()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            BOARD[i][j] = ' ';
        }
    }
    int obstacleHeight;
    int curObstacle = y;
    int xFood, yFood = y;
    while (yFood < 2000 && curObstacle < 2000)
    {
        curObstacle += rand() % 6 + 11;
        obstacleHeight = rand() % 3 + 1;
        xFood = rand() % 6;
        yFood += 10 + rand() % 10;
        BOARD[xFood][yFood] = '^';
        for (int i = 6; i >= 6 - obstacleHeight; i--)
        {
            BOARD[i][curObstacle] = '#';
        }
    }
    BOARD[x][y] = '*';
}
int main()
{
    initialization();
    char forHandlingKbhit;
    PrintBoard();
    srand(time(NULL));
    while (true)
    {
        usleep(100000 - 100 * y);
        BOARD[x][y] = ' ';
        y++;
        if (BOARD[x][y] == '#')
        {
            return 0;
        }
        updatePassedObstacles();
        updateEatenFood();
        if (kbhit())
        {
            forHandlingKbhit = getch();
            while (counter != 5)
            {
                BOARD[x][y] = ' ';
                x--;
                counter++;
                y++;
                if (BOARD[x][y] == '#')
                {
                    return 0;
                }
                updatePassedObstacles();
                updateEatenFood();
                BOARD[x][y] = '*';
                usleep(100000 - 100 * y);
                system("CLS");
                PrintBoard();
            }
            while (counter--)
            {
                BOARD[x][y] = ' ';
                x++;
                y++;
                if (BOARD[x][y] == '#')
                {
                    return 0;
                }
                updatePassedObstacles();
                updateEatenFood();
                BOARD[x][y] = '*';
                usleep(100000 - 100 * y);
                system("CLS");
                PrintBoard();
            }
            counter = 0;
        }
        BOARD[x][y] = '*';
        system("CLS");
        PrintBoard();
    }
}