#include "graphics.h"
#include <iostream>
#include <math.h>
#include <stdlib.h> // Provides exit
#include <ctype.h>
int main()
{
    initwindow(400, 400, "New window");
    circle(200, 200, 50);
    getch();
    closegraph();
    return 0;
}