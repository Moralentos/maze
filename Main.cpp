﻿#include "graphics.h"
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
    {'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'P', 'X'},
    {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
    };

    char side[] = { 'T', 'R', 'B', 'L' };
    //       /\    >    \/   <
    char playerSide = side[2];


    int rectWidth = 50;
    int playerPosY = 0;
    int playerPosX = 0;

    boolean firstRender = false;
    boolean isEscaped = false;

    // ДОБАВИТЬ ПРОВЕРКУ НИЗ. НЕТ ПОВОРОТА НАПРАВО 



    getch();

    while (isEscaped == false) {
        delay(330);
        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j <= 10; j++) {

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
                if (matrix[i][j] == 'P') {
                    playerPosY = i;
                    playerPosX = j;
                    setfillstyle(SOLID_FILL, RED);
                    bar(j * rectWidth, i * rectWidth, (j + 1) * rectWidth, (i + 1) * rectWidth);
                }
                if (firstRender == false) {
                    delay(20);

                }
            }
        }
        firstRender = true;
        delay(1000);



        printf("POS Y:%d X:%d\n", playerPosY, playerPosX);
        printf("BUKVA %c \n", matrix[playerPosY][playerPosX]);
        printf("SIDE --> %c\n", playerSide);
        

        const char SIDE_0 = 'T';
        const char SIDE_1 = 'R';
        const char SIDE_2 = 'B';
        const char SIDE_3 = 'L';


        switch (playerSide) {
        case SIDE_2:
            if (matrix[playerPosY][playerPosX - 1] == 'O') {
                setfillstyle(SOLID_FILL, GREEN);
                bar((playerPosX - 1) * rectWidth, (playerPosY + 1) * rectWidth, playerPosX * rectWidth, playerPosY * rectWidth);
                matrix[playerPosY][playerPosX] = 'O';
                matrix[playerPosY][playerPosX - 1] = 'P';
                playerSide = side[1];
            }
            if (matrix[playerPosY][playerPosX - 1] == 'X') {
                setfillstyle(SOLID_FILL, GREEN);
                bar((playerPosX - 1) * rectWidth, (playerPosY + 1) * rectWidth, playerPosX * rectWidth, playerPosY * rectWidth);
                if (matrix[playerPosY + 1][playerPosX] == 'O') {
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar(playerPosX * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY + 2) * rectWidth);
                    matrix[playerPosY][playerPosX] = 'O';
                    matrix[playerPosY + 1][playerPosX] = 'P';
                }
                else {
                    playerSide = side[3];
                }
            }
            break;

        case SIDE_3:
            if (matrix[playerPosY + 1][playerPosX] == 'O') {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(playerPosX * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY + 2) * rectWidth);
                playerSide = side[2];
                matrix[playerPosY][playerPosX] = 'O';
                matrix[playerPosY + 1][playerPosX] = 'P';
            }
            if (matrix[playerPosY + 1][playerPosX] == 'X') {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(playerPosX * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY + 2) * rectWidth);
                if (matrix[playerPosY][playerPosX + 1] == 'O') {
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar((playerPosX + 2) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, playerPosY * rectWidth);
                    matrix[playerPosY][playerPosX] = 'O';
                    matrix[playerPosY][playerPosX + 1] = 'P';
                }
                else {
                    playerSide = side[0];
                }
            }
            break;

        case SIDE_1:
            if (matrix[playerPosY - 1][playerPosX] == 'O') {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(playerPosX * rectWidth, (playerPosY - 1) * rectWidth, (playerPosX + 1) * rectWidth, playerPosY * rectWidth);
                playerSide = side[0];
                matrix[playerPosY][playerPosX] = 'O';
                matrix[playerPosY - 1][playerPosX] = 'P';
            }
            if (matrix[playerPosY - 1][playerPosX] == 'X') {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(playerPosX * rectWidth, (playerPosY - 1) * rectWidth, (playerPosX + 1) * rectWidth, playerPosY * rectWidth);
                if (matrix[playerPosY][playerPosX - 1] == 'O') {
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar((playerPosX + 2) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, playerPosY * rectWidth);
                    matrix[playerPosY][playerPosX] = 'O';
                    matrix[playerPosY][playerPosX - 1] = 'P';
                }
                else {
                    playerSide = side[2];
                }
            }
            break;

        case SIDE_0:
            if (matrix[playerPosY][playerPosX + 1] == 'O') {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar((playerPosX + 2) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, playerPosY * rectWidth);
                playerSide = side[3];
                matrix[playerPosY][playerPosX] = 'O';
                matrix[playerPosY][playerPosX + 1] = 'P';
            }
            if (matrix[playerPosY][playerPosX + 1] == 'X') {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(playerPosX * rectWidth, (playerPosY - 1) * rectWidth, (playerPosX + 1) * rectWidth, playerPosY * rectWidth);
                if (matrix[playerPosY - 1][playerPosX] == 'O') {
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar((playerPosX + 2) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, playerPosY * rectWidth);
                    matrix[playerPosY][playerPosX] = 'O';
                    matrix[playerPosY - 1][playerPosX] = 'P';
                }
                else {
                    playerSide = side[1];
                }
            }
            break;
        }


        // ИДЕТ НАВЕРХ
       //  if (playerSide == side[0]) {
     //        if (matrix[playerPosY][playerPosX + 1] == 'O') { // Проверка стены правой рукой
      // //           setfillstyle(SOLID_FILL, GREEN);
       //          bar((playerPosX + 2) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY)*rectWidth);
     //            if (matrix[playerPosY - 1][playerPosX] == 'O') {// Проверка стены впереди
      //               setfillstyle(SOLID_FILL, LIGHTGRAY);
       //              bar(playerPosX * rectWidth, (playerPosY - 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY)*rectWidth);
       //              matrix[playerPosY][playerPosX] = 'O';
       //              matrix[playerPosY - 1][playerPosX] = 'P';
       //              playerSide = side[3];
        //         }
        //         if (matrix[playerPosY - 1][playerPosX] == 'X') {// Проверка стены впереди
         //            setfillstyle(SOLID_FILL, GREEN);
        //             bar((playerPosX + 2) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY)*rectWidth);
        //             matrix[playerPosY][playerPosX] = 'O';
        //             matrix[playerPosY - 1][playerPosX] = 'P';
        //             playerSide = side[3];
         //        }


        //     }
       //      if (matrix[playerPosY][playerPosX + 1] == 'X') {
       //          setfillstyle(SOLID_FILL, LIGHTGRAY);
       //          bar(playerPosX * rectWidth, (playerPosY - 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY)*rectWidth);
       //          if (matrix[playerPosY - 1][playerPosX] == 'O') {// Проверка стены впереди
        //             if (matrix[playerPosY - 1][playerPosX] == 'O') {// Проверка стены впереди
        //                 setfillstyle(SOLID_FILL, GREEN);
        //                 bar((playerPosX + 2) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY)*rectWidth);
        //                 matrix[playerPosY][playerPosX] = 'O';
        //                 matrix[playerPosY - 1][playerPosX] = 'P';
        // 
        //             }
         //            else playerSide = side[2];
        //         }
       //          else {
            //            playerSide = side[1];

        //         }
        //     }

       //  }




        // ИДЕТ НАПРАВО
   //      if (playerSide == side[1]) {
            //        if (matrix[playerPosY - 1][playerPosX] == 'O') { // Проверка стены правой рукой
                //          setfillstyle(SOLID_FILL, LIGHTRED);
                //            bar(playerPosX* rectWidth, (playerPosY - 1)* rectWidth, (playerPosX + 1)* rectWidth, (playerPosY)*rectWidth);
                //          if (matrix[playerPosY][playerPosX - 1] == 'O') {// Проверка стены впереди
                    //             setfillstyle(SOLID_FILL, LIGHTGRAY);
                    //           bar((playerPosX - 1)* rectWidth, (playerPosY + 1)* rectWidth, (playerPosX)*rectWidth, (playerPosY)*rectWidth);
                    //           matrix[playerPosY][playerPosX] = 'O';
                    //            matrix[playerPosY ][playerPosX - 1] = 'P';
                    //             playerSide = side[0];
                    //         }
                //         if (matrix[playerPosY][playerPosX + 1] == 'X') {// Проверка стены впереди
                    //           setfillstyle(SOLID_FILL, LIGHTRED);
                    //          bar(playerPosX* rectWidth, (playerPosY - 1)* rectWidth, (playerPosX + 1)* rectWidth, (playerPosY)*rectWidth);
                    //            matrix[playerPosY][playerPosX] = 'O';
                    //            matrix[playerPosY][playerPosX - 1] = 'P';
                    //            playerSide = side[0];
                    //        }


                //       }
            //        if (matrix[playerPosY - 1][playerPosX] == 'X') {
                //            setfillstyle(SOLID_FILL, LIGHTGRAY);
                //            bar((playerPosX - 1) * rectWidth, (playerPosY + 1) * rectWidth, (playerPosX ) * rectWidth, (playerPosY)*rectWidth);
                //            if (matrix[playerPosY][playerPosX - 1] == 'O') {// Проверка стены впереди
                    //              if (matrix[playerPosY][playerPosX - 1] == 'O') {// Проверка стены впереди
                        //                 setfillstyle(SOLID_FILL, LIGHTRED);
                        //                   bar(playerPosX * rectWidth, (playerPosY - 1) * rectWidth, (playerPosX + 1) * rectWidth, (playerPosY ) * rectWidth);
                        //                   matrix[playerPosY][playerPosX] = 'O';
                        //                   matrix[playerPosY][playerPosX - 1] = 'P';

                        //           }
                    //           else playerSide = side[2];
          //       }
        //         else {
           //          playerSide = side[0];
                    // 
      //           }
                //        }
            //  }

        
        
        if (isEscaped == true) printf("VICTORY");
        // isEscaped = true;


    }

    getch(); // Ожидание нажатия на клавишу
    // Очистить экран
    return 0;
}
