#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
char BOARD[6][10000000];
int x = 5, y, counter, passedObstacles, eatenFood;
void PrintBoard()
{
    std::cout << "score: " << y + 10 * passedObstacles + 20 * eatenFood << "\n"
              << "passed destination: " << y << "  \neaten food: " << eatenFood << "  \npassed obastacles: " << passedObstacles << "\n";
    for (int i = 0; i < 6; i++)
    {
        for (int j = y; j < y + 75; j++)
        {
            std::cout << BOARD[i][j];
        }
        std::cout << "\n";
    }
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
int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10000000; j++)
        {
            BOARD[i][j] = ' ';
        }
    }
    char forHandlingKbhit;
    int obstacleHeight;
    int curObstacle = y;
    int xFood, yFood = y;
    BOARD[x][y] = '*';
    PrintBoard();
    srand(time(NULL));
    while (true)
    {
        usleep(100000);
        curObstacle += rand() % 10 + 10;
        obstacleHeight = rand() % 3 + 1;
        xFood = rand() % 6;
        yFood += 10 + rand() % 10;
        BOARD[xFood][yFood] = '^';
        for (int i = 6; i > 6 - obstacleHeight; i--)
        {
            BOARD[i][curObstacle] = '#';
        }
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
                usleep(100000);
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
                usleep(100000);
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