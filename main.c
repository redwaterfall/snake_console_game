/**
 * @file main.c
 * @author Gunnar Rødfoss (you@domain.com)
 * @brief 
 * @version 1.0
 * @date 2023-01-20
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 *  ______   ___   __    ________   ___   ___   ______            _______    ________   ___ __ __   ______      
  /_____/\ /__/\ /__/\ /_______/\ /___/\/__/\ /_____/\           /______/\  /_______/\ /__//_//_/\ /_____/\     
  \::::_\/_\::\_\\  \ \\::: _  \ \\::.\ \\ \ \\::::_\/_          \::::__\/__\::: _  \ \\::\| \| \ \\::::_\/_    
   \:\/___/\\:. `-\  \ \\::(_)  \ \\:: \/_) \ \\:\/___/\          \:\ /____/\\::(_)  \ \\:.      \ \\:\/___/\   
    \_::._\:\\:. _    \ \\:: __  \ \\:. __  ( ( \:___\/_           \:\\_  _\/ \:: __  \ \\:.\-/\  \ \\::___\/_  
    /____\:\\. \`-\  \ \\:.\ \  \ \\: \ )  \ \ \:\____/\            \:\_\ \ \  \:.\ \  \ \\. \  \  \ \\:\____/\ 
    \_____\/ \__\/ \__\/ \__\/\__\/ \__\/\__\/  \_____\/             \_____\/   \__\/\__\/ \__\/ \__\/ \_____\/ 
                                                                                                               
 */
#include <stdio.h>
#include <stdlib.h.>
#include <unistd.h>
//#include <conio.h>
#include <time.h>
#include "filereader.h"
#include "controller.h"

#define SLEEP_TIME 300000


int direction = 1;
void DrawGrid(char grid[]){
    for(int i = 1; i < strlen(grid); i++){
            printf("%c\t",grid[i]);
            if(i % 7 == 0)
                printf("|\n");
        }
    usleep(SLEEP_TIME);
    system("cls");
}

int main(){
    char grid[49] ={' ',' ', ' ', ' ', ' ', ' ', ' ',
                    ' ',' ', ' ', ' ', ' ', ' ', ' ',
                    ' ',' ', ' ', ' ', ' ', ' ', ' ',
                    ' ',' ', ' ', ' ', ' ', ' ', ' ',
                    ' ',' ', ' ', ' ', ' ', ' ', ' ',};

    int gridCount = 0;
    int gameover = 0;
    char snakebody[49] = "x";
    int dir = 1;
    int points = 0;
    int foodPos = rand() % sizeof grid;
    clock_t clockTime = clock();
    clock_t delayTime = clockTime + 2000;

    
    filereader("./snakegame.txt");

    usleep(3000000);
    system("cls");
    gameoverlable:
                    while (gameover)
                    {
                        char input;
                        printf("GAME OVER POINTS %d\n", points);
                        printf("Play again? y/n ");
                        scanf("%c", &input);
                        printf("input %c", input);
                        if(input == 'y'){
                            points = 0;
                            gameover = 0;
                            gridCount = 0;
                            dir = 1;
                        }
                        else if(input == 'n'){
                            break;
                        }
                        else{
                            goto gameoverlable;
                        }
                    }
    
    while (!gameover)
    {
        //draw grid func
        printf("\t SNAKE GAME\t POINTS %d\n", points);
        DrawGrid(grid);
        controller(&direction);

        int oldGridCount = gridCount;
        gridCount += direction;

        if(gridCount >= sizeof grid || gridCount < 0 || gridCount + dir < 0){
            gameover = 1;
            goto gameoverlable;
            }
        
        grid[oldGridCount] = ' ';
        grid[gridCount] = 'X';
        grid[foodPos] = 'O';

        if(gridCount == foodPos){
            points++;
            foodPos =  rand() % sizeof grid;
        }
    
        
    }

    return 0;
}