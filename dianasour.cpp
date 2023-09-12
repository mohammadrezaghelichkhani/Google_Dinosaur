#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
using namespace std;
char BOARD[10][1000000];
int x = 9, y = 0, counter = 0;
void PrintBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = y; j < y + 20; j++)
        {
            cout << BOARD[i][j];
        }
        cout << endl;
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 100000; j++)
        {
            BOARD[i][j] = ' ';
        }
    }
    char forHandlingKbhit;
    int obstacleHeight;
    int curObstacle = y;
    BOARD[x][y] = '*';
    PrintBoard();
    srand(time(NULL));
    while (true)
    {
        usleep(100000);
        curObstacle += rand() % 10 + 10;
        obstacleHeight = rand() % 3 + 1;
        for (int i = 9; i > 9 - obstacleHeight; i--)
        {
            BOARD[i][curObstacle] = '#';
            system("CLS");
            PrintBoard();
        }
        BOARD[x][y] = ' ';
        y++;
        if (BOARD[x][y] == '#')
        {
            return 0;
        }
        if (kbhit())
        {
            forHandlingKbhit = getch();
            while (counter != 5)
            {
                BOARD[x][y] = ' ';
                x--;
                if (BOARD[x][y] == '#')
                {
                    return 0;
                }
                counter++;
                y++;
                if (BOARD[x][y] == '#')
                {
                    return 0;
                }
                BOARD[x][y] = '*';
                usleep(100000);
                system("CLS");
                PrintBoard();
            }
            while (counter--)
            {
                BOARD[x][y] = ' ';
                x++;
                if (BOARD[x][y] == '#')
                {
                    return 0;
                }
                y++;
                if (BOARD[x][y] == '#')
                {
                    return 0;
                }
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