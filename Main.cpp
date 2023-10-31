#include "graphics.h"
#include <iostream>
using namespace std;

int main()
{
    int Win_width = 511;
    int Wheigth = 511;
    std::string Title = "New Window";

    initwindow(Win_width, Wheigth, Title.c_str()); // Инициализация окна Ширина, Высота

    char matrix[][10] = {
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'S', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'E', 'X'},
    };


    int rectWidth = 50;
    getch();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            
            if (matrix[i][j] == 'O') {

                setfillstyle(SOLID_FILL, WHITE);
                bar(j * rectWidth, i * rectWidth, (j + 1) * rectWidth, (i + 1) * rectWidth);
            }
            if (matrix[i][j] == 'X') {
                setfillstyle(SOLID_FILL, BLACK);
                bar(j * rectWidth, i * rectWidth, (j + 1) * rectWidth, (i + 1) * rectWidth);
            }
            if (matrix[i][j] == 'E') {

                setfillstyle(SOLID_FILL, GREEN);
                bar(j * rectWidth, i * rectWidth, (j + 1) * rectWidth, (i + 1) * rectWidth);
            }
            if (matrix[i][j] == 'S') {

                setfillstyle(SOLID_FILL, YELLOW);
                bar(j * rectWidth, i * rectWidth, (j + 1) * rectWidth, (i + 1) * rectWidth);
            }
            delay(20);
        }
    }

    getch(); // Ожидание нажатия на клавишу
    closegraph(); // Очистить экран
    return 0;
}
